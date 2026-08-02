import java.util.ArrayList ;

public class exe2
{
    static void main( String[] args )
    {
        ArrayList<Integer> a = new ArrayList<>();
        a.add(9); a.add(5); a.add(1); a.add(7); a.add(2); a.add(3); a.add(4);
        System.out.println(a); // Prints [9, 5, 1, 7, 2, 3, 4]
        selectionSort(a);
        System.out.println(a); // Prints [1, 2, 3, 4, 5, 7, 9]
    }

    static int minIndex( ArrayList<Integer> a , int start )
    {
        int minn = a.get( start ) ;
        int result = start ;
        for ( int i = start + 1 ; i < a.size() ; i ++ )
        {
            if ( minn > a.get( i ) )
            {
                minn = a.get( i ) ;
                result = i ;
            }
        }
        return result ;
    }

    static void selectionSort( ArrayList<Integer> a )
    {
        for ( int i = 0 ; i < a.size() ; i ++ )
        {
            int j = minIndex( a , i ) ;
            int temp = a.get( i ) ;
            a.set( i , a.get( j ) ) ;
            a.set( j , temp ) ;
        }
    }
}