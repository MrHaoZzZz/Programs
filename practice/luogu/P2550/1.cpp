#include <iostream>
#include <algorithm>

using namespace std ;

int main()
{
    int n , ans[8] = { 0 } , a[7] , b[7] ;
    cin >> n ;
    for ( int i = 0 ; i < 7 ; i ++ )
    {
        cin >> a[i] ;
    }
    sort( a , a+7 ) ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        for ( int j = 0 ; j < 7 ; j ++ )
        {
            cin >> b[j] ;
        }
        sort( b , b+7 ) ;
        int cnt = 0 ;
        for ( int j = 0 ; j < 7 ; j ++ )
        {
            for ( int k = 0 ; k < 7 ; k ++ )
            {
                if ( a[j] == b[k] )
                {
                    cnt ++ ;
                }
            }
        }
        ans[cnt] ++ ;
    }
    for ( int i = 7 ; i > 0 ; i -- )
    {
        cout << ans[i] << ' ' ;
    }
    cout << endl ;
    return 0 ;
}