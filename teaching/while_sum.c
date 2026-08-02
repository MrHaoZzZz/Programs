#include <stdio.h>

int main()
{
    int n , sum = 0 ;
    scanf( "%d" , &n ) ;
    while ( n > 0 )
    {
        int input ;
        scanf( "%d" , &input ) ;
        sum += input ;
        n -- ;
    }
    printf( "%d\n" , sum ) ;
}

// while( _condition ) -> for ( ; _condition ; )