#include <stdio.h>
#include <stdlib.h>
#include "image_processing.h"

// core functions
unsigned char *grayscale( unsigned char *pixels , int width , int height , int channels )
{
    // allocate memory for output
    unsigned char *output = malloc( width * height * channels * sizeof( unsigned char ) ) ;
    for ( int i = 0 ; i < height ; i ++ )
    {
        for ( int j = 0 ; j < width ; j ++ )
        {
            // the index of the first channel of the currently enumerated pixel
            int k = ( i * width + j ) * channels ;
            unsigned char r = pixels[k] ;     // the first  channel
            unsigned char g = pixels[k + 1] ; // the second channel
            unsigned char b = pixels[k + 2] ; // the third  channel
            // calculate the grayscale value by the formula
            unsigned char gray = ( unsigned char )( 0.299 * r + 0.587 * g + 0.114 * b ) ;
            // write the value to the output image
            output[k] = gray ;
            output[k + 1] = gray ;
            output[k + 2] = gray ;
        }
    }
    return output ;
}

unsigned char *flip_horizontal( unsigned char *pixels , int width , int height , int channels )
{
    unsigned char *output = malloc( width * height * channels * sizeof( unsigned char ) ) ;
    for ( int i = 0 ; i < height ; i ++ )
    {
        for ( int j = 0 ; j < width ; j ++ )
        {
            int k = ( i * width + j ) * channels ;
            // the index of current pixel after flipped
            int k_flip = ( i * width + ( width - 1 - j ) ) * channels ;
            output[k] = pixels[k_flip] ;
            output[k + 1] = pixels[k_flip + 1] ;
            output[k + 2] = pixels[k_flip + 2] ;
        }
    }
    return output ;
}

unsigned char *flip_vertical( unsigned char *pixels , int width , int height , int channels )
{
    unsigned char *output = malloc( width * height * channels * sizeof( unsigned char ) ) ;
    for ( int i = 0 ; i < height ; i ++ )
    {
        for ( int j = 0 ; j < width ; j ++ )
        {
            int k = ( i * width + j ) * channels ;
            int k_flip = ( ( height - 1 - i ) * width + j ) * channels ;
            output[k] = pixels[k_flip] ;
            output[k + 1] = pixels[k_flip + 1] ;
            output[k + 2] = pixels[k_flip + 2] ;
        }
    }
    return output ;
}

unsigned char *rotate( unsigned char *pixels , int width , int height , int channels , int degree )
{
    // width and height should be swapped if degree is 90 or 270 ( % 360 )
    int new_width = width , new_height = height ;
    degree = ( degree + 360 ) % 360 ;
    if ( degree == 90 || degree == 270 )
    {
        new_width = height ;
        new_height = width ;
    }
    unsigned char *output = malloc( new_width * new_width * channels * sizeof( unsigned char ) ) ;
    for ( int i = 0 ; i < height ; i ++ )
    {
        for ( int j = 0 ; j < width ; j ++ )
        {
            int k = ( i * width + j ) * channels ;
            int k_rotated = k ;
            if ( degree == 90 ) k_rotated = ( j * new_width + ( new_width - 1 - i ) ) * channels ;
            else if ( degree == 180 ) k_rotated = ( ( new_height - 1 - i ) * new_width + ( new_width - 1 - j ) ) * channels ;
            else if ( degree == 270 ) k_rotated = ( ( new_height - 1 - j ) * new_width + i ) * channels ;
            else if ( degree == 0 ) k_rotated = k ;
            else // not 0, 90, -90, 180, -180, 270, -270
            {
                printf( "Unsupported degree.\n" ) ;
                return NULL ; // for terminate the program in main function
            }
            output[k_rotated] = pixels[k] ;
            output[k_rotated + 1] = pixels[k + 1] ;
            output[k_rotated + 2] = pixels[k + 2] ;
        }
    }
    return output ;
}

unsigned char *blur( unsigned char *pixels , int width , int height , int channels )
{
    // 3*3 box blur
    // avarage each channel independently
    // do not access out of bound pixels
    // integer arithmetic only
    unsigned char *output = malloc( width * height * channels * sizeof( unsigned char ) ) ;
    for ( int i = 0 ; i < height ; i ++ )
    {
        for ( int j = 0 ; j < width ; j ++ )
        {
            int k = ( i * width + j ) * channels ;
            int di[9] = { -1 , -1 , -1 , 0 , 0 , 0 , 1 , 1 , 1 } ;
            int dj[9] = { -1 , 0 , 1 , -1 , 0 , 1 , -1 , 0 , 1 } ;
            int r = 0 , g = 0 , b = 0 , count = 0 ;
            // enumerate all pixels in the 3*3 box
            for ( int l = 0 ; l < 9 ; l ++ )
            {
                int new_i = i + di[l] , new_j = j + dj[l] ;
                int new_k = ( new_i * width + new_j ) * channels ;
                if ( new_i >= 0 && new_i < height && new_j >= 0 && new_j < width )
                {
                    r += pixels[new_k] ;
                    g += pixels[new_k + 1] ;
                    b += pixels[new_k + 2] ;
                    count ++ ;
                }
            }
            output[k]     = ( unsigned char ) ( r / count ) ;
            output[k + 1] = ( unsigned char ) ( g / count ) ;
            output[k + 2] = ( unsigned char ) ( b / count ) ;
        }
    }
    return output ;
}

unsigned char *crop( unsigned char *pixels , int width , int height , int channels , int x , int y , int crop_width , int crop_height )
{
    unsigned char *output = malloc( crop_width * crop_height * channels * sizeof( unsigned char ) ) ;
    for ( int i = 0 ; i < crop_height ; i ++ )
    {
        for ( int j = 0 ; j < crop_width ; j ++ )
        {
            int k_pixels = ( ( x + i ) * width + y + j ) * channels ; 
            int k_output = ( i * crop_width + j ) * channels ;
            output[k_output] = pixels[k_pixels] ;
            output[k_output + 1] = pixels[k_pixels + 1] ;
            output[k_output + 2] = pixels[k_pixels + 2] ;
        }
    }
    return output ;
}

