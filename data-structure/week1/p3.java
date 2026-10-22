import java.util.ArrayList ;

public class p3
{
    private static int iterativeSum( ArrayList<Integer> sequence )
    {
        int i = 0 , ans = 0 ;
        while ( i < sequence.size() )
        {
            ans += sequence.get( i ) ;
            i ++ ;
        }
        return ans ;
    }

    private static int recursiveSum( ArrayList<Integer> sequence )
    {
        if ( sequence.size() == 1 ) return sequence.get( 0 ) ;
        return sequence.removeFirst() + recursiveSum( sequence ) ;
    }

    public static void main( String[] args )
    {
        ArrayList<Integer> sequence = new ArrayList<>() ;
        sequence.add( 1 ) ; sequence.add( 2 ) ; sequence.add( 3 ) ; sequence.add( 4 ) ; sequence.add( 5 ) ;
        System.out.println( iterativeSum(sequence)) ;
        System.out.println( recursiveSum(sequence)) ;
    }
}