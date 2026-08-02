public class exe1
{
    public static void main( String[] args )
    {
        test1() ;
        split() ;
        test2() ;
        split() ;
        test3() ;
        split() ;
        test4() ;
    }

    static void split()
    {
        System.out.println( "----------------------------------------------" ) ;
    }

    static void test1()
    {
        List<Integer> list = new List<>();
        System.out.println( list.length() ) ; // 0
        list.add(0, 10);
        System.out.println( list.length() ) ; // 1
        System.out.println( list.get(0) ) ; // 10
        list.add(0, 20);
        System.out.println( list.length() ) ; // 2
        System.out.println( list.get(0) ) ; // 20
        System.out.println( list.get(1) ) ; // 10
        list.add(1, 30);
        System.out.println( list.length() ) ; // 3
        System.out.println( list.get(0) ) ; // 20
        System.out.println( list.get(1) ) ; // 30
        System.out.println( list.get(2) ) ; // 10
        list.set(1, 40);
        System.out.println( list.length() ) ; // 3
        System.out.println( list.get(0) ) ; // 20
        System.out.println( list.get(1) ) ; // 40
        System.out.println( list.get(2) ) ; // 10
        list.remove(0);
        System.out.println( list.length() ) ; // 2
        System.out.println( list.get(0) ) ; // 40
        System.out.println( list.get(1) ) ; // 10
    }

    static void test2()
    {
        List<Integer> list1 = new List<>() ;
        list1.add(0, 30) ;
        list1.add(1, 20) ;
        list1.add(2, 10) ;
        System.out.println( list1 ) ; // [30, 20, 10]
        System.out.println( list1.findIndex(30) ) ; // 0
        System.out.println( list1.findIndex(20) ) ; // 1
        System.out.println( list1.findIndex(10) ) ; // 2
        System.out.println( list1.findIndex(40) ) ; // -1
    }

    static void test3()
    {
        List<Integer> list1 = new List<>() ;
        List<Integer> list2 = new List<>() ;
        list1.add( 0 , 1 ) ;
        list1.add( 1 , 2 ) ;
        list1.add( 2 , 3 ) ;
        list2.add( 0 , 4 ) ;
        list2.add( 1 , 5 ) ;
        System.out.println(list1); // [1, 2, 3]
        System.out.println(list2); // [4, 5]
        System.out.println(list1.concatenate(list2)); // [1, 2, 3, 4, 5]
        System.out.println(list1); // [1, 2, 3]
        System.out.println(list2); // [4, 5]
    }

    static void test4()
    {
        List<Integer> list = new List<>() ;
        list.add(0, 10) ;
        list.add(1, 20) ;
        list.add(2, 30) ;
        System.out.println(list); // [10, 20, 30]
        list.reverse();
        System.out.println(list); // [30, 20, 10]
    }
}

class List<T> {
    // (a)
    public List() {
        this.head = new Node() ;
        this.tail = new Node() ;
        this.head.next = this.tail ;
        this.tail.prev = this.head ;
        this.size = 0 ;
    }
    public int length() {
        return this.size ;
    }
    public void add(int i, T x) {
        assert i >= 0 && i <= this.size ; // To check the procondition
        Node p ;
        if ( i == 0 ) p = this.head ;
        else p = access( i - 1 ) ;

        Node newNode = new Node() ;
        newNode.value = x ;
        newNode.prev  = p ;
        newNode.next  = p.next ;
        p.next = newNode ;
        newNode.next.prev = newNode ;
        this.size ++ ;
    }
    public T get(int i) {
        assert i >= 0 && i <= this.size ; // To check the procondition
        return access( i ).value ;
    }
    public void set(int i, T x) {
        assert i >= 0 && i <= this.size ; // To check the procondition
        access( i ).value = x ;
    }
    public void remove(int i) {
        assert i >= 0 && i <= this.size ; // To check the procondition
        Node p = access( i ) ;
        p.prev.next = p.next ;
        p.next.prev = p.prev ;
        this.size -- ;
    }

    // (b)
    @Override
    public String toString()
    {
        String output = "[" ;
        Node p = this.head.next ;
        while ( p != tail )
        {
            output += p.value ;
            p = p.next ;
            if ( p != tail ) output += ", " ;
        }
        output += "]" ;
        return output ;
    }

    // (c)
    public int findIndex( T element )
    {
        Node p = this.head.next ;
        for ( int i = 0 ; p != this.tail ; i ++ , p = p.next )
        {
            if ( p.value == element )
            {
                return i ;
            }
        }
        return -1 ;
    }

    // (d)
    public List<T> concatenate( List<T> other )
    {
        List<T> ans = new List<>() ;
        Node last = ans.head ;

        Node current = this.head.next ;
        while ( current != this.tail )
        {
            Node newNode = new Node() ;
            newNode.value = current.value ;
            newNode.prev = last ;
            newNode.next = ans.tail ;
            last.next = newNode ;
            ans.tail.prev = newNode ;
            last = newNode ; // move last to the next node
            ans.size ++ ;
            current = current.next ;
        }

        current = other.head.next ;
        while ( current != other.tail )
        {
            Node newNode = new Node() ;
            newNode.value = current.value ;
            newNode.prev = last ;
            newNode.next = ans.tail ;
            last.next = newNode ;
            ans.tail.prev = newNode ;
            last = newNode ;
            ans.size ++ ;
            current = current.next ;
        }
        return ans ;
    }

    // (f)
    void reverse()
    {
        Node current = this.head.next ;
        while ( current != this.tail )
        {
            Node temp = current.next ;
            current.next = current.prev ;
            current.prev = temp ;
            current = temp ;
        }

        Node newFirst = this.tail.prev ;
        Node newLast  = this.head.next ;
        newFirst.prev = this.head ;
        newLast.next  = this.tail ;
        this.head.next = newFirst ;
        this.tail.prev = newLast ;
    }

    // Auxiliary method
    private Node access( int i )
    {
        assert i >= 0 && i <= this.size ; // To check the procondition
        Node p = this.head.next ;
        for ( int j = 0 ; j < i ; j ++ ) p = p.next ;
        return p ;
    }


    /* Auxiliary nested class */
    private class Node {
        T value;
        Node prev;
        Node next;
    }
    /* Fields */
    private final Node head , tail ;
    private int size ;
}