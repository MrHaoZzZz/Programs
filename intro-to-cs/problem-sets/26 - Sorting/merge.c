#include <stdio.h>
#include <strlib.h>
#include <array.h>
#include <stdlib.h>

int main( int argc , arr( str ) argv )
{
    //Input n , m , a & b .
    int n = atoi( argv[1] ) ;
    int m = atoi( argv[2] ) ;
    arr( int ) a = build( argv+2 , n ) ;
    arr( int ) b = build( argv+2+n , m ) ;
    arr( int ) c = merge( a , n , b , m ) ;
    printa( c , n+m ) ;
    return 0 ;
}