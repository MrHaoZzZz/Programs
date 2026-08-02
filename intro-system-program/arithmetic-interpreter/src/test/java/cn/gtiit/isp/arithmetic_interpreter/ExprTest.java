package cn.gtiit.isp.arithmetic_interpreter;

import java.math.BigInteger;
import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.Test;

public class ExprTest {

    @Test
    void test_symbol() {
        Expr e = new Expr(new Symbol("hello"));
        assertEquals(Tag.SYMBOL, e.tag());
        assertEquals(new Symbol("hello"), e.symbol());
        assertEquals("hello", e.symbol().getName());
        assertEquals(true, e.isTheSymbol("hello"));
    }

    @Test
    void test_number() {
        Expr e = new Expr(new BigInteger("123456789"));
        assertEquals(Tag.NUMBER, e.tag());
        assertEquals(new BigInteger("123456789"), e.number());
        assertEquals(false, e.isTheSymbol("hello"));
    }

    @Test
    void test_list() {
        ArrayList<Expr> list = new ArrayList<>();
        list.add(new Expr(new Symbol("bye")));
        list.add(new Expr(new BigInteger("123")));

        Expr e = new Expr(list);
        assertEquals(Tag.LIST, e.tag());
        assertEquals(2, e.subexpressions().size());
        assertEquals(new Symbol("bye"), e.subexpressions().get(0).symbol());
        assertEquals(new BigInteger("123"), e.subexpressions().get(1).number());
    }

    /* ADD MORE TESTS */
    @Test
    public void testToString() {
        Expr numberExpr = new Expr(new BigInteger("123"));
        assertEquals("123", numberExpr.toString());

        Expr symbolExpr = new Expr(new Symbol("hello"));
        assertEquals("hello", symbolExpr.toString());

        Expr emptyListExpr = new Expr(new ArrayList<>());
        assertEquals("()", emptyListExpr.toString());

        ArrayList<Expr> singleSubexpr = new ArrayList<>();
        singleSubexpr.add(new Expr(new BigInteger("1")));
        Expr singleSubexprExpr = new Expr(singleSubexpr);
        assertEquals("(1)", singleSubexprExpr.toString());

        ArrayList<Expr> multiSubexpr = new ArrayList<>();
        multiSubexpr.add(new Expr(new BigInteger("1")));
        multiSubexpr.add(new Expr(new BigInteger("2")));
        multiSubexpr.add(new Expr(new BigInteger("3")));
        multiSubexpr.add(new Expr(new BigInteger("4")));
        Expr multiSubexprExpr = new Expr(multiSubexpr);
        assertEquals("(1 2 3 4)", multiSubexprExpr.toString());

        ArrayList<Expr> addX2 = new ArrayList<>();
        addX2.add(new Expr(new Symbol("+")));
        addX2.add(new Expr(new Symbol("x")));
        addX2.add(new Expr(new BigInteger("2")));
        Expr addX2Expr = new Expr(addX2);

        ArrayList<Expr> addY3 = new ArrayList<>();
        addY3.add(new Expr(new Symbol("+")));
        addY3.add(new Expr(new Symbol("y")));
        addY3.add(new Expr(new BigInteger("3")));
        Expr addY3Expr = new Expr(addY3);

        ArrayList<Expr> nestedExprList = new ArrayList<>();
        nestedExprList.add(new Expr(new Symbol("*")));
        nestedExprList.add(addX2Expr);
        nestedExprList.add(addY3Expr);
        Expr nestedExpr = new Expr(nestedExprList);
        assertEquals("(* (+ x 2) (+ y 3))", nestedExpr.toString());
    }

