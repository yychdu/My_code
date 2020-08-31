/*
题目描述
找出字符串中第一个只出现一次的字符

输入描述:
输入一个非空字符串

输出描述:
输出第一个只出现一次的字符，如果不存在输出-1

示例1
输入
复制
asdfasdfo
输出
复制
o
*/
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int main(int argc, char const *argv[])
{
    char str[1000];
    while(gets(str))
    {
        char a[200] = {0};
        int f = 0;
        for (size_t i = 0; str[i] != '\0'; i++)
            a[str[i]]++;
        for (size_t i = 0; str[i] != '\0'; i++)
        {
            if (a[str[i]] == 1)
            {
                printf("%c\n", str[i]);
                f = 1;
                break;
            }
        }
        if (f == 1)
            continue;
        else
            puts("-1");
    }
  
    
    return 0;
}
