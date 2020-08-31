/*
题目描述
将一个字符串str的内容颠倒过来，并输出。str的长度不超过100个字符。 如：输入“I am a student”，输出“tneduts a ma I”。

输入参数：

inputString：输入的字符串

返回值：

输出转换好的逆序字符串

输入描述:
输入一个字符串，可以有空格

输出描述:
输出逆序的字符串

示例1
输入

I am a student
输出

tneduts a ma I
*/
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
char* solve(char* str ) {
    // write code here
    int len = strlen(str);
    static char res[1000] = { 0 };
    char *ans = res;
    
    for (int i = len - 1; i >= 0; i--)
    {
        sprintf(ans, "%c", str[i]);
        ans++;
    }
    return res;
}

int fun(char* s)
{
    char* t = s;
    while (*t++);
    return(t - s);
}
int main()
{
    char str[1000];
    char buf[1000] = {0};
    int i;
    // while (gets(str))
    // {
    //     for (i = strlen(str) - 1; i != -1; i--)
    //         printf("%c", str[i]);
    //// }
    //printf("%-8s", "aiojd");
    //char* s;
    //s = "1233";
    printf("\n%d", fun(""));

}