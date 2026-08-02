import java.util.ArrayList ;
import java.util.Arrays;
import java.util.HashSet ;
import java.util.LinkedList;
import java.util.List ;
import java.util.Queue ;
import java.util.Stack ;

public class search
{
    static void main( String[] args )
    {
        Vertex a = new Vertex() ;
        Vertex b = new Vertex() ;
        Vertex c = new Vertex() ;
        Vertex d = new Vertex() ;

        a.addPath( b ) ;
        b.addPath( c ) ;
        b.addPath( d ) ;
        c.addPath( b ) ;
        d.addPath( a ) ;

        Graph graph = new Graph( 4 ) ;
        graph.addEdge( 0 , 1 ) ;
        graph.addEdge( 1 , 2 ) ;
        graph.addEdge( 1 , 3 ) ;
        graph.addEdge( 3 , 0 ) ;

        System.out.println( a.reachBFS( a , d ) ) ;

        graph.DFS_recursion( 0 ) ;

    }
}

// Lecture
class Vertex
{
    public Vertex()
    {
        this.neighbors = new ArrayList<>() ;
    }

    public void addPath( Vertex w )
    {
        this.neighbors.add( w ) ;
    }

    // v -> now visiting
    // w -> target vertex
    // u -> next visiting vertex which is neighbors of v
    public boolean reachDFS_recursion( Vertex v , Vertex w , HashSet<Vertex> visited )
    {
        if ( v.equals( w ) ) return true ;
        if ( visited.contains( v ) ) return false ;
        // maintaining a set visited to avoid searching repeatedly
        visited.add( v ) ;

        for ( Vertex u : v.neighbors )
        {
            if ( reachDFS_recursion( u , w , visited ) ) return true ;
        }

        return false ;
    }

    // since recursion is exactly using stack of system, we can use stack by ourselves
    public boolean reachDFS_stack( Vertex v , Vertex w )
    {
        HashSet<Vertex> visited = new HashSet<>() ;
        Stack<Vertex> pending = new Stack<>() ;

        pending.add( v ) ;

        while ( !pending.empty() )
        {
            Vertex x = pending.pop() ;

            if ( x.equals( w ) ) return true ;
            if ( visited.contains( x ) ) continue ;

            visited.add( x ) ;

            for ( Vertex y : x.neighbors ) pending.add( y ) ;
        }
        return false ;
    }
    
    // replace stack in reachBFS_stack() to queue, but the search order is completely different
    public boolean reachBFS( Vertex v , Vertex w )
    {
        HashSet<Vertex> visited = new HashSet<>() ;
        Queue<Vertex> pending = new LinkedList<>() ;

        pending.add( v ) ;

        while ( !pending.isEmpty() )
        {
            Vertex x = pending.poll() ;

            if ( x.equals( w ) ) return true ;
            if ( visited.contains( x ) ) return false ;

            visited.add( x ) ;

            for ( Vertex y : x.neighbors ) pending.add( y ) ;
        }

        return false ;
    }

    @SuppressWarnings("FieldMayBeFinal")
    private ArrayList<Vertex> neighbors ;
}

// Tutorial
class Graph
{
    public Graph( int vertices )
    {
        this.vertices = vertices ;
        adjacency = new ArrayList<>( vertices ) ;
        for ( int i = 0 ; i < vertices ; i ++ ) adjacency.add( new LinkedList<>() ) ;
    }

    public void addEdge( int u , int v )
    {
        adjacency.get( u ).add( v ) ;
        adjacency.get( v ).add( u ) ;
    }

    public void DFS_recursion( int start )
    {
        boolean visited[] = new boolean[vertices] ;

        DFS_helper( start , visited ) ;
    }

    private void DFS_helper( int v , boolean[] visited )
    {
        visited[v] = true ;
        System.out.println( v + " " ) ;
        for ( int neighbor : adjacency.get( v ) )
        {
            if ( !visited[neighbor] ) DFS_helper( neighbor , visited ) ;
        }
    }

    public int shortestPath_BFS( int start , int end )
    {
        int[] distance = new int[vertices] ;
        Arrays.fill( distance , -1 ) ;
        Queue<Integer> queue = new LinkedList<>() ;

        distance[start] = 0 ;

        queue.add( start ) ;
        
        while( !queue.isEmpty() )
        {
            int v = queue.poll() ;
            for ( int n : adjacency.get( v ) )
            {
                if ( distance[n] == -1 )
                {
                    distance[n] = distance[v] + 1 ; // last distance + 1(or distance)
                    if ( n == end ) return distance[n] ;
                }
            }
        }

        return -1 ;
    }

    private final int vertices ;
    private final List<List<Integer>> adjacency ;
}