package cn.gtiit.isp.arithmetic_interpreter;

import java.math.BigInteger;

import static org.junit.jupiter.api.Assertions.assertEquals;
import org.junit.jupiter.api.Test;

public class InterpreterTest {

    @Test
    void test_constant() {
        Interpreter i = new Interpreter();
        Expr expected = new Expr(new BigInteger("123"));
        Expr actual = i.evaluate(new Reader("123").readExpr());
        assertEquals(expected, actual);
    }

    @Test
    void test_variable() {
        Interpreter i = new Interpreter();
        i.evaluate(new Reader("(define length 10)").readExpr());
        Expr expected = new Expr(new BigInteger("10"));
        Expr actual = i.evaluate(new Reader("length").readExpr());
        assertEquals(expected, actual);
    }

    @Test
    void test_sum() {
        Interpreter i = new Interpreter();
        Expr expected = new Expr(new BigInteger("12"));
        Expr actual = i.evaluate(new Reader("(+ 7 5)").readExpr());
        assertEquals(expected, actual);
    }

    /* ADD MORE TESTS */
    @Test
    public void testArithmeticOperators() {
        Interpreter interpreter = new Interpreter();
        Reader reader;
        Expr expr;
        Expr result;

        reader = new Reader("(+ 1 2 3 4 5)");
        expr = reader.readExpr();
        result = interpreter.evaluate(expr);
        assertEquals(Tag.NUMBER, result.tag());
        assertEquals(BigInteger.valueOf(15), result.number());

        reader = new Reader("(- 100 1 2 3)");
        expr = reader.readExpr();
        result = interpreter.evaluate(expr);
        assertEquals(Tag.NUMBER, result.tag());
        assertEquals(BigInteger.valueOf(94), result.number());

        reader = new Reader("(* 2 3 4)");
        expr = reader.readExpr();
        result = interpreter.evaluate(expr);
        assertEquals(Tag.NUMBER, result.tag());
        assertEquals(BigInteger.valueOf(24), result.number());

        reader = new Reader("(/ 100 2 5)");
        expr = reader.readExpr();
        result = interpreter.evaluate(expr);
        assertEquals(Tag.NUMBER, result.tag());
        assertEquals(BigInteger.valueOf(10), result.number());

        reader = new Reader("(/ 7 2)");
        expr = reader.readExpr();
        result = interpreter.evaluate(expr);
        assertEquals(Tag.NUMBER, result.tag());
        assertEquals(BigInteger.valueOf(3), result.number());
    }

    @Test
    public void testVariableDefinition() {
        Interpreter interpreter = new Interpreter();
        Reader reader;
        Expr expr;
        Expr result;

        reader = new Reader("(define x 5)");
        expr = reader.readExpr();
        interpreter.evaluate(expr);

        reader = new Reader("(define y (* x x x))");
        expr = reader.readExpr();
        interpreter.evaluate(expr);

        reader = new Reader("(+ y y)");
        expr = reader.readExpr();
        result = interpreter.evaluate(expr);
        assertEquals(Tag.NUMBER, result.tag());
        assertEquals(BigInteger.valueOf(250), result.number());

        reader = new Reader("x");
        expr = reader.readExpr();
        result = interpreter.evaluate(expr);
        assertEquals(Tag.NUMBER, result.tag());
        assertEquals(BigInteger.valueOf(5), result.number());

        reader = new Reader("y");
        expr = reader.readExpr();
        result = interpreter.evaluate(expr);
        assertEquals(Tag.NUMBER, result.tag());
        assertEquals(BigInteger.valueOf(125), result.number());
    }

    @Test
    public void testCompleteProgram() {
        Interpreter interpreter = new Interpreter();
        Reader reader;
        Expr expr;
        Expr result;

        reader = new Reader("(define x 10)");
        expr = reader.readExpr();
        interpreter.evaluate(expr);

        reader = new Reader("(define y 3)");
        expr = reader.readExpr();
        interpreter.evaluate(expr);

        reader = new Reader("(+ (* 2 x) y)");
        expr = reader.readExpr();
        result = interpreter.evaluate(expr);
        assertEquals(Tag.NUMBER, result.tag());
        assertEquals(BigInteger.valueOf(23), result.number());
    }
}
