#include <iostream>

using namespace std ;

int main()
{
    int m , n , temp , ans[10] = { 0 } ;
    cin >> m >> n ;
    for ( int i = m ; i <= n ; i ++ )
    {
        temp = i ;
        while ( temp )
        {
            ans[temp%10] ++ ;
            temp /= 10 ;
        }
    }
    for ( int i = 0 ; i < 10 ; i ++ ) cout << ans[i] << ' ' ;
    cout << endl ;
    return 0 ;
}