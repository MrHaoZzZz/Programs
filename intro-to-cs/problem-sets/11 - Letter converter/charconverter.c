#include <charconverter.h>

char char_converter( char c )
{
    if ( c >= 'a' && c <= 'z' ) return c - 'a' + 'A' ;
    if ( c >= 'A' && c <= 'Z' ) return c - 'A' + 'a' ;
    return c ;
}