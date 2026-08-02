package cn.gtiit.isp.arithmetic_interpreter;

import java.math.BigInteger;
import java.util.ArrayList;

public class Expr {

    /* Methods */

    Expr(Symbol symbol) {
        /* COMPLETE */
        this.symbol = symbol ;
        this.tag = Tag.SYMBOL ;
    }

    Expr(BigInteger number) {
        /* COMPLETE */
        this.number = number ;
        this.tag = Tag.NUMBER ;
    }

    Expr(ArrayList<Expr> subexprs) {
        /* COMPLETE */
        this.subexprs = subexprs ;
        this.tag = Tag.LIST ;
    }

    Tag tag() {
        /* COMPLETE */
        return tag ;
    }

    Symbol symbol() {
        assert this.tag == Tag.SYMBOL;
        /* COMPLETE */
        return symbol ;
    }

    boolean isTheSymbol(String name) {
        /* COMPLETE */
        if ( this.tag == Tag.SYMBOL ) return this.symbol.getName().equals(name) ;
        return false ;
    }

    BigInteger number() {
        assert this.tag == Tag.NUMBER;
        /* COMPLETE */
        return number ;
    }

    ArrayList<Expr> subexpressions() {
        assert this.tag == Tag.LIST;
        /* COMPLETE */
        return subexprs ;
    }

    public String toString() {
        /* COMPLETE */
        if ( this.tag == Tag.SYMBOL ) return this.symbol.toString() ;
        if ( this.tag == Tag.NUMBER ) return this.number.toString() ;
        String result = "(" ;
        for ( int i = 0 ; i < this.subexprs.size() ; i ++ )
        {
            result += this.subexprs.get(i).toString() ;
            if ( i != this.subexprs.size() - 1 ) result += " " ;
        }
        result += ")" ;
        return result ;
    }

    public boolean equals(Object obj) {
        if (obj == null || this.getClass() != obj.getClass()) {
            return false;
        }
        return this.equalsExpr((Expr)obj);
    }

    boolean equalsExpr(Expr expr) {
        /* COMPLETE */
        if ( this.tag != expr.tag ) return false ;
        if ( this.tag == Tag.SYMBOL ) return this.symbol.equals(expr.symbol) ;
        if ( this.tag == Tag.NUMBER ) return this.number.equals(expr.number) ;
        if ( this.subexprs.size() != expr.subexprs.size() ) return false ;
        for ( int i = 0 ; i < this.subexprs.size() ; i ++ )
        {
            if ( !this.subexprs.get(i).equalsExpr(expr.subexprs.get(i)) ) return false ;
        }
        return true ;
    }

    /* Fields */
    private Tag tag;
    private Symbol symbol;
    private BigInteger number;
    private ArrayList<Expr> subexprs;
    // Class invariant:
    //   1)   (this.tag == Tag.SYMBOL)  if and only if  (this.symbol != null)
    //   2)   (this.tag == Tag.NUMBER)  if and only if  (this.number != null)
    //   3)   (this.tag == Tag.LIST)    if and only if  (this.subexprs != null)
}