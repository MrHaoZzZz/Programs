#include <iostream>

using namespace std ;

int main()
{
    int n , cnt = 0 ;
    char s[105] ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ ) cin >> s[i] ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        if ( s[i] == 'V' && s[i+1] == 'K' ) cnt ++ ;
    }
    if ( s[1] == 'K' && s[0] != 'V' )
    {
        cout << cnt + 1 << endl ;
        return 0 ;
    }
    for ( int i = 1 ; i < n ; i ++ )
    {
        if ( s[ i + 1 ] == 'K' && s[ i - 1 ] != 'V' && s[i] != 'V' )
        {
            cnt ++ ;
            break ;
        }
        if ( s[ i - 1 ] == 'V' && s[ i + 1 ] != 'K' && s[i] != 'K' )
        {
            cnt ++ ;
            break ;
        }
    }
    cout << cnt << endl ;
    return 0 ;
}