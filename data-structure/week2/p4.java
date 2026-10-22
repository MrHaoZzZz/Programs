public class p4
{
    private static int iterativeBinarySearch( int[] sequence , int target )
    {
        int left = 0 , right = sequence.length - 1 ;
        while ( left <= right )
        {
            int mid = left + ( right - left ) / 2 ;
            if ( sequence[mid] == target ) return mid ;
            if ( sequence[mid] < target ) left = mid + 1 ;
            else right = mid - 1 ;
        }
        return -1 ;
    }

    private static int recursiveBinarySearch( int[] sequence , int target )
    {
        return recursiveBinarySearch( sequence , target , 0 , sequence.length - 1 ) ;
    }

    // function override
    // to fix the enough signature
    private static int recursiveBinarySearch( int[] sequence , int target , int left , int right )
    {
        if ( left > right ) return -1 ;
        int mid = left + ( right - left ) / 2 ;
        if ( sequence[mid] == target ) return mid ;
        if ( sequence[mid] < target ) return recursiveBinarySearch( sequence , target , mid + 1 , right ) ;
        return recursiveBinarySearch( sequence , target , left , mid - 1 ) ;
    }

    public static void main( String[] args )
    {
        int[] sequence = { 0 , 2 , 5 , 7 , 9 , 11 , 35 , 56 , 67 , 91 } ;
        System.out.println( iterativeBinarySearch(sequence, 78)) ;
        System.out.println( iterativeBinarySearch(sequence, 91)) ;
        System.out.println( recursiveBinarySearch(sequence, 78)) ;
        System.out.println( recursiveBinarySearch(sequence, 91)) ;
        System.out.println( recursiveBinarySearch(sequence, 0)) ;
    }
}