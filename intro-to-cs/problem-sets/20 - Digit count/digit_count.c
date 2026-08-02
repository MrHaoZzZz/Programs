#include <digit_count.h>

int digit_count( int n )
{
    int ans = 0 ;
    n = n > 0 ? n : -n ;
    while ( n > 0 )
    {
        ans ++ ;
        n /= 10 ;
    }
    return ans ;
}