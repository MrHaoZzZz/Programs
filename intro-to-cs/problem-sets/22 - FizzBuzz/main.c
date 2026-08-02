#include <stdio.h>
#include <stdlib.h>
#include <fizzbuzz.h>

int main( int argc , char* argv[] )
{
    int n = atoi( argv[1] ) ;
    printf( "%d\n" , fizz_buzz_case( n ) ) ;
    return 0 ;
}