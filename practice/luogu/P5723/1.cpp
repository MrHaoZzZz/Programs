#include <iostream>
#include <cstring>

using namespace std ;

bool prime[100005] ;

void pick_prime()
{
    for ( int i = 2 ; i < 100000 ; i ++ )
    {
        if ( prime[i] ) for ( int j = i * 2 ; j < 100000 ; j += i ) prime[j] = false ;
    }
    return ;
}

int main()
{
    memset( prime , true , sizeof( prime ) ) ;
    prime[0] = false ;
    prime[1] = false ;
    pick_prime() ;
    int l , ans = 0 , n ;
    cin >> l ;
    n = l ;
    for ( int i = 2 ; i <= n ; i ++ )
    {
        if ( prime[i] )
        {
            cout << i << endl ;
            ans ++ ;
            n -= i ;
        }
    }
    cout << ans << endl ;
}