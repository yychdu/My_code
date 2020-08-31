#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
int main()
{
    char str[10000];
    while(gets(str))
    {
        int i , j, len = strlen(str);
        for(i = len - 1;i >= 0; i--)
        {
            if(!isalpha(str[i]))
            {
                j = i;
                j++;
                for(;;j++)
                {
                    if(!isalpha(str[j]) || str[j] == '\0')
                        break;
                    else 
                        printf("%c",str[j]);
                }
                printf(" ");
            }
        }
         i = 0;
        while(isalpha(str[i]))
        {
            printf("%c", str[i]);
            i++;
        }
        printf("\n");
    }
}