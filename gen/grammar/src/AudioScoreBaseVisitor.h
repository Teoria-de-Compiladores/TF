
// Generated from src/AudioScore.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "AudioScoreVisitor.h"


/**
 * This class provides an empty implementation of AudioScoreVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  AudioScoreBaseVisitor : public AudioScoreVisitor {
public:

  virtual std::any visitProgram(AudioScoreParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTempoDecl(AudioScoreParser::TempoDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(AudioScoreParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNoteStmt(AudioScoreParser::NoteStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRestStmt(AudioScoreParser::RestStmtContext *ctx) override {
    return visitChildren(ctx);
  }


};

