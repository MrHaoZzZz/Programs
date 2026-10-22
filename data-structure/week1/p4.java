import java.util.ArrayList ;

/* Pseudocode
for i = 1 to n:
    if a[i] == v:
        return i
return NIL
*/

public class p4
{
    private static int linearSearch( ArrayList<Integer> sequence , int value )
    {
        for ( int i = 0 ; i < sequence.size() ; i ++ )
        {
            if ( sequence.get( i ) == value ) return i ;
        }
        return -1 ;
    }
}