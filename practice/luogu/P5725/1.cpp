#include <iostream>

using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    for ( int i = 1 ; i <= n*n ; i ++ )
    {
        if ( i < 10 ) cout << '0' << i ;
        else cout << i ;
        if ( i % n == 0 ) cout << endl ;
    }
    cout << endl ;
    for ( int i = 1 , j = 1 ; i <= ( 1 + n ) * n / 2 ; j ++ )
    {
        for ( int k = j ; k < n ; k ++ )
        {
            cout << "  " ;
        }
        for ( int k = 0 ; k < j ; k ++ )
        {
            if ( i < 10 ) cout << '0' << i ;
            else cout << i ;
            i ++ ;
        }
        cout << endl ;
    }
    return 0 ;
}