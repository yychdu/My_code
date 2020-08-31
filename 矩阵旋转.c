#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for (int high = 0, low = matrixSize - 1; high < low; ++high, --low)
        swap(&matrix[high], &matrix[low]);
    for (int i = 0; i < matrixSize; ++i)
        for (int j = i; j < matrixSize; ++j)
            swap(&matrix[i][j], &matrix[j][i]);
}