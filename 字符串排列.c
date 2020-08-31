/*
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

示例 1:

输入: [10,2]
输出: "102"
示例 2:

输入: [3,30,34,5,9]
输出: "3033459"
 

提示:

0 < nums.length <= 100
说明:

输出结果可能非常大，所以你需要返回一个字符串而不是整数
拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int cmpfunc(const void * a, const void * b)
{
    char str1[200],str2[200];
	sprintf(str1,"%d%d", *(int*)a, *(int*)b);
    sprintf(str2,"%d%d", *(int*)b, *(int*)a);
    if (strcmp(str1,str2) > 0)
        return 1;
    else 
        return 0;
}

char* minNumber(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    char *buf = (char *)malloc(1024 * sizeof(char));
    char *p = buf;
    buf[0] = '\0';
    for (int i = 0; i < numsSize; i++)
    {
        sprintf(p, "%d", nums[i]);
        p += strlen(p);
    }
    return buf;
}