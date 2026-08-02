#include <iostream>
#include <algorithm>

using namespace std ;

int main()
{
    int n , ans = 0 , a[105] , flag[20005] = { 0 } ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        cin >> a[i] ;
        flag[a[i]] = 1 ;
    }
    sort( a , a+n ) ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        for ( int j = i + 1 ; j < n ; j ++ )
        {
            if ( flag[ a[i] + a[j] ] )
            {
                ans ++ ;
                flag[ a[i] + a[j] ] = 0 ;
            }
        }
    }
    cout << ans << endl ;
    return 0 ;
}