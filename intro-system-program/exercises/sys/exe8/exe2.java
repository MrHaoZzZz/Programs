import java.util.ArrayList ;

public class exe2
{
    static void main( String[] args )
    {
        ArrayList<ArrayList<Integer>> table = new ArrayList<>() ;
        table.add( new ArrayList<>() ) ;
        table.add( new ArrayList<>() ) ;
        table.add( new ArrayList<>() ) ;
        table.add( new ArrayList<>() ) ;
        table.get(0).add(1) ;
        table.get(0).add(2) ;
        table.get(0).add(3) ;
        table.get(1).add(4) ;
        table.get(1).add(5) ;
        table.get(2).add(6) ;
        table.get(3).add(7) ;
        table.get(3).add(8) ;
        table.get(3).add(9) ;

        TableIterator it = new TableIterator<>(table);
        System.out.println(it.hasNext()); // true
        System.out.println(it.next()); // 1
        System.out.println(it.next()); // 2
        System.out.println(it.next()); // 3
        System.out.println(it.next()); // 4
        System.out.println(it.next()); // 5
        System.out.println(it.next()); // 6
        System.out.println(it.next()); // 7
        System.out.println(it.next()); // 8
        System.out.println(it.hasNext()); // true
        System.out.println(it.next()); // 9
        System.out.println(it.hasNext()); // false
    }
}

class TableIterator<T>
{

    public TableIterator( ArrayList<ArrayList<T>> table )
    {
        this.table = table ;
        i = j = 0 ;
    }
    
    boolean hasNext()
    {
        return i < table.size() && j < table.get( table.size() - 1 ).size();
    }

    T next()
    {
        T res = table.get(i).get(j) ;

        j ++ ;
        if ( j >= table.get(i).size() )
        {
            j = 0 ;
            i ++ ;
        }

        return res ;
    }

    private final ArrayList<ArrayList<T>> table ;
    private int i , j ;
}