import java.util.ArrayList ;

public class exe2
{
    public static void main( String[] args )
    {
        int n = 0 ;
        ArrayList<Character> alphabet = new ArrayList<>() ;

        System.out.println( allWords( n , alphabet ) ) ;
    }

    public static ArrayList<String> allWords( int n , ArrayList<Character> alphabet )
    {
        if ( n == 0 ) return new ArrayList<>() ;
        
        ArrayList<String> pre = allWords( n-1 , alphabet ) ;
        ArrayList<String> res = new ArrayList<>() ;
        for ( String s : pre )
        {
            for ( Character c : alphabet )
            {
                res.add( s + c ) ;
            }
        }
        return res ;
    }
}

/*
String s1 = "hel" ;
String s2 = "lo"  ;

String s3 = s1 + s2 ;

s3 == "hello"
*/

/*
for ( T element : Set<T> set )
for ( int i = 0 ; i < n ; i ++ ) -> for ( int i : range( 0 , n-1 ) ) 
*/

/*
ArrayList<Character> alphabet = ['a','b','c'] ;
for ( char c : alphabet )
*/