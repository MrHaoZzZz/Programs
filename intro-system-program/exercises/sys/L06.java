public class L06
{
    static void main( String[] args )
    {
        System.out.println( fac(5) ) ;
        System.out.println( fib(7) ) ;
    }

    static int fac( int n )
    {
        if ( n == 0 ) return 1 ; // base step

        return n * fac( n - 1 ) ;
    }
    /*
    4! = 4 * 3!
    3! = 3 * 2!
    2! = 2 * 1!
    1! = 1 * 0!
    0! = 1
    */

    static int fib( int n )
    {
        if ( n == 1 ) return 1 ;
        if ( n == 2 ) return 1 ;

        return fib( n-1 ) + fib( n-2 ) ;
    }
    /*
    a_n+2 = a_n+1 + a_n
    1 1 2 3 5 8 13
    a_5 = a_4 + a_3
    a_4 = a_3 + a_2
    a_3 = a_2 + a_1
    a_2 = 1
    a_1 = 1
    */
}