#include <strlib.h>
#include <stdlib.h>

int len( str s )
{
    int l = 0 ;
    while ( s[l] != '\0' ) l ++ ;
    return l ;
}

int search( str s , char c )
{
    int l = len( s ) ;
    for ( int i = 0 ; i < l ; i ++ ) if ( s[i] == c ) return 1 ;
    return 0 ;
}

int count( str s , char c )
{
    int l = len( s ) , ans = 0 ;
    for ( int i = 0 ; i < l ; i ++ ) if ( s[i] == c ) ans ++ ;
    return ans ;
}

int abecedarian( str s )
{
    int l = len( s ) ;
    for ( int i = 1 ; i < l ; i ++ ) if ( s[i] < s[i-1] ) return 0 ;
    return 1 ;
}

int firstof( str s , char c )
{
    int l = len( s ) ;
    for ( int i = 0 ; i < l ; i ++ ) if ( s[i] == c ) return i ;
    return -1 ;
}

int lastof( str s , char c )
{
    int l = len( s ) ;
    for ( int i = l-1 ; i >= 0 ; i -- ) if ( s[i] == c ) return i ;
    return l ;
}

int equals( str s )
{
    int l = len( s ) ;
    for ( int i = 1 ; i < l ; i ++ ) if ( s[i] != s[i-1] ) return 0 ;
    return 1 ;
}

int palindrome( str s )
{
    int l = len( s ) ;
    for ( int i = 0 , j = l-1 ; i < l ; i ++ , j -- ) if ( s[i] != s[j] ) return 0 ;
    return 1 ;
}

int count_uppercase( str s )
{
    int ans = 0 , l = len( s ) ;
    for ( int i = 0 ; i < l ; i ++ ) if ( s[i] >= 'A' && s[i] <= 'Z' ) ans ++ ;
    return ans ;
}

int is_number( str s )
{
    int l = len( s ) ;
    for ( int i = 0 ; i < j ; i ++ ) if ( s[i] < '0' || s[i] > '9' ) return 0 ;
    return 1 ;
}

int to_number( str s )
{
    return atoi( s ) ;
}

int string_equals( str s1 , str s2 )
{
    int l1 = len( s1 ) , l2 = len( s2 ) ;
    if ( l1 != l2 ) return 0 ;
    for ( int i = 0 ; i < l1 ; i ++ ) if ( s1[i] != s2[i] ) return 0 ;
    return 1 ;
}