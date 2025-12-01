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
    //InitializeNativeTarget() y InitializeNativeTargetAsmPrinter() 
    // preparan LLVM para generar código para la propia máquina.
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

    //buscar y ejecutar main()
    //Busca la función main dentro del módulo LLVM (la que generaste en visitProgram).
    Function *MainFunc = EE->FindFunctionNamed("main");
    if (!MainFunc) {
        errs() << "No se encontró la función main para ejecutar con JIT\n";
        return;
    }

    std::vector<GenericValue> NoArgs;
    EE->runFunction(MainFunc, NoArgs);
}

std::string getBaseName(const std::string &path) {
    size_t slash = path.find_last_of("/\\");
    std::string file = (slash == std::string::npos) ? path : path.substr(slash + 1);

    size_t dot = file.find_last_of('.');
    return (dot == std::string::npos) ? file : file.substr(0, dot);
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

    //Pipeline de ANTLR
    ANTLRInputStream input(code); //envuelve el string de código
    AudioScoreLexer lexer(&input); //separa en tokens
    CommonTokenStream tokens(&lexer); //buffer de tokens
    AudioScoreParser parser(&tokens); //aplica la gramática y construye un árbol de derivación

    tree::ParseTree *tree = parser.program(); //nodo raíz del árbol (program)

    // 1) se construye el módulo LLVM con el driver
    AudioDriver driver;
    driver.visit(tree);

    std::string baseName = getBaseName(inputFile);
    std::string wavName = baseName + ".wav";

    std::string sinoptFile = baseName + "_sinopt.ll";
    std::string optFile    = baseName + "_opt.ll";

    // 2) Siempre se guardara una versión "sinopt.ll" 
    driver.writeIR(sinoptFile);
    std::cout << "[info] IR sin optimizar escrito en " << sinoptFile << "\n";

    // 3) Si hay -O, optimizamos y escribimos el optimizado
    if (optimize) {
        std::cout << "[info] Ejecutando optimización O2...\n";
        driver.optimizeAndWrite(optFile);
        std::cout << "[info] IR optimizado escrito en " << optFile << "\n";
    }

    // 4) Si hay -jit, ejecutamos el módulo (optimizado o no)
    if (useJIT) {
        setenv("AUDIO_OUTPUT_NAME", wavName.c_str(), 1);
        std::cout << "[info] Ejecutando módulo con JIT...\n";
        auto M = driver.takeModule();
        runWithJIT(std::move(M));
        std::cout << "[info] Ejecución JIT terminada.\n";
        std::cout << "[info] Deberías ver " << wavName << " en el directorio actual.\n";
    }

    return 0;
}
