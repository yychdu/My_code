#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
/*
题目描述
密码要求:
1.长度超过8位

2.包括大小写字母.数字.其它符号,以上四种至少三种

3.不能有相同长度大于等于2的子串重复

输入描述:
一组或多组长度超过2的子符串。每组占一行

输出描述:
如果符合要求输出：OK，否则输出NG

input

021Abc9000
021Abc9Abc1
021ABC9000
021$bc9000

output
OK
NG
NG
OK
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int main() {
    char str[1000],tmp[4];
    
    while (scanf("%s",str) != EOF)
    {
        int up = 0, low = 0, digit = 0, other = 0, flag = 0,i;
        if (strlen(str) <= 8)
        {
            puts("NG");
            continue;
        }
        else
        {
            for (i = 0; str[i] != '\0'; i++)
            {
                if (isupper(str[i]))
                    up = 1;
                else if (islower(str[i]))
                    low = 1;
                else if (isdigit(str[i]))
                    digit = 1;
                else
                    other = 1;
            }
            if (up + low + digit + other < 3)
            {
                puts("NG");
                continue;
            }
        }
        for (i = 0; str[i+2] != '\0'; i++)
        {
            tmp[0] = str[i];
            tmp[1] = str[i + 1];
            tmp[2] = str[i + 2];
            tmp[3] = '\0';
            if(strstr(str + 2 + i, tmp) != NULL)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            puts("NG");
        else 
            puts("OK");
    }
    return 0;
}