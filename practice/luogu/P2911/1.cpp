#include <iostream>
#include <algorithm>

using namespace std ;

int main()
{
    int a , b , c , cnt[85] = { 0 } , maxs = 0 , ans , maxc = 0 ;
    cin >> a >> b >> c ;
    for ( int i = 1 ; i <= a ; i ++ )
    {
        for ( int j = 1 ; j <= b ; j ++ )
        {
            for ( int k = 1 ; k <= c ; k ++ )
            {
                cnt[ i + j + k ] ++ ;
                maxs = max( maxs , i + j + k ) ;
            }
        }
    }

    for ( int i = 1 ; i <= maxs ; i ++ )
    {
        if ( maxc < cnt[i] )
        {
            maxc = cnt[i] ;
            ans = i ;
        }
    }

    cout << ans << endl ;
    return 0 ;
}