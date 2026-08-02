#include <stdio.h>

#define MAXN 10005

int main()
{
    int n , a[MAXN] , sum = 0 ; 
    scanf( "%d" , &n ) ;
    for ( int i = 0 ; i < n ; i ++ ) // i -> index
    {
        int j = 789 ;
        scanf( "%d" , &a[i] ) ;
    }
    /*
    scanf( "%d" , &a[0] ) ;
    scanf( "%d" , &a[1] ) ;
    scanf( "%d" , &a[2] ) ;
    scanf( "%d" , &a[3] ) ;
    scanf( "%d" , &a[4] ) ;
    */
    for ( int i = 0 ; i < n ; i ++ )
    {
        sum += a[i] ;// sum = sum + a[i] ;
    }
    printf( "%d\n" , sum ) ;
    return 0 ;
}

//#define _string1 _string2
// var ++ ; ++ var ; var -- ; -- var ;
// var = var + 1 ; var = var + 1 ; var = var - 1 ; var = var - 1 ;

// let a = 5.
// b = a ++ ; // b == 5
// b = ++ a ; // b == 6

// += , -= , *= , /= , %= .

/*
input case:
5
7 6 9 2 6
output case:
30
*/