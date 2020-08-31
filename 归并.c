#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"

void merge(int arr[], int L, int M, int R)
{
    int LEFT_SIZE = M - L;
    int RIGHT_SIZE = R - M + 1;
    // int left[LEFT_SIZE];
    // int right[RIGHT_SIZE];
    int *left = (int*)malloc(LEFT_SIZE * sizeof(int));
    int *right = (int *)malloc(RIGHT_SIZE * sizeof(int));
    int i, j, k;
    for (i = L; i < M; i++)
        left[i - L] = arr[i];
    for (i = M; i <= R; i++)
        right[i - M] = arr[i];

    i = 0, j = 0, k = L;
    while (i < LEFT_SIZE && j < RIGHT_SIZE)
    {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < LEFT_SIZE)
        arr[k++] = left[i++];
    while (j < RIGHT_SIZE)
        arr[k++] = right[j++];
    free(left);
    free(right);
}

void mergeSort(int arr[], int L, int R)
{
    if (L == R)
        return;
    int M = (L + R) / 2;
    mergeSort(arr, L, M);
    mergeSort(arr, M + 1, R);
    merge(arr, L, M + 1, R);
}

int main()
{
    int arr[] = {16, 8, 9, 10, 4, 0, 6, 7};
    int L = 0;
    int R = 7;
    int M = 4;
    int i;
    mergeSort(arr, L, R);
    for (i = 0; i <= R; i++)
        printf("%d\n", arr[i]);
}