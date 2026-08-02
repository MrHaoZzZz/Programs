#ifndef LINALG_H
#define LINALG_H

#include <array.h>
#include <strlib.h>

int nrows(str matrix);
int ncols(str matrix);

arr(arr(int))   build (str s);
    // require: s is of the form "r c a11 a12 ... a1c a21 a22 ... a2c ... ar1 ar2 ... arc"
    // ensure: the output A is a matrix of r rows x c columns with content as stated by s

void display(arr(arr(int)) A, int rows, int cols);
    // prints the matrix in the screen

arr(arr(int))   transpose(arr(arr(int)) A, int rows, int cols);


#endif