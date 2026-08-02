#include <iostream>
#include <algorithm>

using namespace std ;

int main()
{
    int n , a[105] ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        cin >> a[i] ;
    }
    sort( a , a+n ) ;
    cout << a[n-1] - a[0] << endl ;
    return 0 ;
}