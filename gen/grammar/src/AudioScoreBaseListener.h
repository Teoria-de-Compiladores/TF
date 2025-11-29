
// Generated from src/AudioScore.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "AudioScoreListener.h"


/**
 * This class provides an empty implementation of AudioScoreListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  AudioScoreBaseListener : public AudioScoreListener {
public:

  virtual void enterProgram(AudioScoreParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(AudioScoreParser::ProgramContext * /*ctx*/) override { }

  virtual void enterTempoDecl(AudioScoreParser::TempoDeclContext * /*ctx*/) override { }
  virtual void exitTempoDecl(AudioScoreParser::TempoDeclContext * /*ctx*/) override { }

  virtual void enterStatement(AudioScoreParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(AudioScoreParser::StatementContext * /*ctx*/) override { }

  virtual void enterNoteStmt(AudioScoreParser::NoteStmtContext * /*ctx*/) override { }
  virtual void exitNoteStmt(AudioScoreParser::NoteStmtContext * /*ctx*/) override { }

  virtual void enterRestStmt(AudioScoreParser::RestStmtContext * /*ctx*/) override { }
  virtual void exitRestStmt(AudioScoreParser::RestStmtContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