// additional functions ( in assignment description )
unsigned char *threshold( unsigned char *pixels , int width , int height , int channels , int thres )
{
    unsigned char *output = malloc( width * height * channels * sizeof( unsigned char ) ) ;
    unsigned char *gray   = malloc( width * height * channels * sizeof( unsigned char ) ) ;

    gray = grayscale( pixels , width , height , channels ) ;

    for ( int i = 0 ; i < height ; i ++ )
    {
        for ( int j = 0 ; j < width ; j ++ )
        {
            int k = ( i * width + j ) * channels ;
            if ( gray[k] >= thres )
            {
                output[k]     = 255 ;
                output[k + 1] = 255 ;
                output[k + 2] = 255 ;
            }
            else
            {
                output[k]     = 0 ;
                output[k + 1] = 0 ;
                output[k + 2] = 0 ;
            }
        }
    }
    return output ;
}

unsigned char *bright( unsigned char *pixels , int width , int height , int channels , int delta )
{
    unsigned char *output = malloc( width * height * channels * sizeof( unsigned char ) ) ;
    for ( int i = 0 ; i < height ; i ++ )
    {
        for ( int j = 0 ; j < width ; j ++ )
        {
            int k = ( i * width + j ) * channels ;
            output[k]     = clamp( pixels[k]     + delta ) ;
            output[k + 1] = clamp( pixels[k + 1] + delta ) ;
            output[k + 2] = clamp( pixels[k + 2] + delta ) ;
        }
    }
    return output ;
}

unsigned char *invert( unsigned char *pixels , int width , int height , int channels )
{
    unsigned char *output = malloc( width * height * channels * sizeof( unsigned char ) ) ;
    for ( int i = 0 ; i < height ; i ++ )
    {
        for ( int j = 0 ; j < width ; j ++ )
        {
            int k = ( i * width + j ) * channels ;
            output[k]     = 255 - pixels[k] ;
            output[k + 1] = 255 - pixels[k + 1] ;
            output[k + 2] = 255 - pixels[k + 2] ;
        }
    }
    return output ;
}

unsigned char *resize( unsigned char *pixels , int width , int height , int channels , double scale )
{
    if ( scale <= 0 )
    {
        printf( "Invalid scale.\n" ) ;
        return NULL ;
    }

    int new_width  = ( int ) ( scale * width  ) ;
    int new_height = ( int ) ( scale * height ) ;
    if ( new_width  < 1 ) new_width  = 1 ;
    if ( new_height < 1 ) new_height = 1 ;

    unsigned char *output = malloc( new_width * new_height * channels * sizeof( unsigned char ) ) ;

    double scale_x = ( double ) width  / new_width ;
    double scale_y = ( double ) height / new_height ;

    for ( int i = 0 ; i < new_height ; i ++ )
    {
        for ( int j = 0 ; j < new_width ; j ++ )
        {
            int k = ( i * new_width + j ) * channels ;

            double x = j * scale_x ;
            double y = i * scale_y ;

            int x0 = ( int ) x , y0 = ( int ) y ;
            int x1 , y1 ;
            if ( x0 + 1 < new_width  ) x1 = x0 + 1 ; else x1 = x0 ;
            if ( y0 + 1 < new_height ) y1 = y0 + 1 ; else y1 = y0 ;
            double x_dec = x - x0 , y_dec = y - y0 ;

            // top-left, top-right, bottom-left, bottom-right
            int k_tl = ( y0 * width + x0 ) * channels ;
            int k_tr = ( y0 * width + x1 ) * channels ;
            int k_bl = ( y1 * width + x0 ) * channels ;
            int k_br = ( y1 * width + x1 ) * channels ;

            for ( int l = 0 ; l < channels ; l ++ )
            {
                double pixel_tl = pixels[k_tl + l] ;
                double pixel_tr = pixels[k_tr + l] ;
                double pixel_bl = pixels[k_bl + l] ;
                double pixel_br = pixels[k_br + l] ;

                double top    = pixel_tl * ( 1 - x_dec ) + pixel_tr * x_dec ;
                double bottom = pixel_bl * ( 1 - x_dec ) + pixel_br * x_dec ;
                double result = top      * ( 1 - y_dec ) + bottom   * y_dec ;

                output[k + l] = ( unsigned char ) ( result + 0.5 ) ;
            }
        }
    }
    return output ;
}

// helper functions
unsigned char clamp( int value )
{
    if ( value < 0 ) return 0 ;
    if ( value > 255 ) return 255 ;
    return ( unsigned char ) value ;
}

void boundary_value_check( unsigned char **pixels , int width , int height , int channels )
{
    for ( int i = 0 ; i < height ; i ++ )
    {
        for ( int j = 0 ; j < width ; j ++ )
        {
            int k = ( i * width + j ) + channels ;
            ( *pixels )[k] = clamp( ( int )( *pixels )[k] ) ;
            ( *pixels )[k + 1] = clamp( ( int ) ( *pixels )[k + 1] ) ;
            ( *pixels )[k + 2] = clamp( ( int ) ( *pixels )[k + 2] ) ;
        }
    }
}

int invalid_boundary( unsigned char *pixels , int width , int height , int channels , int x , int y , int crop_width , int crop_height )
{
    int validation = 0 ;
    if ( x >= 0 && y >= 0 && x + crop_width <= width && y + crop_height <= height ) validation = 1 ;
    return 1 - validation ;
}