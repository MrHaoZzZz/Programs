#include <iostream>
#include <algorithm>

using namespace std ;

int gcd( int a , int b )
{
    if ( a % b == 0 ) return b ;
    return gcd( b , a % b ) ;
}

int main()
{
    int a[3] ;
    cin >> a[0] >> a[1] >> a[2] ;
    sort( a , a+3 ) ;
    int d = gcd( a[0] , a[2] ) ;
    //cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl ;
    cout << a[0] / d << '/' << a[2] / d << endl ;
    return 0 ;
}