#include <iostream>

using namespace std ;

int main()
{
    int n , m , a[3005] , minn = 300005 ;
    cin >> n >> m ;
    for ( int i = 0 ; i < n ; i ++ ) cin >> a[i] ;
    for ( int i = m-1 ; i < n ; i ++ )
    {
        int cur = 0 ;
        for ( int j = i ; j > i-m ; j -- )
        {
            cur += a[j] ;
        }
        if ( cur < minn ) minn = cur ;
    }
    cout << minn << endl ;
    return 0 ;
}