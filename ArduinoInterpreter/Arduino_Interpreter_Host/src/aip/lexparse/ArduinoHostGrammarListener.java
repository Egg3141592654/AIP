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
	 * Enter a parse tree produced by {@link ArduinoHostGrammarParser#r}.
	 * @param ctx the parse tree
	 */
	void enterR(@NotNull ArduinoHostGrammarParser.RContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArduinoHostGrammarParser#r}.
	 * @param ctx the parse tree
	 */
	void exitR(@NotNull ArduinoHostGrammarParser.RContext ctx);
}