#include <stdio.h>
#include <stdlib.h>
#include <strlib.h>

int main( int argc, char* argv[] )
{
    char* sentence = argv[1] ;
    char  letter   = argv[2][0] ;

    printf( "%d\n" , count( sentence , letter ) ) ;

    return 0 ;
}