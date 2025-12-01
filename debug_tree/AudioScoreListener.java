// Generated from AudioScore.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link AudioScoreParser}.
 */
public interface AudioScoreListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link AudioScoreParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(AudioScoreParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link AudioScoreParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(AudioScoreParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link AudioScoreParser#tempoDecl}.
	 * @param ctx the parse tree
	 */
	void enterTempoDecl(AudioScoreParser.TempoDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link AudioScoreParser#tempoDecl}.
	 * @param ctx the parse tree
	 */
	void exitTempoDecl(AudioScoreParser.TempoDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link AudioScoreParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(AudioScoreParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link AudioScoreParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(AudioScoreParser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link AudioScoreParser#noteStmt}.
	 * @param ctx the parse tree
	 */
	void enterNoteStmt(AudioScoreParser.NoteStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link AudioScoreParser#noteStmt}.
	 * @param ctx the parse tree
	 */
	void exitNoteStmt(AudioScoreParser.NoteStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link AudioScoreParser#restStmt}.
	 * @param ctx the parse tree
	 */
	void enterRestStmt(AudioScoreParser.RestStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link AudioScoreParser#restStmt}.
	 * @param ctx the parse tree
	 */
	void exitRestStmt(AudioScoreParser.RestStmtContext ctx);
}