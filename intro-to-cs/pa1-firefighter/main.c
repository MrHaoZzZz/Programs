#include <stdio.h>
#include <stdlib.h>
#include "firefighter.h"
#include "array.h"

int main( int argc , char* argv[] )
{
    arr( char ) plan ;
    arr( char ) result ;
    int x0 , y0 , x1 , y1 ;
    arr( int ) base = new( int , 2 ) ;
    arr( int ) target = new( int , 2 ) ;
    int bat , dis ;//battery , distance

    //Input
    x0   = atoi(argv[1]);
    y0   = atoi(argv[2]);
    x1   = atoi(argv[3]);
    y1   = atoi(argv[4]);
    bat  = atoi(argv[5]);
    dis  = atoi(argv[6]);
    plan = argv[7];

    //Deal with the point: from int to arr
    base[0] = x0 ; base[1] = y0 ;
    target[0] = x1 ; target[1] = y1 ;

    result = firefighter( base , target , bat , dis , plan ) ;

    printf( "%s\n" , result ) ;

    free( result ) ;

    return 0 ;
}