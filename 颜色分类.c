#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
#include "math.h"
void sortColors(int* nums, int numsSize){
    int hash[1000];
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < numsSize; i++)
    {
        hash[nums[i]]++;
    }
    for (int i = 0, j = 0; i < numsSize; i++)
    {
        if (hash['0' + j]--)
        {
            nums[i] = '0' + j;
        }
        else
            j++;
    }
}
int main()
{
    int arr[] = {2, 0, 2, 1, 1, 0};
    sortColors(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        printf("%d ",arr[i]);
}