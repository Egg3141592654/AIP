// Generated from ArduinoHostGrammar.g4 by ANTLR 4.4
package aip.lexparse;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ArduinoHostGrammarParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.4", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		SET=1, READ=2, HIGH=3, LOW=4, ANALOG=5, DIGITAL=6, ID=7, INT=8, WS=9;
	public static final String[] tokenNames = {
		"<INVALID>", "SET", "READ", "HIGH", "LOW", "'ANALOG'", "'DIGITAL'", "ID", 
		"INT", "WS"
	};
	public static final int
		RULE_command = 0, RULE_setCommand = 1, RULE_readCommand = 2;
	public static final String[] ruleNames = {
		"command", "setCommand", "readCommand"
	};

	@Override
	public String getGrammarFileName() { return "ArduinoHostGrammar.g4"; }

	@Override
	public String[] getTokenNames() { return tokenNames; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public ArduinoHostGrammarParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class CommandContext extends ParserRuleContext {
		public ReadCommandContext readCommand() {
			return getRuleContext(ReadCommandContext.class,0);
		}
		public SetCommandContext setCommand() {
			return getRuleContext(SetCommandContext.class,0);
		}
		public CommandContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_command; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArduinoHostGrammarListener ) ((ArduinoHostGrammarListener)listener).enterCommand(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArduinoHostGrammarListener ) ((ArduinoHostGrammarListener)listener).exitCommand(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArduinoHostGrammarVisitor ) return ((ArduinoHostGrammarVisitor<? extends T>)visitor).visitCommand(this);
			else return visitor.visitChildren(this);
		}
	}

	public final CommandContext command() throws RecognitionException {
		CommandContext _localctx = new CommandContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_command);
		try {
			setState(8);
			switch (_input.LA(1)) {
			case SET:
				enterOuterAlt(_localctx, 1);
				{
				setState(6); setCommand();
				}
				break;
			case READ:
			case ANALOG:
			case DIGITAL:
				enterOuterAlt(_localctx, 2);
				{
				setState(7); readCommand();
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

	public static class SetCommandContext extends ParserRuleContext {
		public TerminalNode INT(int i) {
			return getToken(ArduinoHostGrammarParser.INT, i);
		}
		public List<TerminalNode> INT() { return getTokens(ArduinoHostGrammarParser.INT); }
		public TerminalNode LOW() { return getToken(ArduinoHostGrammarParser.LOW, 0); }
		public TerminalNode SET() { return getToken(ArduinoHostGrammarParser.SET, 0); }
		public TerminalNode HIGH() { return getToken(ArduinoHostGrammarParser.HIGH, 0); }
		public SetCommandContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_setCommand; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArduinoHostGrammarListener ) ((ArduinoHostGrammarListener)listener).enterSetCommand(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArduinoHostGrammarListener ) ((ArduinoHostGrammarListener)listener).exitSetCommand(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArduinoHostGrammarVisitor ) return ((ArduinoHostGrammarVisitor<? extends T>)visitor).visitSetCommand(this);
			else return visitor.visitChildren(this);
		}
	}

	public final SetCommandContext setCommand() throws RecognitionException {
		SetCommandContext _localctx = new SetCommandContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_setCommand);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(10); match(SET);
			setState(11); match(INT);
			setState(12);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << HIGH) | (1L << LOW) | (1L << INT))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			consume();
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

	public static class ReadCommandContext extends ParserRuleContext {
		public TerminalNode DIGITAL() { return getToken(ArduinoHostGrammarParser.DIGITAL, 0); }
		public TerminalNode ANALOG() { return getToken(ArduinoHostGrammarParser.ANALOG, 0); }
		public TerminalNode READ() { return getToken(ArduinoHostGrammarParser.READ, 0); }
		public TerminalNode INT() { return getToken(ArduinoHostGrammarParser.INT, 0); }
		public ReadCommandContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_readCommand; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArduinoHostGrammarListener ) ((ArduinoHostGrammarListener)listener).enterReadCommand(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArduinoHostGrammarListener ) ((ArduinoHostGrammarListener)listener).exitReadCommand(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArduinoHostGrammarVisitor ) return ((ArduinoHostGrammarVisitor<? extends T>)visitor).visitReadCommand(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ReadCommandContext readCommand() throws RecognitionException {
		ReadCommandContext _localctx = new ReadCommandContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_readCommand);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(15);
			_la = _input.LA(1);
			if (_la==ANALOG || _la==DIGITAL) {
				{
				setState(14);
				_la = _input.LA(1);
				if ( !(_la==ANALOG || _la==DIGITAL) ) {
				_errHandler.recoverInline(this);
				}
				consume();
				}
			}

			setState(17); match(READ);
			setState(18); match(INT);
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
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3\13\27\4\2\t\2\4\3"+
		"\t\3\4\4\t\4\3\2\3\2\5\2\13\n\2\3\3\3\3\3\3\3\3\3\4\5\4\22\n\4\3\4\3\4"+
		"\3\4\3\4\2\2\5\2\4\6\2\4\4\2\5\6\n\n\3\2\7\b\25\2\n\3\2\2\2\4\f\3\2\2"+
		"\2\6\21\3\2\2\2\b\13\5\4\3\2\t\13\5\6\4\2\n\b\3\2\2\2\n\t\3\2\2\2\13\3"+
		"\3\2\2\2\f\r\7\3\2\2\r\16\7\n\2\2\16\17\t\2\2\2\17\5\3\2\2\2\20\22\t\3"+
		"\2\2\21\20\3\2\2\2\21\22\3\2\2\2\22\23\3\2\2\2\23\24\7\4\2\2\24\25\7\n"+
		"\2\2\25\7\3\2\2\2\4\n\21";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}