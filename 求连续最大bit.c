/*
功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
    
输入: 一个byte型的数字
    
输出: 无
     
返回: 对应的二进制数字中1的最大连续数
输入描述:
输入一个byte数字

输出描述:
输出转成二进制之后连续1的个数

示例1
输入
复制
3
输出
复制
2
*/
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
int main()
{
    int byte;
    int a = 1, cnt = 0;
    int max = 0;
    while (scanf("%d", &byte)!=EOF)
    {
        while(byte > a)
        {
            while ((byte & a) == 0)
            a = a << 1;
            cnt = 0;
            while ((byte & a) != 0)
            {
                a = a << 1;
                cnt++;
            }
            max = max > cnt ? max : cnt;
        }
        printf("%d\n", max);
    }
   

    
    return 0;
}
