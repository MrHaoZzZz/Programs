#include <factorial.h>

int factorial( int num )
{
    int ans = 1 ;
    for ( int i = 1 ; i <= num ; i ++ ) ans *= i ;
    return ans ;
}