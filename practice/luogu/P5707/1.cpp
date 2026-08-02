#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    double s , v ;
    int t , tot = 24*60 + 8*60 , rest ;
    cin >> s >> v ;
    t = ceil( s / v ) + 10 ;
    rest = tot - t ;
    if ( rest >= 24 * 60 ) rest -= 24 * 60 ;
    int h , min ;
    h = rest / 60 ;
    min = rest % 60 ;
    if ( h < 10 )
    {
        cout << '0' << h << ':' ;
        if ( min < 10 ) cout << '0' << min << endl ;
        else cout << min << endl ;
    }
    else
    {
        cout << h << ':' ;
        if ( min < 10 ) cout << '0' << min << endl ;
        else cout << min << endl ;
    }
    return 0 ;
}