#include <gaussjordan.h>
#include <stdlib.h>
#include <strlib.h>
#include <file.h>
#include <array.h>

// To slice a string from index i to j-1
str slice( str sentence , int i , int j )
{
    str result = new( char , j - i + 1 ) ;
    for ( int k = i ; k < j ; k ++ )
    {
        result[k - i] = sentence[k] ;
    }
    result[j - i] = '\0' ;
    return result ;
}

// To split a string by space
arr( str ) split( str sentence )
{
    int length = len( sentence ) ;
    int count = 1 ;
    for ( int i = 0 ; i < length ; i ++ )
    {
        if ( sentence[i] == ' ' ) count ++ ;
    }

    arr( str ) result = new( str , count ) ;
    int l = 0 , r = -1 ;
    for ( int i = 0 ; i < count ; i ++ )
    {
        l = r + 1 ;
        r = search( sentence , l , ' ' ) ;
        result[i] = slice( sentence , l , r ) ;
    }
    return result ;
}

// To input the augmented matrix from file f
void input( arr( arr( double ) ) a , file f , int n )
{
    str line ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        a[i] = new( double , n+1 ) ;
        line = get_next_line( f ) ;
        arr( str ) tokens = split( line ) ;
        for ( int j = 0 ; j < n + 1 ; j ++ )
        {
            a[i][j] = atof( tokens[j] ) ;
        }
    }
}

// To interchange rows to avoid zero pivot elements
void interchange( arr( arr( double ) ) a , int n )
{
    for ( int i = 0 ; i < n - 1 ; i ++ )
    {
        int found = 0 ;
        if ( !a[i][i] )
        {
            for ( int j = i + 1 ; j < n ; j ++ )
            {
                if ( a[j][i] )
                {
                    // interchange row i and row j
                    arr( double ) temp = a[i] ;
                    a[i] = a[j] ;
                    a[j] = temp ;
                }
                found = 1 ;
                break ;
            }
        }
        if ( found ) break ;
        else continue ;// no non-zero pivot element found in this column
    }
}

// To calculate the rank of the matrix
int rank( arr( arr( double ) ) a , int n )
{
    int rank = n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        int all_zero = 1 ;
        for ( int j = 0 ; j < n ; j ++ )
        {
            if ( a[i][j] != 0 )
            {
                all_zero = 0 ;
            }
        }
        if ( all_zero ) rank -- ;
    }
    return rank ;
}

// To check if the matrix has a unique solution
int has_unique_solution( arr( arr( double ) ) a , int n )
{
    int r = rank( a , n ) ;
    if ( r < n ) return 0 ;
    else return 1 ;
}

// To convert the matrix to REF(Row Echelon Form)
void REF( arr( arr( double ) ) a , int n )
{
    for ( int i = 0 ; i < n ; i ++ )
    {
        double pivot = a[i][i] ;
        if ( pivot )
        {
            for ( int j = i ; j < n + 1 ; j ++ )
            {
                a[i][j] /= pivot ;
            }
            for ( int j = i + 1 ; j < n ; j ++ )
            {
                double factor = a[j][i] ;
                for ( int k = i ; k < n + 1 ; k ++ )
                {
                    a[j][k] -= factor * a[i][k] ;
                }
            }
        }
    }
}

// To convert the matrix to RREF(Reduced Row Echelon Form)
void RREF( arr( arr( double ) ) a , int n )
{
    REF( a , n ) ;
    for ( int i = n - 1 ; i >= 0 ; i -- )
    {
        for ( int j = i - 1 ; j >= 0 ; j -- )
        {
            double factor = a[j][i] ;
            for ( int k = n ; k >= i ; k -- )
            {
                a[j][k] -= factor * a[i][k] ;
            }
        }
    }
}