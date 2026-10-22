public class p3
{
    private static int[] dutchFlag( int[] sequence )
    {
        int[] counter = {0 , 0 , 0} ;
        int[] ans = new int[ sequence.length ] ;
        for ( int i = 0 ; i < sequence.length ; i ++ )  counter[ sequence[i] ] ++ ;
        int pos = 0 ;
        for ( int i = 0 ; i < 3 ; i ++ )
        {
            for ( int j = 0 ; j < counter[i] ; j ++ )
            {
                ans[ pos ++ ] = i ;
            }
        }
        return ans ;
    }

    private static void printArray( int[] array )
    {
        for ( int i = 0 ; i < array.length ; i ++ )
        {
            System.out.print( array[i] + " " ) ; 
        }
        System.out.println( "" ) ;
    }

    public static void main(String[] args)
    {
        int[] sequence = {0, 1, 2, 0, 2, 1, 0, 2, 1, 0} ;
        printArray( dutchFlag( sequence ) ) ;
    }
}