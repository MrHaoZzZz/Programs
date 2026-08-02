#include <fizzbuzz.h>

int fizz_buzz_case( int n )
{
    if ( n % 3 == 0 && n % 5 == 0 ) return 3 ;
    if ( n % 5 == 0 ) return 2 ;
    if ( n % 3 == 0 ) return 1 ;
    return 0 ;
}