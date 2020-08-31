#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
// 使用中心扩散法寻找回文数组，但是回文数组有两种可能，奇数个和偶数个。
// 设置两个指针left和right，分别位于对称中心的两边，向两边扩散，中心对称点是重复字符串则当成一个字符处理。

char * longestPalindrome(char * s)
{
    if(strlen(s) == 0 || strlen(s) == 1)
        return s;
    int i, start, left, right, count, len;
    start = len = 0;
    for (i = 0; s[i]; i++)
    {
        left = i - 1;
        right = i + 1;
        while (s[right] && s[i] == s[right]) //处理重复字符串
            right++;

        while(left >= 0 && s[right] && s[left] == s[right])
        {
            left--;
            right++;
        }
        if(right - left - 1 > len)
        {
            start = left + 1;
            len = right - left - 1;
        }
    }
    s[start + len] = '\0';      // 原地修改返回
    return s + start;
}

