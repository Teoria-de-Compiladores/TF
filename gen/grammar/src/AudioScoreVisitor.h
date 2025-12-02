
// Generated from src/AudioScore.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "AudioScoreParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by AudioScoreParser.
 */
class  AudioScoreVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by AudioScoreParser.
   */
    virtual std::any visitProgram(AudioScoreParser::ProgramContext *context) = 0;

    virtual std::any visitTempoStmt(AudioScoreParser::TempoStmtContext *context) = 0;

    virtual std::any visitPatternDecl(AudioScoreParser::PatternDeclContext *context) = 0;

    virtual std::any visitStatement(AudioScoreParser::StatementContext *context) = 0;

    virtual std::any visitLoopStmt(AudioScoreParser::LoopStmtContext *context) = 0;

    virtual std::any visitPlayStmt(AudioScoreParser::PlayStmtContext *context) = 0;

    virtual std::any visitNoteStmt(AudioScoreParser::NoteStmtContext *context) = 0;

    virtual std::any visitRestStmt(AudioScoreParser::RestStmtContext *context) = 0;


};

