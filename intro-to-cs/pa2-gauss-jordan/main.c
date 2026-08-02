#include <stdio.h>
#include <stdlib.h>
#include <array.h>
#include <strlib.h>
#include <file.h>
#include <gaussjordan.h>

int main( int argc , arr( str ) argv )
{
    // Input the augmented matrix from file f
    file f = new_file( argv[1] ) ;
    str line = get_next_line( f ) ;
    int n = atoi( line ) ;
    if ( !n )
    {
        printf( "no unique solution\n" ) ;
        return 0 ;
    }
    arr( arr( double ) ) a = new( arr( double ) , n ) ;
    input( a , f , n ) ;

    interchange( a , n ) ;

    RREF( a , n ) ;

    if ( has_unique_solution( a , n ) )
    {
        for ( int i = 0 ; i < n ; i ++ ) printf( "%lf " , a[i][n] ) ;
        printf( "\n" ) ;
    }
    else printf( "no unique solution\n" ) ;

    return 0 ;
}