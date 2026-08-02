import java.util.Scanner;
public class j1 {
    public static void main(String args[]) throws Exception {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt() ;
        while ( n != 0 )
        {
            System.out.print( "f91(" ) ;
            System.out.print( n ) ;
            System.out.print( ") = " ) ;
            System.out.println( f91( n ) ) ;
            n = cin.nextInt() ;
        }
    }
    static int f91( int n )
    {
        if ( n >= 101 ) return n - 10 ;
        return f91( f91( n + 11 ) ) ;
    }
}