    @Test
    public void testEqualsExpr() {
        Expr hello1 = new Expr(new Symbol("hello"));
        Expr hello2 = new Expr(new Symbol("hello"));
        assertTrue(hello1.equalsExpr(hello2));

        Expr hello = new Expr(new Symbol("hello"));
        Expr goodbye = new Expr(new Symbol("goodbye"));
        assertFalse(hello.equalsExpr(goodbye));

        Expr num123a = new Expr(new BigInteger("123"));
        Expr num123b = new Expr(new BigInteger("123"));
        assertTrue(num123a.equalsExpr(num123b));

        Expr num123 = new Expr(new BigInteger("123"));
        Expr num321 = new Expr(new BigInteger("321"));
        assertFalse(num123.equalsExpr(num321));

        Expr number = new Expr(new BigInteger("123"));
        Expr symbol = new Expr(new Symbol("hello"));
        assertFalse(number.equalsExpr(symbol));

        Expr emptyList1 = new Expr(new ArrayList<>());
        Expr emptyList2 = new Expr(new ArrayList<>());
        assertTrue(emptyList1.equalsExpr(emptyList2));

        ArrayList<Expr> list3 = new ArrayList<>();
        list3.add(new Expr(new BigInteger("1")));
        list3.add(new Expr(new BigInteger("2")));
        list3.add(new Expr(new BigInteger("3")));
        Expr expr3 = new Expr(list3);

        ArrayList<Expr> list4 = new ArrayList<>();
        list4.add(new Expr(new BigInteger("1")));
        list4.add(new Expr(new BigInteger("2")));
        list4.add(new Expr(new BigInteger("3")));
        list4.add(new Expr(new BigInteger("4")));
        Expr expr4 = new Expr(list4);
        assertFalse(expr3.equalsExpr(expr4));

        ArrayList<Expr> addX2_1 = new ArrayList<>();
        addX2_1.add(new Expr(new Symbol("+")));
        addX2_1.add(new Expr(new Symbol("x")));
        addX2_1.add(new Expr(new BigInteger("2")));
        Expr addX2Expr1 = new Expr(addX2_1);

        ArrayList<Expr> addY3_1 = new ArrayList<>();
        addY3_1.add(new Expr(new Symbol("+")));
        addY3_1.add(new Expr(new Symbol("y")));
        addY3_1.add(new Expr(new BigInteger("3")));
        Expr addY3Expr1 = new Expr(addY3_1);

        ArrayList<Expr> nested1 = new ArrayList<>();
        nested1.add(new Expr(new Symbol("*")));
        nested1.add(addX2Expr1);
        nested1.add(addY3Expr1);
        Expr nestedExpr1 = new Expr(nested1);

        ArrayList<Expr> addX2_2 = new ArrayList<>();
        addX2_2.add(new Expr(new Symbol("+")));
        addX2_2.add(new Expr(new Symbol("x")));
        addX2_2.add(new Expr(new BigInteger("2")));
        Expr addX2Expr2 = new Expr(addX2_2);

        ArrayList<Expr> addY3_2 = new ArrayList<>();
        addY3_2.add(new Expr(new Symbol("+")));
        addY3_2.add(new Expr(new Symbol("y")));
        addY3_2.add(new Expr(new BigInteger("3")));
        Expr addY3Expr2 = new Expr(addY3_2);

        ArrayList<Expr> nested2 = new ArrayList<>();
        nested2.add(new Expr(new Symbol("*")));
        nested2.add(addX2Expr2);
        nested2.add(addY3Expr2);
        Expr nestedExpr2 = new Expr(nested2);
        assertTrue(nestedExpr1.equalsExpr(nestedExpr2));

        ArrayList<Expr> ab1 = new ArrayList<>();
        ab1.add(new Expr(new Symbol("a")));
        ab1.add(new Expr(new Symbol("b")));
        Expr abExpr1 = new Expr(ab1);

        ArrayList<Expr> x2 = new ArrayList<>();
        x2.add(new Expr(new Symbol("x")));
        x2.add(new Expr(new BigInteger("2")));
        Expr x2Expr = new Expr(x2);

        ArrayList<Expr> diffList1 = new ArrayList<>();
        diffList1.add(abExpr1);
        diffList1.add(x2Expr);
        Expr diffExpr1 = new Expr(diffList1);

        ArrayList<Expr> ab2 = new ArrayList<>();
        ab2.add(new Expr(new Symbol("a")));
        ab2.add(new Expr(new Symbol("b")));
        Expr abExpr2 = new Expr(ab2);

        ArrayList<Expr> y2 = new ArrayList<>();
        y2.add(new Expr(new Symbol("y")));
        y2.add(new Expr(new BigInteger("2")));
        Expr y2Expr = new Expr(y2);

        ArrayList<Expr> diffList2 = new ArrayList<>();
        diffList2.add(abExpr2);
        diffList2.add(y2Expr);
        Expr diffExpr2 = new Expr(diffList2);
        assertFalse(diffExpr1.equalsExpr(diffExpr2));
    }
}
