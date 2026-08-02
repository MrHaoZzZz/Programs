public class iterator
{
    public static void main( String args[] )
    {
        // void
    }

    static int sumAllElements( RangeIterator i )
    {
        int sum = 0 ;
        while ( i.hasNext() )
        {
            sum += i.next() ;
        }
        return sum ;
    }
}

class RangeIterator
{
    RangeIterator( int start , int end )
    {
        this.end = end ;
        this.index = start ;
    }

    boolean hasNext()
    {
        return this.index < this.end ;
    }

    int next()
    {
        return this.index ++ ;
    }

    private final int end ;
    private int index ;
}

class Point
{
    Point( int i , int j , int k )
    {
        this.i = i ;
        this.j = j ;
        this.k = k ;
    }

    private final int i , j , k ;
}

class BoxIeterator
{
    BoxIeterator( int n , int m , int p )
    {
        this.n = n ;
        this.m = m ;
        this.p = p ;
    }

    boolean hasNect()
    {
        return this.k < this.p ;
    }

    Point next()
    {
        Point point = new Point( i , j , k ) ;

        this.i ++ ;
        if ( this.i > this.n )
        {
            this.i = 0 ;
            this.j ++ ;
            if ( this.j > this.m )
            {
                this.j = 0 ;
                this.k ++ ;
            }
        }
        
        return point ;
    }

    private final int n , m , p ;
    private int i = 0 , j = 0 , k = 0 ;
}