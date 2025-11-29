#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "antlr4-runtime.h"
#include "AudioScoreLexer.h"
#include "AudioScoreParser.h"

#include "AudioDriver.h"

int main(int argc, const char* argv[]) {
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0]
                  << " <input.aud> <output.ll>\n";
        return 1;
    }

    std::string inputFile  = argv[1];
    std::string outputLl   = argv[2];

    // Leer archivo de entrada
    std::ifstream stream(inputFile);
    if (!stream.is_open()) {
        std::cerr << "No se pudo abrir archivo de entrada: "
                  << inputFile << "\n";
        return 1;
    }

    antlr4::ANTLRInputStream input(stream);
    AudioScoreLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    AudioScoreParser parser(&tokens);

    antlr4::tree::ParseTree *tree = parser.program();

    try {
        AudioDriver driver(outputLl);
        driver.visit(tree);
        std::cout << "LLVM IR generado en: " << outputLl << "\n";
    } catch (const std::exception &ex) {
        std::cerr << "Error durante la generación de LLVM IR: "
                  << ex.what() << "\n";
        return 1;
    }

    return 0;
}
