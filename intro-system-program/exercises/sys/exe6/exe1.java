public class exe1
{
    public static void main( String[] args )
    {
        int n = 0 ;
        System.out.println( lucas(n) ) ;
    }
    public static int lucas( int n )
    {
        return switch (n)
        {
            case 0 -> 2 ;
            case 1 -> 1 ;
            default -> lucas( n-1 ) + lucas( n-2 ) ;
        } ;
    }
}