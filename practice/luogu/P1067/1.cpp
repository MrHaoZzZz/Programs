#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    int n , coe[105] ;
    cin >> n ;
    for ( int i = n ; i >= 0  ; i -- ) cin >> coe[i] ;
    if ( n == 0 )
    {
        cout << coe[0] << endl ;
        return 0 ;
    }
    if ( coe[n] == 1 ) cout << "x^" << n ;
    else if ( coe[n] == -1 ) cout << "-x^" << n ;
    else if ( coe[n] > 1 ) cout << coe[n] << "x^" << n ;
    else if ( coe[n] < -1 ) cout << coe[n] << "x^" << n ;
    for ( int i = n-1 ; i > 0 ; i -- )
    {
        if ( coe[i] > 0 ) cout << '+' ;
        else if ( coe[i] < 0 ) cout << '-' ;
        else continue ;
        if ( coe[i] != 1 && coe[i] != -1 ) cout << abs( coe[i] ) ;
        if ( i == 1 ) cout << "x" ;
        else cout << "x^" << i ;
    }
    if ( coe[0] > 0 ) cout << '+' << coe[0] ;
    else if ( coe[0] < 0 ) cout << coe[0] ;
    cout << endl ;
    return 0 ;
}