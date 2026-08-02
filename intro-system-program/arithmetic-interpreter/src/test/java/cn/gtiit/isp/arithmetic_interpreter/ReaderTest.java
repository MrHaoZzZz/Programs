package cn.gtiit.isp.arithmetic_interpreter;

import java.math.BigInteger;
import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.Test;

public class ReaderTest {

    @Test
    void test_skip_whitespace() {
        Reader r = new Reader("   xyz   ");
        assertEquals(0, r.position());
        r.skipWhitespace();
        assertEquals(3, r.position());
        r.skipWhitespace();
        assertEquals(3, r.position());
    }

    @Test
    void test_read_symbol() {
        Reader r = new Reader("* width length");
        Symbol s1 = r.readSymbol();
        assertEquals(1, r.position());
        r.skipWhitespace();
        Symbol s2 = r.readSymbol();
        assertEquals(7, r.position());
        r.skipWhitespace();
        Symbol s3 = r.readSymbol();
        assertEquals(14, r.position());
        assertEquals(new Symbol("*"), s1);
        assertEquals(new Symbol("width"), s2);
        assertEquals(new Symbol("length"), s3);
    }

    @Test
    void test_read_number() {
        Reader r = new Reader("0 123 9999999999999999");
        BigInteger n1 = r.readNumber();
        assertEquals(1, r.position());
        r.skipWhitespace();
        BigInteger n2 = r.readNumber();
        assertEquals(5, r.position());
        r.skipWhitespace();
        BigInteger n3 = r.readNumber();
        assertEquals(22, r.position());
        assertEquals(new BigInteger("0"), n1);
        assertEquals(new BigInteger("123"), n2);
        assertEquals(new BigInteger("9999999999999999"), n3);
    }

    /* ADD MORE TESTS */
     @Test
    public void testReadExpr_JustNumber() {
        Reader reader = new Reader("123");
        Expr actual = reader.readExpr();
        Expr expected = new Expr(BigInteger.valueOf(123));
        assertTrue(actual.equalsExpr(expected));
    }

    @Test
    public void testReadExpr_NumberWithSpaces() {
        Reader reader = new Reader(" 123 ");
        Expr actual = reader.readExpr();
        Expr expected = new Expr(BigInteger.valueOf(123));
        assertTrue(actual.equalsExpr(expected));
    }

    @Test
    public void testReadExpr_JustSymbol() {
        Reader reader = new Reader("hello");
        Expr actual = reader.readExpr();
        Expr expected = new Expr(new Symbol("hello"));
        assertTrue(actual.equalsExpr(expected));
    }

    @Test
    public void testReadExpr_SymbolWithSpaces() {
        Reader reader = new Reader(" hello ");
        Expr actual = reader.readExpr();
        Expr expected = new Expr(new Symbol("hello"));
        assertTrue(actual.equalsExpr(expected));
    }

    @Test
    public void testReadExpr_EmptyList() {
        Reader reader = new Reader("()");
        Expr actual = reader.readExpr();
        Expr expected = new Expr(new ArrayList<>());
        assertTrue(actual.equalsExpr(expected));
    }

    @Test
    public void testReadExpr_SingleElementList() {
        Reader reader = new Reader("(1)");
        Expr actual = reader.readExpr();
        
        ArrayList<Expr> subexprs = new ArrayList<>();
        subexprs.add(new Expr(BigInteger.valueOf(1)));
        Expr expected = new Expr(subexprs);
        
        assertTrue(actual.equalsExpr(expected));
    }

    @Test
    public void testReadExpr_MultiElementList() {
        Reader reader = new Reader("(1 2 3 4)");
        Expr actual = reader.readExpr();
        
        ArrayList<Expr> subexprs = new ArrayList<>();
        subexprs.add(new Expr(BigInteger.valueOf(1)));
        subexprs.add(new Expr(BigInteger.valueOf(2)));
        subexprs.add(new Expr(BigInteger.valueOf(3)));
        subexprs.add(new Expr(BigInteger.valueOf(4)));
        Expr expected = new Expr(subexprs);
        
        assertTrue(actual.equalsExpr(expected));
    }

    @Test
    public void testReadExpr_NestedLists() {
        Reader reader = new Reader("(* (+ x 2) (+ y 3))");
        Expr actual = reader.readExpr();
        
        ArrayList<Expr> inner1 = new ArrayList<>();
        inner1.add(new Expr(new Symbol("+")));
        inner1.add(new Expr(new Symbol("x")));
        inner1.add(new Expr(BigInteger.valueOf(2)));
        Expr inner1Expr = new Expr(inner1);
        
        ArrayList<Expr> inner2 = new ArrayList<>();
        inner2.add(new Expr(new Symbol("+")));
        inner2.add(new Expr(new Symbol("y")));
        inner2.add(new Expr(BigInteger.valueOf(3)));
        Expr inner2Expr = new Expr(inner2);
        
        ArrayList<Expr> outer = new ArrayList<>();
        outer.add(new Expr(new Symbol("*")));
        outer.add(inner1Expr);
        outer.add(inner2Expr);
        Expr expected = new Expr(outer);
        
        assertTrue(actual.equalsExpr(expected));
    }

