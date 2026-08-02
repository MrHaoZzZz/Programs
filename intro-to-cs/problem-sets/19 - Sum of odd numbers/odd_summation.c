#include <odd_summation.h>

int odd_summation( int n )
{
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; i += 2 )
    {
        ans += i ;
    }
    return ans ;
}