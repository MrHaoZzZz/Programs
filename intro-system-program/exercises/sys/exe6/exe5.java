import java.util.ArrayList ;
import java.util.LinkedList ;
import java.util.Queue ;

public class exe5
{
    public static void main(String[] args) {
        Node<Integer> a = new Node<>() ;
        Node<Integer> al = new Node<>() ;
        Node<Integer> ar = new Node<>() ;
        Node<Integer> all = new Node<>() ;
        Node<Integer> alr = new Node<>() ;
        Node<Integer> arl = new Node<>() ;
        Node<Integer> arr = new Node<>() ;
        a.value = 1 ;
        al.value = 2 ;
        ar.value = 4 ;
        all.value = 5 ;
        alr.value = 6 ;
        arl.value = 7 ;
        arr.value = 8 ;
        
        a.leftChild = al ;
        a.rightChild = ar ;
        al.leftChild = all ;
        al.rightChild = alr ;
        ar.leftChild = arl ;
        ar.rightChild = arr ;

        System.out.println( a ) ;
        ArrayList<Integer> e = new ArrayList<>() ;
        e.add( 10 ) ;
        e.add( 20 ) ;
        e.add( 30 ) ;
        e.add( 40 ) ;
        System.out.println( buildBalancdeTree(e) ) ;
    }

    static <T> Node<T> buildBalancdeTree( ArrayList<T> element )
    {
        if ( element.isEmpty() ) return null ;
        Node<T> root = new Node<>() ;
        root.value = element.get(0) ;
        Queue<Node<T>> pending = new LinkedList<>() ;
        pending.add( root ) ;
        for ( int level = 1 ; level < element.size() ; level ++ )
        {
            int parentsAmount = pending.size() ;
            for ( int i = 0 ; i < parentsAmount ; i ++ )
            {
                Node<T> parent = pending.poll() ;

                Node<T> l = new Node<>() ;
                Node<T> r = new Node<>() ;

                l.value = element.get(level) ;
                r.value = element.get(level) ;

                parent.leftChild = l ;
                parent.rightChild = r ;

                pending.add( l ) ;
                pending.add( r ) ;
            }
        }
        return root ;
        
        /*
        if ( element.isEmpty() ) return null ;
        ArrayList<T> newElement = new ArrayList<>() ;
        for ( int i = 1 ; i < element.size() ; i ++ ) newElement.add( element.get(i) ) ;
        Node<T> tree = new Node<>() ;
        tree.value = element.get( 0 ) ;
        tree.leftChild = buildBalancdeTree( newElement ) ;
        tree.rightChild = buildBalancdeTree( newElement ) ;
        return tree ;
        */
    }
}

class Node<T> {
    @Override
    public String toString()
    {
        StringBuilder sb = new StringBuilder() ;
        buildString( sb , "" , "" , this ) ;
        return sb.toString() ;
    }

    private void buildString( StringBuilder sb , String prefix , String childrenPrefix , Node<T> node )
    {
        sb.append( prefix ) ;
        sb.append( node.value ) ;
        sb.append('\n');
        if ( node.leftChild != null )
        {
            if ( node.rightChild != null )
                buildString( sb , childrenPrefix + "├── " , childrenPrefix + "│   " , node.leftChild ) ;
            else
                buildString( sb , childrenPrefix + "└── " , childrenPrefix + "    " , node.leftChild ) ;
        }

        if ( node.rightChild != null )
            buildString( sb , childrenPrefix + "└── " , childrenPrefix + "    " , node.rightChild ) ;
    }

    T value;
    Node<T> leftChild;
    Node<T> rightChild;
}