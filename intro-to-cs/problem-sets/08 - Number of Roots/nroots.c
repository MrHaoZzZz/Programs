#include <nroots.h>

int nroots( float a , float b , float c )
{
    float delta = b*b - 4*a*c ;
    if ( delta > 0 ) return 2 ;
    if ( delta == 0 ) return 1 ;
    return 0 ;
}