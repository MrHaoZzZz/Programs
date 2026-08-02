public class exe2
{
    public static void main(String[] args)
    {
        Node<Integer> a = new Node<>() ;
        Node<Integer> al = new Node<>() ;
        Node<Integer> am = new Node<>() ;
        Node<Integer> ar = new Node<>() ;
        Node<Integer> aml = new Node<>() ;
        a.value = 1 ;
        al.value = 2 ;
        am.value = 3 ;
        ar.value = 4 ;
        aml.value = 5 ;
        a.leftChild = al ;
        a.midChild = am ;
        a.rightChild = ar ;
        am.leftChild = aml ;
        System.out.println( sumNode( a ) ) ;
        System.out.println( a ) ;
    }

    static int sumNode( Node<Integer> tree )
    {
        if ( tree == null ) return 0 ;
        return tree.value + sumNode( tree.leftChild ) + sumNode( tree.midChild ) + sumNode( tree.rightChild ) ;
    }
}

class Node<T>
{
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

    T value ;
    Node<T> leftChild ;
    Node<T> midChild ;
    Node<T> rightChild ;
}