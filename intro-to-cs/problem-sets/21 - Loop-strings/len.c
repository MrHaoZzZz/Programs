#include <stdio.h>
#include <stdlib.h>
#include <strlib.h>

int main( int argc , char* argv[] )
{
    char* string = argv[1] ;

    printf( "%d\n" , len( string ) ) ;

    return 0;
}