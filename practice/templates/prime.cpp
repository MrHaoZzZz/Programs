#include <iostream>

using namespace std ;

int prime[100005] ;

bool is_prime( int n )
{
    if ( n == 1 ) return false ;
    if ( n == 2 ) return true ;
    if ( n % 2 == 0 ) return false ;
    for ( int i = 3 ; i*i <= n ; i += 2 )
    {
        if ( n % i == 0 ) return false ;
    }
    return true ;
}

int find_first_n_prime( int n )
{
    ;
}

int main()
{
    return 0 ;
}