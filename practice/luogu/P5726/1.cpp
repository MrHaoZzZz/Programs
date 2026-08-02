#include <iostream>
#include <algorithm>

using namespace std ;

int main()
{
    int n , a[1005] ;
    double sum = 0 ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        cin >> a[i] ;
    }
    sort( a , a+n ) ;
    for ( int i = 1 ; i < n-1 ; i ++ )
    {
        sum += a[i] ;
    }
    printf( "%.2lf\n" , sum / ( n - 2 ) * 1.0 ) ;
    return 0 ;
}