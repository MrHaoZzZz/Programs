#include <iostream>

using namespace std ;

/*
TLE solution
int fib( int n )
{
    if ( n == 1 || n == 2 ) return 1 ;
    return fib( n - 1 ) + fib( n - 2 ) ;
}
*/

int main()
{
    long long n , fib[50] ;
    fib[0] = 0 ; fib[1] = 1 ; fib[2] = 1 ;
    cin >> n ;
    for ( int i = 3 ; i <= n ; i ++ )
    {
        fib[i] = fib[i-1] + fib[i-2] ;
    }
    cout << fib[n] << ".00" << endl ;
    return 0 ;
}