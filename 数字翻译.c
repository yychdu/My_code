
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"

int _translateNum(int num){
    int* nums = (int *) malloc (sizeof(int) * 20), numsSize = 0;
    int* dp = (int *) malloc (sizeof(int) * 20);
	
    while (num > 9) {//按位存到数组
        nums[numsSize++] = num % 10;
        num = (num - num % 10) / 10;
    }
    nums[numsSize++] = num;
    for (int i = 0; i < numsSize; i++)
        printf("%d ", nums[i]);
    printf("\n ");
    for (int left = 0, right = numsSize - 1; left < right; left++, right--)
    { //交换顺序
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }
    for (int i = 0; i < numsSize; i++)
    printf("%d ", nums[i]);
    dp[0] = 1;//只有一位的情况下为一
    dp[1] = (nums[0] * 10 + nums[1] < 26 && nums[0] * 10 + nums[1] > 9) ? dp[0] + 1 : dp[0];
    //第二位会不会组成条件，可以就对应情况增加
    for(int i = 2; i < numsSize; i++)
        dp[i] = (nums[i - 1] * 10 + nums[i] < 26 && nums[i - 1] * 10 + nums[i] > 9) ? dp[i - 2] + dp[i - 1] : dp[i - 1];
        //不能组合时等于上一个的数量，可以组合时，等会后两位组合加上最后一位不参与组合的情况（//有可能倒数二三位可以组合切倒数一二位也可以祝贺的情况。
    return dp[numsSize - 1];
}
# define STR_CMP ((str[0] - '0')*10 + (str[1] - '0') < 26 && (str[0] - '0')*10 + (str[1] - '0') > 9)
# define STR_CMP2 ((str[i - 1] - '0')*10 + (str[i] - '0') < 26 && (str[i - 1] - '0')*10 + (str[i] - '0') > 9)
int translateNum(int num)
{
    char str[100] = {0};
    int* dp = (int *) malloc (sizeof(int) * 20);
    sprintf(str, "%d", num);
    dp[0] = 1;
    dp[1] =  STR_CMP ? dp[0] + 1 : dp[0];
    for (int i = 2; i < strlen(str) - 1; i++)
        dp[i] = STR_CMP2 ? dp[i - 2] + dp[i - 1] : dp[i - 1];
    return dp[strlen(str) - 1];
}

int main()
{
    printf("%d", translateNum(12258));
}