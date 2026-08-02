#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "image_processing.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main( int argc , char *argv[] )
{
    // variable declaration
    int width , height , channels ;
    int new_width , new_height ;
    unsigned char *pixels ; // the input image
    unsigned char *output_pixels ; // the output image
    // read the command from terminal
    char *input_file  = argv[1] ;
    char *output_file = argv[2] ;
    char *command     = argv[3] ;

    // loading input image by stb
    pixels = stbi_load( input_file , &width , &height , &channels , 3 ) ;
    // force 3 channels
    channels   = 3 ;
    // initialize the size of output image
    new_width  = width ;
    new_height = height ;

    // check if the value of pixels is in the range [0, 255]
    // if not, let it be the boundary value
    boundary_value_check( &pixels , width , height , channels ) ;

    if ( strcmp( command , "grayscale" ) == 0 ) // command grayscale
    {
        output_pixels = grayscale( pixels , width , height , channels ) ;
    }
    else if ( strcmp( command , "flip" ) == 0 ) // command flip
    {
        char *direction = argv[4] ; // read the diration of rotation
        if ( strcmp( direction , "horizontal" ) == 0 ) // flip horizontally
        {
            output_pixels = flip_horizontal( pixels , width , height , channels ) ;
        }
        else if ( strcmp( direction , "vertical" ) == 0 ) // flip vertically
        {
            output_pixels = flip_vertical( pixels , width , height , channels ) ;
        }
    }
    else if ( strcmp( command , "rotate" ) == 0 ) // command rotate
    {
        int degree = atoi( argv[4] ) ; // read the degree of rotation
        // if the degree is 90, -90, 270, -270, the width and height should be swapped
        // plus 360 to deal with the negative value
        if ( ( degree + 360 ) % 360 == 90 || ( degree + 360 ) % 360 == 270 )
        {
            new_width = height ;
            new_height = width ;
        }
        output_pixels = rotate( pixels , width , height , channels , degree ) ;
    }
    else if ( strcmp( command , "blur" ) == 0 ) // command blur
    {
        output_pixels = blur( pixels , width , height , channels ) ;
    }
    else if ( strcmp( command , "crop" ) == 0 ) // command crop
    {
        // read the parameters
        int x = atoi( argv[4] ) ;
        int y = atoi( argv[5] ) ;
        int crop_width = atoi( argv[6] ) ;
        int crop_height = atoi( argv[7] ) ;
        // determine if the region is valid
        if ( invalid_boundary( pixels , width , height , channels , x , y , crop_width , crop_height ) )
        {
            // if not, print error message
            printf( "The crop region is invalid.\n" ) ;
            // and terminalte the program
            return 0 ;
        }
        output_pixels = crop( pixels , width , height , channels , x , y , crop_width , crop_height ) ;
        // the new width and height changed to what parameter said
        new_width = crop_width ;
        new_height = crop_height ;
    }
    else if ( strcmp( command , "threshold" ) == 0 ) // threshold filter
    {
        int thres = 128 ; // default threshold
        if ( argc == 5 ) thres = atoi( argv[4] ) ; // optinal parameter: users are allowed to set threshold
        output_pixels = threshold( pixels , width , height , channels , thres ) ;
    }
    else if ( strcmp( command , "bright" ) == 0 ) // brightness adjustment
    {
        int delta = atoi( argv[4] ) ; // value of brightness change
        output_pixels = bright( pixels , width , height , channels , delta ) ;
    }
    else if ( strcmp( command , "invert") == 0 ) // color inversion
    {
        output_pixels = invert( pixels , width , height , channels ) ;
    }
    else if ( strcmp( command , "resize" ) == 0 ) // bilinear resize
    {
        double scale = atof( argv[4] ) ; // users should give the scale of resize( > 0 )
        // set size of output_pixels
        new_width  = ( int ) ( scale * width  ) ;
        new_height = ( int ) ( scale * height ) ;
        // at least one pixel
        if ( new_width  < 1 ) new_width  = 1 ;
        if ( new_height < 1 ) new_height = 1 ;
        output_pixels = resize( pixels , width , height , channels , scale ) ;
    }
    else // for code safety
    {
        printf( "Unknown command: %s.\n" , command ) ;
        return 0 ;
    }

    if ( output_pixels == NULL ) // when the rotation degree is not support, we let output_pixels be NULL
    {
        // not write the image and terminate program directely
        return 0 ;
    }
    else
    {
        // write the image
        stbi_write_bmp( output_file , new_width , new_height , channels , output_pixels ) ;
        printf( "The image has been processed.\n" ) ;
        return 0 ;
    }
    return 0 ;
}