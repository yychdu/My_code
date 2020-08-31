/*
题目描述
现在IPV4下用一个32位无符号整数来表示，一般用点分方式来显示，点将IP地址分成4个部分，每个部分为8位，表示成一个无符号整数（因此不需要用正号出现），
如10.137.17.1，是我们非常熟悉的IP地址，一个IP地址串中没有空格出现（因为要表示成一个32数字）。

现在需要你用程序来判断IP是否合法。


输入描述:
输入一个ip地址

输出描述:
返回判断的结果YES or NO

示例1
输入
复制
10.138.15.1
输出
复制
YES
*/
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int main()
{
    char str[100];
    while (gets(str))
    {
        int i = 0, j = 0;
        int ip[4] = {0};
        char flag = 1;
        // for (; str[i] != '\0'; i++)
        // {
        //     if (str[i] != '.')
        //         ip[j++] = str[i];
        //     else
        //     {
        //         if (ip[0] == '-' || atoi(ip) > 255)
        //         {
        //             flag = 0;
        //             break;
        //         }
        //         else
        //             ;
        //         memset(ip, 0, sizeof(ip));
        //         j = 0;
        //     }
        // }
        sscanf(str, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
        for (i = 0; i < 4; i++)
        {
            if (ip[i] < 0 || ip[i] > 255)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            puts("NO");
        else
            puts("YES");
    }
}