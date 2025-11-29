
// Generated from src/AudioScore.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "AudioScoreParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by AudioScoreParser.
 */
class  AudioScoreListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(AudioScoreParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(AudioScoreParser::ProgramContext *ctx) = 0;

  virtual void enterTempoDecl(AudioScoreParser::TempoDeclContext *ctx) = 0;
  virtual void exitTempoDecl(AudioScoreParser::TempoDeclContext *ctx) = 0;

  virtual void enterStatement(AudioScoreParser::StatementContext *ctx) = 0;
  virtual void exitStatement(AudioScoreParser::StatementContext *ctx) = 0;

  virtual void enterNoteStmt(AudioScoreParser::NoteStmtContext *ctx) = 0;
  virtual void exitNoteStmt(AudioScoreParser::NoteStmtContext *ctx) = 0;

  virtual void enterRestStmt(AudioScoreParser::RestStmtContext *ctx) = 0;
  virtual void exitRestStmt(AudioScoreParser::RestStmtContext *ctx) = 0;


};

