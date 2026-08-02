#include <stdio.h>

int distance( int x1 , int y1 , int x2 , int y2 )
{
    return ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) ;
}

int main()
{
    int n ;
    scanf( "%d" , &n ) ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        int x1 , y1 , x2 , y2 ;
        scanf( "%d%d%d%d" , &x1 , &y1 , &x2 , &y2 ) ;
        printf( "%d\n" , distance( x1 , y1 , x2 , y2 ) ) ;
    }
    return 0 ;
}