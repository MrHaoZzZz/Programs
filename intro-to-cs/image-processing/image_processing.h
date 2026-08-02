#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <stdlib.h>

// core functions
unsigned char *grayscale(unsigned char *pixels, int width, int height, int channels);
unsigned char *flip_horizontal(unsigned char *pixels, int width, int height, int channels);
unsigned char *flip_vertical(unsigned char *pixels, int width, int height, int channels);
unsigned char *rotate(unsigned char *pixels, int width, int height, int channels, int degree);
unsigned char *blur(unsigned char *pixels, int width, int height, int channels);
unsigned char *crop(unsigned char *pixels, int width, int height, int channels, int x, int y, int crop_width, int crop_height);

// addtionnal functions(in assignment decription)
unsigned char *threshold(unsigned char *pixels, int width, int height, int channels, int thres);
unsigned char *bright(unsigned char *pixels, int width, int height, int channels, int delta);
unsigned char *invert(unsigned char *pixels, int width, int height, int channels);
unsigned char *resize(unsigned char *pixels, int width, int height, int channels, double scale);

// helper functions
unsigned char clamp(int value);
void boundary_value_check(unsigned char **pixel, int width, int height, int channels);
int invalid_boundary(unsigned char *pixels, int width, int height, int channels, int x, int y, int crop_width, int crop_height);

#endif