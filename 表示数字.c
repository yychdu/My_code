/*
将一个字符中所有出现的数字前后加上符号“*”，其他字符保持不变
public static String MarkNum(String pInStr)
{

return null;
}
注意：输入数据可能有多行
输入描述:
输入一个字符串

输出描述:
字符中所有出现的数字前后加上符号“*”，其他字符保持不变

示例1
输入
复制
Jkdi234klowe90a3
输出
复制
Jkdi*234*klowe*90*a*3*
*/
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int main(int argc, char const *argv[])
{

    int i,j,len;
    char str[1000];
    while(scanf("%s", str)!=EOF)
    {
        for (i = 0; str[i] != '\0'; i++)
        {
            if (!isdigit(str[i]))
                printf("%c", str[i]);
            else
            {
                printf("*");
                for (j = i; isdigit(str[j]); j++)
                    printf("%c", str[j]);

                printf("*");
                i = --j;
            }
        }
        printf("\n");
    }
    return 0;
}
