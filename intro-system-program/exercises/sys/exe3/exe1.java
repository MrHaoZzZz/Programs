import java.util.ArrayList ;

public class exe1
{
    public static void main( String[] args )
    {
        // TODO code application logic here
        System.out.println(generateRange(3, 10)); // Prints [3, 4, 5, 6, 7, 8, 9, 10]
        System.out.println(generateRange(5, -1)); // Prints [5, 4, 3, 2, 1, 0, -1]
        // System.out.println(generateRange(0)); // Prints [0]
        // Maybe use overdide function??

        ArrayList<Integer> a = generateRange(1, 5);
        System.out.println(a); // Prints [1, 2, 3, 4, 5]
        System.out.println(reverse(a)); // Prints [5, 4, 3, 2, 1]
        System.out.println(a); // Prints [1, 2, 3, 4, 5]

        // ArrayList<Integer> a = generateRange(1, 5);
        System.out.println(a); // Prints [1, 2, 3, 4, 5]
        reverseInPlace(a);
        System.out.println(a); // Prints [5, 4, 3, 2, 1]
    }

    static ArrayList<Integer> generateRange( int start , int end )
    {
        ArrayList<Integer> result = new ArrayList<>() ;
        int sign = ( start < end ) ? 1 : -1 ;
        for ( int i = start ; i != end ; i += sign )
        {
            result.add( i ) ;
        }
        result.add( end ) ;
        return result ;
    }

    static ArrayList<Integer> reverse( ArrayList<Integer> a )
    {
        ArrayList<Integer> result = new ArrayList<>() ;
        for ( int i = a.size() - 1 ; i >= 0 ; i -- )
        {
            result.add( a.get( i ) ) ;
        }
        return result ;
    }

    static void reverseInPlace( ArrayList<Integer> a )
    {
        ArrayList<Integer> temp = new ArrayList<>() ;
        for ( int i = a.size() - 1 ; i >= 0 ; i -- )
        {
            temp.add( a.get( i ) ) ;
        }
        for ( int i = 0 ; i < a.size() ; i ++ )
        {
            a.set( i , temp.get( i ) ) ;
        }
    }
}