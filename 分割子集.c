#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"

bool find(int nums[], int target, int index, int numsSize)
{
    if (target == 0)
        return true;
    for (int i = index; i < numsSize; i++)
    {
        if (i > index && nums[i] == nums[i - 1])
            continue;
        if (target - nums[i] < 0)
            return false;
        if (find(nums, target - nums[i], i + 1, numsSize))
            return true;
    }
    return false;
}

bool canPartition(int* nums, int numsSize){
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
        sum += nums[i];
    if (sum & 1)
        return false;
    if (sum == 0)
        return true;
    return find(nums, sum / 2, 0, numsSize);
}