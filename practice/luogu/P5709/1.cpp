#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    double m , s , t ;
    cin >> m >> t >> s ;
    if ( t == 0 )
    {
        cout << 0 << endl ;
        return 0 ;
    }
    int eat = ceil( s/t*1.0 ) ;
    //cout << eat << endl ;
    if ( m - eat < 0 ) cout << 0 << endl ;
    else cout << m - eat << endl ;
    return 0 ;
}