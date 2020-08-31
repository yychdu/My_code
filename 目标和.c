
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "limits.h"
#include "math.h"
#include "stdbool.h"


void caclulate(int *nums, int numsSize, int index, int S, int sum, int *cnt)
{
    if (index == numsSize)
        *cnt += (sum == S);
    else
    {
        caclulate(nums, numsSize, index + 1, S, sum + nums[index], cnt);
        caclulate(nums, numsSize, index + 1, S, sum - nums[index], cnt);
    }
    
}

int findTargetSumWays(int* nums, int numsSize, int S){
    int cnt = 0;
    caclulate(nums, numsSize, 0, S, 0, &cnt);
    return cnt;
}