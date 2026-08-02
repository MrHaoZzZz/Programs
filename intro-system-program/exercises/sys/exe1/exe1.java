public class exe1
{
    static void main( String[] args )
    {
        Counter cnt = new Counter() ;
        System.out.println( cnt.get() ) ; // 0
        cnt.increment() ;
        System.out.println( cnt.get() ) ; // 1
        cnt.decrement() ;
        System.out.println( cnt.get() ) ; // 0
        cnt.decrement() ;
        System.out.println( cnt.get() ) ; // -1
    }
}

class Counter
{
    // Method 
    Counter()
    {
        this.a = 0 ;
    }

    void increment()
    {
        this.a ++ ;
    }

    void decrement()
    {
        this.a -- ;
    }

    int get()
    {
        return this.a ;
    }

    // Field
    private int a ;
}