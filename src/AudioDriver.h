#pragma once

#include <string>
#include <unordered_map>
#include <stdexcept>
#include <cmath>
#include <system_error>

#include "antlr4-runtime.h"
#include "AudioScoreBaseVisitor.h"
#include "AudioScoreParser.h"

// LLVM
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/raw_ostream.h"

class AudioDriver : public AudioScoreBaseVisitor {
public:
    explicit AudioDriver(const std::string &outputLl)
        : tempoBpm_(120),
          module_(std::make_unique<llvm::Module>("AudioScoreModule", context_)),
          builder_(std::make_unique<llvm::IRBuilder<>>(context_)),
          outputFilename_(outputLl),
          initFn_(nullptr),
          finalFn_(nullptr),
          noteFn_(nullptr),
          restFn_(nullptr),
          mainFn_(nullptr) {}

    // program: tempoDecl? statement* EOF ;
    antlrcpp::Any visitProgram(AudioScoreParser::ProgramContext *ctx) override {
        using namespace llvm;

        // 1. Declarar tipos básicos
        llvm::Type *voidTy   = builder_->getVoidTy();
        llvm::Type *doubleTy = builder_->getDoubleTy();
        llvm::Type *i32Ty    = builder_->getInt32Ty();

        // 2. Declarar funciones externas del runtime (runtime_audio_wav.c)
        FunctionType *initTy  = FunctionType::get(voidTy, false);
        FunctionType *finalTy = FunctionType::get(voidTy, false);
        FunctionType *noteTy  = FunctionType::get(voidTy, {doubleTy, i32Ty}, false);
        FunctionType *restTy  = FunctionType::get(voidTy, {i32Ty}, false);

        initFn_ = Function::Create(
            initTy, Function::ExternalLinkage, "init_wav_writer", module_.get());
        finalFn_ = Function::Create(
            finalTy, Function::ExternalLinkage, "finalize_wav", module_.get());
        noteFn_ = Function::Create(
            noteTy, Function::ExternalLinkage, "write_sine_note", module_.get());
        restFn_ = Function::Create(
            restTy, Function::ExternalLinkage, "write_rest", module_.get());

        // 3. Definir: i32 @main()
        FunctionType *mainTy = FunctionType::get(i32Ty, false);
        mainFn_ = Function::Create(
            mainTy, Function::ExternalLinkage, "main", module_.get());

        llvm::BasicBlock *entryBB =
            llvm::BasicBlock::Create(context_, "entry", mainFn_);
        builder_->SetInsertPoint(entryBB);

        // 4. init_wav_writer();
        builder_->CreateCall(initFn_);

        // 5. Visitar tempo (si existe) y statements
        if (ctx->tempoDecl()) {
            visit(ctx->tempoDecl());
        }
        for (auto *stmt : ctx->statement()) {
            visit(stmt);
        }

        // 6. finalize_wav(); return 0;
        builder_->CreateCall(finalFn_);
        builder_->CreateRet(llvm::ConstantInt::get(i32Ty, 0));

        // 7. Verificación
        if (verifyFunction(*mainFn_, &llvm::errs())) {
            llvm::errs() << "Error: función main inválida\n";
        }
        if (verifyModule(*module_, &llvm::errs())) {
            llvm::errs() << "Error: módulo LLVM inválido\n";
        }

        // 8. Volcar el IR a archivo .ll
        std::error_code EC;
        llvm::raw_fd_ostream dest(outputFilename_, EC, llvm::sys::fs::OF_Text);
        if (EC) {
            llvm::errs() << "No se pudo abrir archivo " << outputFilename_
                         << ": " << EC.message() << "\n";
        } else {
            module_->print(dest, nullptr);
        }

        return nullptr;
    }

    // tempoDecl: 'tempo' INT ';'
    antlrcpp::Any visitTempoDecl(AudioScoreParser::TempoDeclContext *ctx) override {
        int bpm = std::stoi(ctx->INT()->getText());
        tempoBpm_ = bpm;
        return nullptr;
    }

    // noteStmt: NOTE OCTAVE DUR ;
    antlrcpp::Any visitNoteStmt(AudioScoreParser::NoteStmtContext *ctx) override {
        using namespace llvm;

        std::string noteText   = ctx->NOTE()->getText();   // "C", "D#", etc.
        std::string octaveText = ctx->OCTAVE()->getText(); // "4"
        std::string durText    = ctx->DUR()->getText();    // "q", "h", "e"

        int midi = noteToMidi(noteText, octaveText);

        // MIDI -> frecuencia en Hz (A4 = 440Hz, MIDI 69)
        double semitonesFromA4 = static_cast<double>(midi - 69) / 12.0;
        double freqHz = 440.0 * std::pow(2.0, semitonesFromA4);

        int ms = durationToMs(durText, tempoBpm_);

        // Crear constantes LLVM y llamar a write_sine_note(freq, ms)
        llvm::Type *doubleTy = builder_->getDoubleTy();
        llvm::Type *i32Ty    = builder_->getInt32Ty();

        Value *freqVal = ConstantFP::get(doubleTy, freqHz);
        Value *durVal  = ConstantInt::get(i32Ty, ms);

        builder_->CreateCall(noteFn_, {freqVal, durVal});

        return nullptr;
    }

    // restStmt: 'rest' DUR ;
    antlrcpp::Any visitRestStmt(AudioScoreParser::RestStmtContext *ctx) override {
        using namespace llvm;

        std::string durText = ctx->DUR()->getText();
        int ms = durationToMs(durText, tempoBpm_);

        llvm::Type *i32Ty = builder_->getInt32Ty();
        Value *durVal = ConstantInt::get(i32Ty, ms);

        builder_->CreateCall(restFn_, {durVal});
        return nullptr;
    }

private:
    // ==== Estado del compilador ====
    int tempoBpm_;

    llvm::LLVMContext context_;
    std::unique_ptr<llvm::Module> module_;
    std::unique_ptr<llvm::IRBuilder<>> builder_;
    std::string outputFilename_;

    llvm::Function *initFn_;
    llvm::Function *finalFn_;
    llvm::Function *noteFn_;
    llvm::Function *restFn_;
    llvm::Function *mainFn_;

    // ==== Helpers musicales ====
    int noteToMidi(const std::string &note, const std::string &octaveStr) {
        static std::unordered_map<std::string, int> baseMidi = {
            {"C", 0},  {"C#", 1}, {"Db", 1},
            {"D", 2},  {"D#", 3}, {"Eb", 3},
            {"E", 4},
            {"F", 5},  {"F#", 6}, {"Gb", 6},
            {"G", 7},  {"G#", 8}, {"Ab", 8},
            {"A", 9},  {"A#",10}, {"Bb",10},
            {"B", 11}
        };

        auto it = baseMidi.find(note);
        if (it == baseMidi.end()) {
            throw std::runtime_error("Nota desconocida: " + note);
        }
        int semitone = it->second;
        int octave = std::stoi(octaveStr);
        // MIDI: C4 = 60 -> 12*(octave+1) + semitone
        int midi = 12 * (octave + 1) + semitone;
        return midi;
    }

    int durationToMs(const std::string &dur, int tempoBpm) {
        // Negra en ms
        double quarterMs = 60000.0 / tempoBpm;

        if (dur == "q") {         // negra
            return static_cast<int>(quarterMs);
        } else if (dur == "h") {  // blanca
            return static_cast<int>(2 * quarterMs);
        } else if (dur == "e") {  // corchea
            return static_cast<int>(quarterMs / 2.0);
        } else {
            throw std::runtime_error("Duración desconocida: " + dur);
        }
    }
};