    @Test
    public void testReadExpr_ExtraSpacesBeforeStart() {
        Reader reader = new Reader("   (1 2 3)");
        Expr actual = reader.readExpr();
        
        ArrayList<Expr> subexprs = new ArrayList<>();
        subexprs.add(new Expr(BigInteger.valueOf(1)));
        subexprs.add(new Expr(BigInteger.valueOf(2)));
        subexprs.add(new Expr(BigInteger.valueOf(3)));
        Expr expected = new Expr(subexprs);
        
        assertTrue(actual.equalsExpr(expected));
    }

    @Test
    public void testReadExpr_ExtraSpacesAfterLeftParen() {
        Reader reader = new Reader("(   1 2 3)");
        Expr actual = reader.readExpr();
        
        ArrayList<Expr> subexprs = new ArrayList<>();
        subexprs.add(new Expr(BigInteger.valueOf(1)));
        subexprs.add(new Expr(BigInteger.valueOf(2)));
        subexprs.add(new Expr(BigInteger.valueOf(3)));
        Expr expected = new Expr(subexprs);
        
        assertTrue(actual.equalsExpr(expected));
    }

    @Test
    public void testReadExpr_ExtraSpacesBetweenElements() {
        Reader reader = new Reader("(1   2  3)");
        Expr actual = reader.readExpr();
        
        ArrayList<Expr> subexprs = new ArrayList<>();
        subexprs.add(new Expr(BigInteger.valueOf(1)));
        subexprs.add(new Expr(BigInteger.valueOf(2)));
        subexprs.add(new Expr(BigInteger.valueOf(3)));
        Expr expected = new Expr(subexprs);
        
        assertTrue(actual.equalsExpr(expected));
    }

    @Test
    public void testReadExpr_ExtraSpacesBeforeRightParen() {
        Reader reader = new Reader("(1 2 3   )");
        Expr actual = reader.readExpr();
        
        ArrayList<Expr> subexprs = new ArrayList<>();
        subexprs.add(new Expr(BigInteger.valueOf(1)));
        subexprs.add(new Expr(BigInteger.valueOf(2)));
        subexprs.add(new Expr(BigInteger.valueOf(3)));
        Expr expected = new Expr(subexprs);
        
        assertTrue(actual.equalsExpr(expected));
    }

    @Test
    public void testReadExpr_ExtraSpacesAfterEnd() {
        Reader reader = new Reader("(1 2 3)   ");
        Expr actual = reader.readExpr();
        
        ArrayList<Expr> subexprs = new ArrayList<>();
        subexprs.add(new Expr(BigInteger.valueOf(1)));
        subexprs.add(new Expr(BigInteger.valueOf(2)));
        subexprs.add(new Expr(BigInteger.valueOf(3)));
        Expr expected = new Expr(subexprs);
        
        assertTrue(actual.equalsExpr(expected));
    }

    @Test
    public void testReadProgram_Empty() {
        Reader reader = new Reader("");
        ArrayList<Expr> program = reader.readProgram();
        assertTrue(program.isEmpty());
    }

    @Test
    public void testReadProgram_EmptyWithSpaces() {
        Reader reader = new Reader("   ");
        ArrayList<Expr> program = reader.readProgram();
        assertTrue(program.isEmpty());
    }

    @Test
    public void testReadProgram_ExpressionsWithSpaces() {
        Reader reader = new Reader("abc 123 (d e f)   (g)   ");
        ArrayList<Expr> actual = reader.readProgram();
        
        ArrayList<Expr> expected = new ArrayList<>();
        expected.add(new Expr(new Symbol("abc")));
        expected.add(new Expr(BigInteger.valueOf(123)));
        
        ArrayList<Expr> list1 = new ArrayList<>();
        list1.add(new Expr(new Symbol("d")));
        list1.add(new Expr(new Symbol("e")));
        list1.add(new Expr(new Symbol("f")));
        expected.add(new Expr(list1));
        
        ArrayList<Expr> list2 = new ArrayList<>();
        list2.add(new Expr(new Symbol("g")));
        expected.add(new Expr(list2));
        
        assertEquals(expected.size(), actual.size());
        for (int i = 0; i < expected.size(); i++) {
            assertTrue(actual.get(i).equalsExpr(expected.get(i)));
        }
    }

    @Test
    public void testReadProgram_ExpressionsNoSpaces() {
        Reader reader = new Reader("abc123(d e f)(g)");
        ArrayList<Expr> actual = reader.readProgram();
        
        ArrayList<Expr> expected = new ArrayList<>();
        expected.add(new Expr(new Symbol("abc")));
        expected.add(new Expr(BigInteger.valueOf(123)));
        
        ArrayList<Expr> list1 = new ArrayList<>();
        list1.add(new Expr(new Symbol("d")));
        list1.add(new Expr(new Symbol("e")));
        list1.add(new Expr(new Symbol("f")));
        expected.add(new Expr(list1));
        
        ArrayList<Expr> list2 = new ArrayList<>();
        list2.add(new Expr(new Symbol("g")));
        expected.add(new Expr(list2));
        
        assertEquals(expected.size(), actual.size());
        for (int i = 0; i < expected.size(); i++) {
            assertTrue(actual.get(i).equalsExpr(expected.get(i)));
        }
    }
}
