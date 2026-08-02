#include <iostream>
#include <string>

using namespace std ;

int main()
{
    string s , a ;
    int n ;
    cin >> s ;
    n = s.size() ;
    for ( int i = 1 ; i < n ; i ++ )
    {
        cin >> a ;
        s += a ;
    }
    cout << n << ' ' ;
    if ( s[0] != '0' ) cout << 0 << ' ' ;
    int ans = 1 ;
    for ( int i = 1 ; i < n*n ; i ++ )
    {
        if ( s[i] == s[i-1] ) ans ++ ;
        else
        {
            cout << ans << ' ' ;
            ans = 1 ;
        }
    }
    cout << ans << endl ;
    return 0 ;
}