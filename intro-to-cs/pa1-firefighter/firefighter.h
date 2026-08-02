#include "array.h"

//Simplize the operation
#ifndef FIREFIGHTER_H
#define FIREFIGHTER_H

#define back do { dir = pre_dir ; pos[0] = pre_pos[0] ; pos[1] = pre_pos[1] ; bat_used -- ; } while(0)
#define execute( command , direction , position ) do { \
    if ( ( command ) == 'L' ) ( direction ) = ( ( direction ) + 3 ) % 4 ; \
    if ( ( command ) == 'R' ) ( direction ) = ( ( direction ) + 1 ) % 4 ; \
    if ( ( command ) == 'S' ) \
    { \
        int row[4] = { 0 , 1 , 0 , -1 } ; \
        int col[4] = { 1 , 0 , -1 , 0 } ; \
        ( position )[0] += row[( direction )] ; \
        ( position )[1] += col[( direction )] ; \
    } \
} while( 0 )

#endif

//To cliam the functions
int is_in_radius( int dis , int x , int y ) ;
int is_arrive( int x0 , int y0 , int x1 , int y1 ) ;
int get_length( arr( char ) string ) ;
arr( char ) reverse( arr( char ) path ) ;
arr( char ) firefighter( int base[2] , int tar[2] , int bat , int dis , arr( char ) plan ) ;