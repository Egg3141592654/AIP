// Generated from ArduinoHostGrammar.g4 by ANTLR 4.4
package aip.lexparse;
import org.antlr.v4.runtime.misc.NotNull;
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link ArduinoHostGrammarParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface ArduinoHostGrammarVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link ArduinoHostGrammarParser#readCommand}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitReadCommand(@NotNull ArduinoHostGrammarParser.ReadCommandContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArduinoHostGrammarParser#setCommand}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSetCommand(@NotNull ArduinoHostGrammarParser.SetCommandContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArduinoHostGrammarParser#command}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCommand(@NotNull ArduinoHostGrammarParser.CommandContext ctx);
}