import java.util.ArrayList ;

public class exe1
{
    static void main( String[] args )
    {
        // Queue
        Queue<Integer> q = new Queue<Integer>();
        q.addAtEnd(1);
        q.addAtEnd(2);
        q.addAtEnd(3);
        System.out.println( q.isEmpty() ) ;// false
        System.out.println( q.getFront() ) ; // 1
        System.out.println( q.getFront() ) ; // 1
        System.out.println( q.getFront() ) ; // 1
        q.removeFromFront();
        System.out.println( q.isEmpty() ) ; // false
        System.out.println( q.getFront() ) ; // 2
        q.removeFromFront();
        System.out.println( q.isEmpty() ) ; // false
        System.out.println( q.getFront() ) ; // 3
        q.removeFromFront();

        // Set 1
        Set<Integer> x = new Set<Integer>();
        x.insert(1);
        x.insert(1);
        x.insert(2);
        x.insert(3);
        System.out.println( x.cardinality() ) ; // 3
        System.out.println( x.contains(1) ) ; // true
        System.out.println( x.contains(2) ) ; // true
        System.out.println( x.contains(3) ) ; // true
        System.out.println( x.contains(4) ) ; // false
        x.remove(2);
        x.remove(2);
        System.out.println( x.cardinality() ) ; // 2
        System.out.println( x.contains(1) ) ; // true
        System.out.println( x.contains(2) ) ; // false
        System.out.println( x.contains(3) ) ; // true
        System.out.println( x.contains(4) ) ; // false
        System.out.println( x ) ;

        // Set 2
        String hello1 = "hello";
        String hello2 = "he";
        hello2 += "llo";
        Set<String> xx = new Set<String>() ;
        xx.insert(hello1);
        System.out.println( hello1 == hello2 ) ; // false
        System.out.println( hello1.equals( hello2 ) ) ; // true
        System.out.println( xx.contains(hello1) ) ; // true
        System.out.println( xx.contains(hello2) ) ; // true
        xx.remove(hello2);
        System.out.println( xx.contains(hello1) ) ; // false
        System.out.println( xx.contains(hello2) ) ; // false
        System.out.println( xx.cardinality() ) ; // 0
        xx.insert(hello1);
        xx.insert(hello2);
        System.out.println( xx.contains(hello1) ) ; // true
        System.out.println( xx.contains(hello2) ) ; // true
        System.out.println( xx.cardinality() ) ; // 1
        System.out.println( xx ) ;

        // Set 3
        Set<Integer> empty = new Set<Integer>() ;
        System.out.println( empty.toString() ) ; // -> System.out.println( empty.toString() ) ;
    }
}

class Queue<T>
{
    Queue()
    {
        this.q = new ArrayList<>() ;
        this.start = this.end = -1 ;
    }

    public boolean isEmpty()
    {
        return this.start == this.end ;
    }

    public void addAtEnd( T x )
    {
        q.add( x ) ;
        end ++ ;
    }

    public T getFront()
    {
        assert isEmpty() ;
        return q.get( start + 1 ) ;
    }

    public void removeFromFront()
    {
        assert isEmpty() ;
        start ++ ;
    }

    private ArrayList<T> q ;
    private int start , end ;
}

/*

q: 0 1 2 3 4 5 6 7 8 9

start = 1
end = 9

*/

class Stack<T>
{
    Stack()
    {
        this.s = new ArrayList<>() ;
        this.end = -1 ;
    }

    public boolean isEmpty()
    {
        return this.end == -1 ;
    }

    public void push( T x ) // int x 
    {
        s.add( x ) ;
        end ++ ;
    }

    public T pop()
    {
        T x = s.get( end ) ;
        s.remove( end ) ;
        return x ;
    }

    private ArrayList<T> s ;
    private int end ;
}

class Set<T>
{
    // Method
    Set()
    {
        this.s = new ArrayList<>() ;
    }

    public void insert( T x )
    {
        if ( s.contains( x ) ) return ;
        s.add( x ) ;
    }

    public int cardinality()
    {
        return s.size() ;
    }

    public boolean contains( T x )
    {
        return s.contains( x ) ;
    }

    public void remove( T x )
    {
        s.remove( x ) ;
    }

    
    @Override
    public String toString()
    {
        String res = "{" ;
        for ( int i = 0 ; i < s.size() - 1 ; i ++ )
        {
            res += s.get( i ) ;
            res += ", " ;
        }
        if ( !s.isEmpty() ) res += s.get( s.size() - 1 ) ;
        res += "}" ;
        return res ;
    }

    // Fields
    ArrayList<T> s ;
}