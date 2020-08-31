/*
输入描述:
输入一串字符。

输出描述:
对字符中的
各个英文字符（大小写分开统计），数字，空格进行统计，并按照统计个数由多到少输出,如果统计的个数相同，
则按照ASII码由小到大排序输出 。如果有其他字符，则对这些字符不用进行统计。
示例1
输入

aadddccddc
输出

dca
*/

#include<stdio.h>
#include<string.h>
int main()
{  
    char str[1000];
    while(gets(str))
    {
         
        int count[256]={0};
        int max=0;
        for(int i=0;i<strlen(str);i++)
        {
            count[str[i]]++;
            if(count[str[i]]>max)
            {
                max=count[str[i]];
            }
        }
        while(max)
        {
            for(int i=0;i<256;i++)
            {
                if(count[i]==max)
                {
                    printf("%c",i);
                }
            }
            max--;
        }
        printf("\n");
    }
    return 0;
}