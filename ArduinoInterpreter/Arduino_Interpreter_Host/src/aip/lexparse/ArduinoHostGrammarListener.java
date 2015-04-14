// Generated from ArduinoHostGrammar.g4 by ANTLR 4.4
package aip.lexparse;
import org.antlr.v4.runtime.misc.NotNull;
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ArduinoHostGrammarParser}.
 */
public interface ArduinoHostGrammarListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ArduinoHostGrammarParser#readCommand}.
	 * @param ctx the parse tree
	 */
	void enterReadCommand(@NotNull ArduinoHostGrammarParser.ReadCommandContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArduinoHostGrammarParser#readCommand}.
	 * @param ctx the parse tree
	 */
	void exitReadCommand(@NotNull ArduinoHostGrammarParser.ReadCommandContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArduinoHostGrammarParser#setCommand}.
	 * @param ctx the parse tree
	 */
	void enterSetCommand(@NotNull ArduinoHostGrammarParser.SetCommandContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArduinoHostGrammarParser#setCommand}.
	 * @param ctx the parse tree
	 */
	void exitSetCommand(@NotNull ArduinoHostGrammarParser.SetCommandContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArduinoHostGrammarParser#command}.
	 * @param ctx the parse tree
	 */
	void enterCommand(@NotNull ArduinoHostGrammarParser.CommandContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArduinoHostGrammarParser#command}.
	 * @param ctx the parse tree
	 */
	void exitCommand(@NotNull ArduinoHostGrammarParser.CommandContext ctx);
}