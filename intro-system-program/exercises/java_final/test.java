public class test
{
    static void main( String[] args )
    {
        A a ;
        B b ;
        a.A() ; b.B() ;
        a.out() ;
        b.out() ;
    }

    class A
    {
        A(){}
        void out()
        {
            System.out.println("A") ;
        }
    }

    class B
    {
        B(){}
        void out()
        {
            System.out.println("B") ;
        }
    }
}



/*

1+2+3+4 = (1+2+3+4)

3! = 3 * 2! = 3 * ( 2 * 1! ) = 3 * ( 2 * ( 1 ) )

1! = 1 * 0! = 1 * 1 = 1
2! = 2 * 1! = 2 * 1 = 2
3! = 3 * 2! = 3 * 2 = 6

fun fac( n : int ) -> int
    if n = 0 then
        return 1
    
    return n * fac( n-1 )

*/