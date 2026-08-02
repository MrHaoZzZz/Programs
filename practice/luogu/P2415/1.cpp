#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    int cnt = 0 ;
    int s[35] ;
    unsigned long long ans = 0 ;
    while ( cin >> s[ cnt ++ ] ) ;
    for ( int i = 0 ; i < cnt ; i ++ )
    {
        ans += s[i] ;
    }
    cout << ( unsigned long long ) ( ans * pow( 2 , cnt - 2 ) ) << endl ;
    return 0 ;
}