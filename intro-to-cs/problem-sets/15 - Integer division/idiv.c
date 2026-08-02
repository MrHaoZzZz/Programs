#include <idiv.h>

int idiv( int n , int d )
{
    int ans = 0 ;
    while ( n >= d )
    {
        ans ++ ;
        n -= d ;
    }
    return ans ;
}