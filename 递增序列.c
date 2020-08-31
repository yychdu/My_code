
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "limits.h"
#include "math.h"
#include "stdbool.h"

int lengthOfLIS(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 0) {
        return 0;
    }

    int ans = -1;        //  记录最大的res[i]
    int *res = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) 
    {
        res[i] = 1;      //  边界初始条件（因为每个元素都可以自成一个子序列）
        for (int j = 0; j < i; j++) 
        {
            if (nums[i] > nums[j] && (res[j] + 1 > res[i])) 
                res[i] = res[j] + 1;   
        }
        ans = fmax(res[i], ans);
        
    }
    return ans;
}
int main()
{
    int arr[] = {2, 5, 3, 4};
    lengthOfLIS(arr, 4);
}



