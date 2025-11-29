#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "antlr4-runtime.h"
#include "AudioScoreLexer.h"
#include "AudioScoreParser.h"
#include "AudioDriver.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/DynamicLibrary.h"

using namespace antlr4;
using namespace llvm;
using std::string;

// ==== declaracion de las funciones del runtime para poder mapearlas ====
// Están definidas en runtime_audio_wav.c (C puro), por eso el extern "C"
extern "C" {
    void init_wav_writer(void);
    void finalize_wav(void);
    void write_sine_note(double freqHz, int durationMs);
    void write_rest(int durationMs);
}

void runWithJIT(std::unique_ptr<Module> M) {
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();

    Module *Mraw = M.get();

    std::string errStr;
    ExecutionEngine *EE =
        EngineBuilder(std::move(M)).setErrorStr(&errStr).create();

    if (!EE) {
        errs() << "Error creando el JIT: " << errStr << "\n";
        return;
    }

    // === Vincular funciones externas del runtime al módulo JITeado ===
    if (Function *F = Mraw->getFunction("init_wav_writer")) {
        EE->addGlobalMapping(F, (void*)&init_wav_writer);
    }
    if (Function *F = Mraw->getFunction("finalize_wav")) {
        EE->addGlobalMapping(F, (void*)&finalize_wav);
    }
    if (Function *F = Mraw->getFunction("write_sine_note")) {
        EE->addGlobalMapping(F, (void*)&write_sine_note);
    }
    if (Function *F = Mraw->getFunction("write_rest")) {
        EE->addGlobalMapping(F, (void*)&write_rest);
    }

    // Ahora sí, buscar y ejecutar main()
    Function *MainFunc = EE->FindFunctionNamed("main");
    if (!MainFunc) {
        errs() << "No se encontró la función main para ejecutar con JIT\n";
        return;
    }

    std::vector<GenericValue> NoArgs;
    EE->runFunction(MainFunc, NoArgs);
}

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0]
                  << " <input.aud> [-O] [-jit]\n";
        return 1;
    }

    string inputFile = argv[1];

    bool optimize = false;
    bool useJIT   = false;

    for (int i = 2; i < argc; ++i) {
        string flag = argv[i];
        if (flag == "-O") {
            optimize = true;
        } else if (flag == "-jit") {
            useJIT = true;
        } else {
            std::cerr << "Flag desconocido: " << flag
                      << " (usa -O y/o -jit)\n";
        }
    }

    std::ifstream stream(inputFile);
    if (!stream.is_open()) {
        std::cerr << "No se pudo abrir archivo de entrada: "
                  << inputFile << "\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << stream.rdbuf();
    std::string code = buffer.str();

    ANTLRInputStream input(code);
    AudioScoreLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    AudioScoreParser parser(&tokens);

    tree::ParseTree *tree = parser.program();

    // 1) Construimos el módulo LLVM con el driver
    AudioDriver driver;
    driver.visit(tree);

    // 2) Siempre guardamos una versión "sinopt.ll" (como en Calc)
    driver.writeIR("sinopt.ll");

    // 3) Si hay -O, optimizamos y escribimos "optimized.ll"
    if (optimize) {
        std::cout << "[info] Ejecutando optimización O2...\n";
        driver.optimizeAndWrite("optimized.ll");
        std::cout << "[info] IR optimizado escrito en optimized.ll\n";
    }

    // 4) Si hay -jit, ejecutamos el módulo (optimizado o no)
    if (useJIT) {
        std::cout << "[info] Ejecutando módulo con JIT...\n";
        auto M = driver.takeModule();   // movemos el módulo al JIT
        runWithJIT(std::move(M));
        std::cout << "[info] Ejecución JIT terminada.\n";
        std::cout << "[info] Deberías ver output.wav en el directorio actual.\n";
    }

    return 0;
}
