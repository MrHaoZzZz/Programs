#include <stdio.h>
#include <linalg.h>
#include <array.h>
#include <strlib.h>

int nrows(str matrix)
{
    return str2nat(matrix, 0, search(matrix, 0, ' '));
}

int ncols(str matrix)
{
    int i = search(matrix, 0, ' ')+1;

    return str2nat(matrix, i, search(matrix, i, ' '));
}


void display(arr(arr(int)) A, int rows, int cols)
{
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < cols; col++)
        {
            printf("%d ", A[row][col]);
        };

        printf("\n");
    };
}



arr(arr(int)) build (str s) {
    int i=0;
    int j=search(s,i,' '); 
    int rows = str2nat(s, i, j);
    
    i=j+1;
    j=search(s,i,' '); 
    int cols = str2nat(s, i, j);

    arr(arr(int)) A = new(arr(int),rows);
    for(int i=0; i < rows; i++) {
        A[i] = new(int,cols);
    };

    for (int row=0;row<rows;row++){
        for (int col=0;col<cols;col++){
            i = j+1;
            j = search(s, i, ' ');
            A[row][col] = str2nat(s, i, j);
        }
    }

    return A;
}
