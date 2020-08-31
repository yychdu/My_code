
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "limits.h"
#include "math.h"
#include "stdbool.h"

int maxProduct(int* nums, int numsSize)
{
    int dpmax[numsSize], dpmin[numsSize];
    dpmax[0] = dpmin[0] = nums[0];
    int ans = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        dpmax[i] = fmax(nums[i], fmax(dpmin[i - 1] * nums[i], dpmax[i - 1] * nums[i]));
        dpmin[i] = fmin(nums[i], fmin(dpmin[i - 1] * nums[i], dpmax[i - 1] * nums[i]));
        ans = fmax(ans, dpmax[i]);
    }
    return ans;
}

