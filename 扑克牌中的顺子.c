
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
/*
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。


示例 1:

输入: [1,2,3,4,5]
输出: True
 

示例 2:

输入: [0,0,1,2,5]
输出: True

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int cmp(const int* a, const int* b)
{
    return *a > *b;
}

bool isStraight(int* nums, int numsSize){
    bool result = false;
    int joker = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < 5; i++)
    {
        // printf("%d ", nums[i]);
        if (nums[i] == 0)
            joker++;
        else if (nums[i] == nums[i + 1])
            return false;
    }

     if (nums[numsSize - 1] - nums[joker] < 5)
        result = true;
    return result;
}

int main()
{
    int a[] = { 0,0,1,2,5 };
    
    
    printf("%d\n", isStraight(a, 5));
}                                                                              