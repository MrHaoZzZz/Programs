#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "firefighter.h"

int is_in_radius( int dis , int x , int y )
{
    //Pythagoras' theorem
    return dis*dis >= x*x + y*y ;
}

int is_arrive( int x0 , int y0 , int x1 , int y1 )
{
    return x0 == x1 && y0 == y1 ;
}

int get_length( arr( char ) string )
{
    int length = 0 ;
    while ( string[length] != '\0' ) length ++ ;
    return length ;
}

arr( char ) reverse( arr( char ) path )
{
    int len = get_length( path ) ;
    arr( char ) reversed = new( char , len + 1 ) ;

    for ( int i = 0 ; i < len ; i ++ )
    {
        char origin = path[len-i-1] ;
        //Reverse the path
        if ( origin == 'L' ) reversed[i] = 'R' ;
        else if ( origin == 'R' ) reversed[i] = 'L' ;
        else reversed[i] = origin ;
    }

    reversed[len] = '\0' ;
    return reversed ;
}

arr( char ) firefighter( int base[2] , int tar[2] , int bat , int dis , arr( char ) plan )
{
    //To get the length of plan
    int len = get_length( plan ) ;
    //Cliam a variable of the direction , and is initially towards North
    //For the convinient of processing, we define :
    //0 -> N ; 1 -> E ; 2 -> S ; 3 -> W
    int dir = 0 ;
    //Cliam a variable of the position
    int pos[2] = { base[0] , base[1] } ;
    //To record the battery used
    int bat_used = 0 ;
    //To record if mission success
    int reach = 0 , success = 0 ;
    //To store the prefix
    arr( char ) prefix = new( char , len + 1 ) ;
    int prefix_len = 0 ;

    for ( int i = 0 ; i < len ; i ++ )
    {
        //To save the previous state so that is convinient to return backwards
        int pre_dir = dir , pre_pos[2] = { pos[0] , pos[1] } ;

        //To execute the command
        //The symbol '&' is for sync the change in function execute() to this function
        execute( plan[i] , dir , pos ) ;
        bat_used ++ ;

        //Judge if the drone is beyond the raduis
        if ( !is_in_radius( dis , pos[0] , pos[1] ) )
        {
            //Go back
            back ;
            //Quit the loop
            i = len ;
        }
        //Judge if there is enough battery to return the base
        else if ( bat_used*2 + 2 > bat )
        {
            //Go back
            back ;
            //Quit the loop
            i = len ;
        }
        else
        {
            //Store the prefix
            prefix[prefix_len] = plan[i] ;
            prefix_len ++ ;
            prefix[prefix_len] = '\0' ;
        }
    }

    //To judge if the mission success
    if ( is_arrive( pos[0] , pos[1] , tar[0] , tar[1] ) )
    {
        if ( bat_used*2 + 2 <= bat && is_in_radius( dis , pos[0] , pos[1] ) )
        {
            //Mission success
            success = 1 ;
        }
    }

    //Cliam the variable of result
    char first ;
    arr( char ) second ;
    arr( char ) third ;

    //Build the parts of answer
    if ( success )
    {
        //0
        first = '0' ;
        //plan
        second = plan ;
        //return
        third = reverse( plan ) ;
    }
    else
    {
        //1
        first = '1' ;
        //prefix
        prefix[prefix_len] = '\0' ;
        second = prefix ;
        //return
        third = reverse( prefix ) ;
    }

    //To get the string length of the different parts of the final answer
    int len2 = get_length( second ) , len3 = get_length( third ) ;
    //To get the total length of answer
    int len_tot = 1 + 1 + len2 + 1 + 2 + len3 + 1 ;
    //Allocate memory for the variable result
    arr( char ) result = new( char , len_tot ) ;
    //Writing the final answer
    result[0] = first ;
    result[1] = '.' ;
    for ( int i = 0 ; i < len2 ; i ++ )
    {
        result[i+2] = second[i] ;
    }
    result[len2+2] = '.' ;
    //Turn around
    result[len2+3] = 'R' ;
    result[len2+4] = 'R' ;
    for ( int i = 0 ; i < len3 ; i ++ )
    {
        result[i+len2+5] = third[i] ;
    }
    result[len_tot-1] = '\0' ;

    //Free the allocated memory
    free( third ) ;
    free( prefix ) ;

    //All has done
    return result ;
}