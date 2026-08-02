package cn.gtiit.isp.arithmetic_interpreter;

import java.math.BigInteger;
import java.util.ArrayList;

class Reader {

    Reader(String text) {
        this.text = text;
        this.position = 0;
    }

    String text() {
        return this.text;
    }

    int position() {
        return this.position;
    }

    /* Categories of characters */

    private boolean isWhitespace(char c) {
        return c == ' ' || c == '\t' || c == '\r' || c == '\n';
    }

    private boolean isDigit(char c) {
        return '0' <= c && c <= '9';
    }

    private boolean isAlphabetic(char c) {
        return ('a' <= c && c <= 'z')
            || ('A' <= c && c <= 'Z');
    }

    private boolean isConstituent(char c) {
        return isAlphabetic(c)
            || c == '+' || c == '*' || c == '-' || c == '/' || c == '%'
            || c == '=' || c == '<' || c == '>' || c == '&' || c == '|'
            || c == '!' || c == '?';
    }

    /* Reader methods */

    void skipWhitespace() {
        /* COMPLETE */
        while ( this.position < this.text.length() && this.isWhitespace(this.text.charAt(this.position)) ) this.position ++ ;
    }

    Symbol readSymbol() {
        assert this.position < this.text.length()
            && this.isConstituent(this.text.charAt(this.position));
        /* COMPLETE */
        String res = "" ;
        while ( this.position < this.text.length() && this.isConstituent(this.text.charAt(this.position)) ) res += this.text.charAt(this.position++) ;
        return new Symbol(res) ;
    }

    BigInteger readNumber() {
        assert this.position < this.text.length()
            && this.isDigit(this.text.charAt(this.position));
        /* COMPLETE */
        String res = "" ;
        while ( this.position < this.text.length() && this.isDigit(this.text.charAt(this.position)) ) res += this.text.charAt(this.position++) ;
        return new BigInteger(res) ;
    }

    Expr readExpr() {
        // We assume as a precondition that the text contains
        // a well-formed expression starting at the current position
        // (possible preceded by spaces).
        assert this.position < this.text.length();
        /* COMPLETE */
        skipWhitespace() ;
        if ( isConstituent( text.charAt( this.position ) ) ) return new Expr( readSymbol() ) ;
        if ( isDigit( text.charAt( this.position ) ) ) return new Expr( readNumber() ) ;
        if ( text.charAt( this.position ) == '(' )
        {
            this.position ++ ;
            ArrayList<Expr> subexprs = new ArrayList<>() ;
            while ( true )
            {
                skipWhitespace() ;
                if ( this.position < this.text.length() && text.charAt( this.position ) == ')' )
                {
                    this.position ++ ;
                    break ;
                }
                subexprs.add( readExpr() ) ;
            }
            return new Expr(subexprs) ;
        }
        return null ;
    }

    ArrayList<Expr> readProgram() {
        /* COMPLETE */
        ArrayList<Expr> program = new ArrayList<>() ;
        skipWhitespace() ;
        while ( this.position < this.text.length() )
        {
            program.add( readExpr() ) ;
            skipWhitespace() ;
        }
        return program ;

    }

    /* Fields */
    private String text;
    private int position;
    // Class invariant:
    //   0 <= this.position && this.position <= this.text.length()
}