
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

  virtual void enterTempoStmt(AudioScoreParser::TempoStmtContext * /*ctx*/) override { }
  virtual void exitTempoStmt(AudioScoreParser::TempoStmtContext * /*ctx*/) override { }

  virtual void enterPatternDecl(AudioScoreParser::PatternDeclContext * /*ctx*/) override { }
  virtual void exitPatternDecl(AudioScoreParser::PatternDeclContext * /*ctx*/) override { }

  virtual void enterStatement(AudioScoreParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(AudioScoreParser::StatementContext * /*ctx*/) override { }

  virtual void enterLoopStmt(AudioScoreParser::LoopStmtContext * /*ctx*/) override { }
  virtual void exitLoopStmt(AudioScoreParser::LoopStmtContext * /*ctx*/) override { }

  virtual void enterPlayStmt(AudioScoreParser::PlayStmtContext * /*ctx*/) override { }
  virtual void exitPlayStmt(AudioScoreParser::PlayStmtContext * /*ctx*/) override { }

  virtual void enterNoteStmt(AudioScoreParser::NoteStmtContext * /*ctx*/) override { }
  virtual void exitNoteStmt(AudioScoreParser::NoteStmtContext * /*ctx*/) override { }

  virtual void enterRestStmt(AudioScoreParser::RestStmtContext * /*ctx*/) override { }
  virtual void exitRestStmt(AudioScoreParser::RestStmtContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

