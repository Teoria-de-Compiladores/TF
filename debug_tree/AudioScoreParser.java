// Generated from AudioScore.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class AudioScoreParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, NOTE=4, OCTAVE=5, DUR=6, INT=7, WS=8;
	public static final int
		RULE_program = 0, RULE_tempoDecl = 1, RULE_statement = 2, RULE_noteStmt = 3, 
		RULE_restStmt = 4;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "tempoDecl", "statement", "noteStmt", "restStmt"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'tempo'", "';'", "'rest'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, "NOTE", "OCTAVE", "DUR", "INT", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "AudioScore.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public AudioScoreParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(AudioScoreParser.EOF, 0); }
		public TempoDeclContext tempoDecl() {
			return getRuleContext(TempoDeclContext.class,0);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AudioScoreListener ) ((AudioScoreListener)listener).enterProgram(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AudioScoreListener ) ((AudioScoreListener)listener).exitProgram(this);
		}
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(11);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__0) {
				{
				setState(10);
				tempoDecl();
				}
			}

			setState(16);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__2 || _la==NOTE) {
				{
				{
				setState(13);
				statement();
				}
				}
				setState(18);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(19);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TempoDeclContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(AudioScoreParser.INT, 0); }
		public TempoDeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_tempoDecl; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AudioScoreListener ) ((AudioScoreListener)listener).enterTempoDecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AudioScoreListener ) ((AudioScoreListener)listener).exitTempoDecl(this);
		}
	}

	public final TempoDeclContext tempoDecl() throws RecognitionException {
		TempoDeclContext _localctx = new TempoDeclContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_tempoDecl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(21);
			match(T__0);
			setState(22);
			match(INT);
			setState(23);
			match(T__1);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementContext extends ParserRuleContext {
		public NoteStmtContext noteStmt() {
			return getRuleContext(NoteStmtContext.class,0);
		}
		public RestStmtContext restStmt() {
			return getRuleContext(RestStmtContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AudioScoreListener ) ((AudioScoreListener)listener).enterStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AudioScoreListener ) ((AudioScoreListener)listener).exitStatement(this);
		}
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_statement);
		try {
			setState(31);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NOTE:
				enterOuterAlt(_localctx, 1);
				{
				setState(25);
				noteStmt();
				setState(26);
				match(T__1);
				}
				break;
			case T__2:
				enterOuterAlt(_localctx, 2);
				{
				setState(28);
				restStmt();
				setState(29);
				match(T__1);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NoteStmtContext extends ParserRuleContext {
		public TerminalNode NOTE() { return getToken(AudioScoreParser.NOTE, 0); }
		public TerminalNode OCTAVE() { return getToken(AudioScoreParser.OCTAVE, 0); }
		public TerminalNode DUR() { return getToken(AudioScoreParser.DUR, 0); }
		public NoteStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_noteStmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AudioScoreListener ) ((AudioScoreListener)listener).enterNoteStmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AudioScoreListener ) ((AudioScoreListener)listener).exitNoteStmt(this);
		}
	}

	public final NoteStmtContext noteStmt() throws RecognitionException {
		NoteStmtContext _localctx = new NoteStmtContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_noteStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(33);
			match(NOTE);
			setState(34);
			match(OCTAVE);
			setState(35);
			match(DUR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RestStmtContext extends ParserRuleContext {
		public TerminalNode DUR() { return getToken(AudioScoreParser.DUR, 0); }
		public RestStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_restStmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AudioScoreListener ) ((AudioScoreListener)listener).enterRestStmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AudioScoreListener ) ((AudioScoreListener)listener).exitRestStmt(this);
		}
	}

	public final RestStmtContext restStmt() throws RecognitionException {
		RestStmtContext _localctx = new RestStmtContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_restStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(37);
			match(T__2);
			setState(38);
			match(DUR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\u0004\u0001\b)\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0001"+
		"\u0000\u0003\u0000\f\b\u0000\u0001\u0000\u0005\u0000\u000f\b\u0000\n\u0000"+
		"\f\u0000\u0012\t\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0003\u0002 \b\u0002\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0000\u0000\u0005\u0000\u0002\u0004\u0006\b\u0000\u0000&\u0000\u000b"+
		"\u0001\u0000\u0000\u0000\u0002\u0015\u0001\u0000\u0000\u0000\u0004\u001f"+
		"\u0001\u0000\u0000\u0000\u0006!\u0001\u0000\u0000\u0000\b%\u0001\u0000"+
		"\u0000\u0000\n\f\u0003\u0002\u0001\u0000\u000b\n\u0001\u0000\u0000\u0000"+
		"\u000b\f\u0001\u0000\u0000\u0000\f\u0010\u0001\u0000\u0000\u0000\r\u000f"+
		"\u0003\u0004\u0002\u0000\u000e\r\u0001\u0000\u0000\u0000\u000f\u0012\u0001"+
		"\u0000\u0000\u0000\u0010\u000e\u0001\u0000\u0000\u0000\u0010\u0011\u0001"+
		"\u0000\u0000\u0000\u0011\u0013\u0001\u0000\u0000\u0000\u0012\u0010\u0001"+
		"\u0000\u0000\u0000\u0013\u0014\u0005\u0000\u0000\u0001\u0014\u0001\u0001"+
		"\u0000\u0000\u0000\u0015\u0016\u0005\u0001\u0000\u0000\u0016\u0017\u0005"+
		"\u0007\u0000\u0000\u0017\u0018\u0005\u0002\u0000\u0000\u0018\u0003\u0001"+
		"\u0000\u0000\u0000\u0019\u001a\u0003\u0006\u0003\u0000\u001a\u001b\u0005"+
		"\u0002\u0000\u0000\u001b \u0001\u0000\u0000\u0000\u001c\u001d\u0003\b"+
		"\u0004\u0000\u001d\u001e\u0005\u0002\u0000\u0000\u001e \u0001\u0000\u0000"+
		"\u0000\u001f\u0019\u0001\u0000\u0000\u0000\u001f\u001c\u0001\u0000\u0000"+
		"\u0000 \u0005\u0001\u0000\u0000\u0000!\"\u0005\u0004\u0000\u0000\"#\u0005"+
		"\u0005\u0000\u0000#$\u0005\u0006\u0000\u0000$\u0007\u0001\u0000\u0000"+
		"\u0000%&\u0005\u0003\u0000\u0000&\'\u0005\u0006\u0000\u0000\'\t\u0001"+
		"\u0000\u0000\u0000\u0003\u000b\u0010\u001f";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}