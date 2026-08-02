#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std ;

int main()
{
    double n , x , y ;
    int a[5] ;
    cin >> n ;
    for ( int i = 0 ; i < 3 ; i ++ )
    {
        cin >> x >> y ;
        a[i] = ceil( n / x ) * y ;
    }
    cout << min( a[0] , min( a[1] , a[2] ) ) << endl ;
    return 0 ;
}