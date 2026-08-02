package cn.gtiit.isp.arithmetic_interpreter;

import java.math.BigInteger;
import java.util.ArrayList ;
import java.util.HashMap ;
import java.util.Map ;

class Interpreter {

    Interpreter() {
        /* COMPLETE */
        this.command = new HashMap<>() ;
    }

    void runProgram(ArrayList<Expr> program) {
        for (Expr expr : program) {
            evaluate(expr);
        }
    }

    @SuppressWarnings("ConvertToStringSwitch")
    Expr evaluate(Expr expr) {
        /* COMPLETE */
        if ( expr.tag() == Tag.NUMBER ) return expr ;
        if ( expr.tag() == Tag.SYMBOL ) {
            String name = expr.symbol().getName() ;
            BigInteger value = this.command.get(name) ;
            return new Expr(value) ;
        }
        if ( expr.tag() == Tag.LIST )
        {
            ArrayList<Expr> subexprs = expr.subexpressions() ;
            String operation = subexprs.get(0).symbol().getName() ;

            if ( "define".equals(operation) )
            {
                String var = subexprs.get(1).symbol().getName() ;
                Expr valueExpr = evaluate(subexprs.get(2)) ;
                command.put(var, valueExpr.number()) ;
                return valueExpr ;
            }
            else if ( "print".equals(operation) )
            {
                Expr valueExpr = evaluate(subexprs.get(1)) ;
                System.out.println(valueExpr.number()) ;
                return valueExpr ;
            }
            else
            {
                BigInteger result = evaluate(subexprs.get(1)).number() ;
                for ( int i = 2 ; i < subexprs.size() ; i ++ )
                {
                    BigInteger operand = evaluate(subexprs.get(i)).number() ;
                    if ( "+".equals(operation) ) result = result.add(operand) ;
                    else if ( "-".equals(operation) ) result = result.subtract(operand) ;
                    else if ( "*".equals(operation) ) result = result.multiply(operand) ;
                    else if ( "/".equals(operation) ) result = result.divide(operand) ;
                }
                return new Expr(result) ;
            }
        }
        return null ;
    }

    /* Fields */
    /* COMPLETE */
    Map< String , BigInteger > command ;
}