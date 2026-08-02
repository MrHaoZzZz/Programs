import java.util.ArrayList ;
import java.util.HashSet ;
import java.util.Stack;

public class GraphAlgorithms {

    public static void main(String[] args) {
        test1() ;
        split() ;
        test2() ;
        split() ;
        test3() ;
        split() ;
        test4() ;
        split() ;
        test5() ;
    }

    static void split()
    {
        System.out.println("--------------------------------------------------");
    }

    static void test1()
    {
        Graph g = new Graph(7);
        g.add_edge(0, 1);
        g.add_edge(1, 2);
        g.add_edge(2, 3);
        g.add_edge(4, 0);
        g.add_edge(5, 1);
        g.add_edge(6, 2);
        g.add_edge(6, 3);
        System.out.println(g);
    }

    static void test2()
    {
        Graph g = new Graph( 7 ) ;
        g.add_edge(0, 5);
        g.add_edge(5, 4);
        g.add_edge(1, 2);
        g.add_edge(2, 3);
        g.add_edge(3, 6);
        g.add_edge(2, 6);
        System.out.println( reachableFrom( g , 4 ) ) ;
        System.out.println( reachableFrom( g , 6 ) ) ;
    }

    static void test3()
    {
        Graph g = new Graph( 7 ) ;
        g.add_edge(0, 5);
        g.add_edge(5, 4);
        g.add_edge(1, 2);
        g.add_edge(2, 3);
        g.add_edge(3, 6);
        g.add_edge(2, 6);

        Graph g1 = new Graph( 7 ) ;
        g1.add_edge(0, 5);
        g1.add_edge(5, 4);
        g1.add_edge(1, 2);
        g1.add_edge(2, 3);
        g1.add_edge(3, 6);
        g1.add_edge(2, 6);
        g1.add_edge(2, 5);

        System.out.println( isConnected( g  ) ) ;
        System.out.println( isConnected( g1 ) ) ;
    }

    static void test4()
    {
        Graph g = new Graph( 9 ) ;
        g.add_edge(0, 4);
        g.add_edge(1, 4);
        g.add_edge(2, 4);
        g.add_edge(4, 5);
        g.add_edge(5, 8);
        g.add_edge(7, 8);
        g.add_edge(3, 7);
        g.add_edge(6, 7);
        System.out.println( hasCycles(g) ) ; // false

        g.add_edge(4, 6);
        g.add_edge(0, 3);
        System.out.println( hasCycles(g) ) ; // true 
    }

    static void test5()
    {
        Graph g = new Graph( 10 ) ;
        g.add_edge(5, 0);
        g.add_edge(0, 1);
        g.add_edge(1, 2);
        g.add_edge(2, 3);
        g.add_edge(3, 4);
        g.add_edge(1, 7);
        g.add_edge(2, 6);
        g.add_edge(3, 9);
        g.add_edge(7, 6);
        g.add_edge(7, 8);
        System.out.println( distance(g, 7, 5) );
        System.out.println( distance(g, 7, 0) );
    }

    static ArrayList<Integer> reachableFrom(Graph g, int v) {
        // COMPLETE
        HashSet<Integer> visited = new HashSet<>() ;
        ArrayList<Integer> ans = new ArrayList<>() ;
        Stack<Integer> pending = new Stack<>() ;
        pending.push( v ) ;
        visited.add( v ) ;
        while ( !pending.isEmpty() )
        {
            int p = pending.pop() ;
            ans.add( p ) ;
            for ( int i = 0 ; i < g.size() ; i ++ )
            {
                if ( visited.contains( i ) ) continue ;
                if ( g.adjacent( p , i ) )
                {
                    visited.add( i ) ;
                    pending.add( i ) ;
                }
            }
        }

        return ans ;
    }

    static boolean isConnected( Graph g )
    {
        return reachableFrom(g, 0).size() == g.size();
    }

    static boolean hasCycles(Graph g) {
        // COMPLETE
        HashSet<Integer> visited = new HashSet<>() ;
        Stack<Integer> pending = new Stack<>() ;
        Stack<Integer> last = new Stack<>() ;

        for ( int i = 0 ; i < g.size() ; i ++ )
        {
            if ( !visited.contains( i ) )
            {
                last.push( -1 ) ;
                visited.add( i ) ;
                pending.push( i ) ;
                while ( !pending.isEmpty() )
                {
                    int now = pending.pop() ;
                    int prev = last.pop() ;
                    for ( int j = 0 ; j < g.size() ; j ++ )
                    {
                        if ( g.adjacent( now , j ) )
                        {
                            if ( !visited.contains( j ) )
                            {
                                pending.push( j ) ;
                                visited.add( j ) ;
                                last.push( now ) ;
                            }
                            else if ( j != prev ) return true ;
                        }
                    }
                }
            }
        }
        return false;
    }

    static int distance( Graph g , int v , int w )
    {
        assert reachableFrom( g , v ).contains( w ) ;
        if ( v == w ) return 0 ;
        int ans = -1 ;
        Stack<Integer> pending = new Stack<>() ;
        HashSet<Integer> visited = new HashSet<>() ;
        pending.push( v ) ;
        visited.add( v ) ;
        while ( !pending.isEmpty() )
        {
            ans ++ ;
            int p = pending.pop() ;
            visited.add( p ) ;
            for ( int i = 0 ; i < g.size() ; i ++ )
            {
                if ( visited.contains( i ) ) continue ;
                if ( g.adjacent( p , i ) )
                {
                    pending.push( i ) ;
                    visited.add( i ) ;
                }
            }
        }
        return ans ;
    }

    static ArrayList<Integer> findPath(Graph g, int v, int w) {
        // COMPLETE
        return null;
    }
}

class Graph {
    /* Methods */

    // Create a graph with n vertices numbered from 0 to n-1.
    Graph(int n) {
        this.n = n;
        this.adjacency = new ArrayList<ArrayList<Boolean>>();
        for (int i = 0; i < n; i++) {
            ArrayList<Boolean> row = new ArrayList<Boolean>();
            for (int j = 0; j < n; j++) {
                row.add(false);
            }
            this.adjacency.add(row);
        }
    }

    // Returns the number of vertices.
    int size() {
        return this.n;
    }

    // Add an adge between the vertices v and w.
    void add_edge(int v, int w) {
        // Precondition:
        assert 0 <= v && v < this.n;
        assert 0 <= w && w < this.n;
        assert v != w;
        this.adjacency.get(v).set(w, true);
        this.adjacency.get(w).set(v, true);
    }

    // Add an adge between the vertices v and w.
    boolean adjacent(int v, int w) {
        assert 0 <= v && v < this.n;
        assert 0 <= w && w < this.n;
        return this.adjacency.get(v).get(w);
    }

    @SuppressWarnings("override")
    public String toString() {
        String res = "";
        res += "vertices:";
        for (int v = 0; v < n; v++) {
            res += " " + v;
        }
        res += "\n";
        res += "edges:";
        for (int v = 0; v < n; v++) {
            for (int w = v + 1; w < n; w++) {
                if (this.adjacent(v, w)) {
                    res += " " + v + "-" + w;
                }
            }
        }
        return res;
    }

    /* Fields */
    int n;
    ArrayList<ArrayList<Boolean>> adjacency;
}
