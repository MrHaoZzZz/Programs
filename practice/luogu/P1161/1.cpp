#include <iostream>

using namespace std ;

int main()
{
    int n , light[2000005] = {0} , cnt = 0 ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        double a ;
        int t ;
        cin >> a >> t ;
        for ( int j = 1 ; j <= t ; j ++ )
        {
            int k = ( int ) ( a * j ) ;
            light[k] ^= 1 ;
        }
    }
    for ( int i = 1 ; i <= 2000000 ; i ++ )
    {
        if ( light[i] )
        {
            cout << i << endl ;
            break ;
        }
    }
    return 0 ;
}