#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"

char* search(char* str)
{
    int Slen = strlen(str);
    char *start = str;
    int max = 1;
    int len = 1;
    for (int i = 0; i < Slen - 1; i++)
    {
        if (str[i] == str[i +1])
        {
            int j = i;
            while (str[j] == str[j + 1])
                j++;
            len = j - i + 1;

        }
        if (len > max)
        {
            start = str + i;
            max = len;
        }
    }
    start[max] = '\0';
    return start;
}

int main() {
    char s[] = "aabbbcCCCCcc";
    printf("%s", search(s));
    return 0;
}