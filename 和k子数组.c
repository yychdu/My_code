
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "limits.h"
#include "math.h"
#include "stdbool.h"

int subarraySum(int* nums, int numsSize, int k)
{
    int i, j;
    int sum = 0, cnt = 0;
    for (i = 0; i < numsSize; i++)
    {
        sum = 0;
        for (j = i; j < numsSize; j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                cnt++;
            }
        }
    }
    return cnt;
}   

int main()
{
    int arr[] = {28, 54, 7, -70, 22, 65, -6};
    int k = 100;
    subarraySum(arr, sizeof(arr) / sizeof(arr[0]), k);
}