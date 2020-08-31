#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a; 
}

int findKthLargest(int* nums, int numsSize, int k){
    int result = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != nums[i + 1])
        {
            if (--k == 0)
            {
                result = nums[i];
                break;
            }
        }
    }
    return result;
}