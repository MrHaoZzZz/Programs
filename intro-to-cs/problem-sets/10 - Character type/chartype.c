#include <chartype.h>

int char_type( char c )
{
    if ( c >= 'a' && c <= 'z' ) return 0 ;
    if ( c >= 'A' && c <= 'Z' ) return 1 ;
    if ( c >= '0' && c <= '9' ) return 2 ;
    return 3 ;
}