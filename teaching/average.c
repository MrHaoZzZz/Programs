//provide n(0<n<=10000) integers, print their average (round down to integer)
//input format:
//the first line: an integer n
//the second line: n integers splited by white space
//output format: 
//an integer representing the average
/*
#include<stdio.h>

#define MAXN 10000
int main()
{
    int n , a[MAXN] , sum=0;
    scanf("%d" , &n );
    for (int i , i < n, i ++ )
    {
        scanf("%d" , &a[i])
    }
    for (int i , i < n , i ++ )
    {
        sum += a[i] ;
    }
    scanf("%d" , &sum );
    prinf("%d\n" , sum/n)
    return 0;
}
*/
#include <stdio.h>

#define MAXN 10005

int main()
{
    int n , sum = 0 ;
    scanf( "%d" , &n ) ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        int input ;
        scanf( "%d" , &input ) ;
        sum += input ;
    }
    printf( "%d\n" , sum / n ) ;
    return 0 ;
}