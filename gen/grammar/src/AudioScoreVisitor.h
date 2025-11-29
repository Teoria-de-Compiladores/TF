
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

    virtual std::any visitTempoDecl(AudioScoreParser::TempoDeclContext *context) = 0;

    virtual std::any visitStatement(AudioScoreParser::StatementContext *context) = 0;

    virtual std::any visitNoteStmt(AudioScoreParser::NoteStmtContext *context) = 0;

    virtual std::any visitRestStmt(AudioScoreParser::RestStmtContext *context) = 0;


};

