#include <stdio.h>

int a[1005] ;

int max( int n )
{
    if ( n == 2 )
    {
        if ( a[0] > a[1] ) return a[0] ;
        else return a[1] ;
    }
    int tempmax = max( n - 1 ) ;
    if ( tempmax > a[n - 1] ) return tempmax ;
    else return a[n - 1] ;
}

int main()
{
    int n ;
    scanf( "%d" , &n ) ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        scanf( "%d" , &a[i] ) ;
    }
    printf( "%d\n" , max( n ) ) ;
    return 0 ;
}

// 5
// 1 2 3 4 5 ;