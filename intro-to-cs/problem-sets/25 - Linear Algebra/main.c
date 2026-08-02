#include <stdio.h>
#include <stdlib.h>
#include <array.h>
#include <strlib.h>
#include <linalg.h>

int main(int argc, arr(str) argv)
{
    arr(arr(int)) A = build(argv[1]);

    int rows = nrows(argv[1]);
    int cols = ncols(argv[1]);

    display(A, rows, cols);

    // ... use the matrix for doing something

    return 0;
}