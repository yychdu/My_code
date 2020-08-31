
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "limits.h"
#define LEN 128


char* minWindow(char* s, char* t)
{
    int hash[LEN];
    
    int end = 0, start = 0, minStart = 0, minLen = INT_MAX;
    for (int i = 0; i < LEN; i++)
        hash[i] = -1000;
    for (int i = 0; t[i] != 0; i++)
        hash[t[i]] = 0;
    for (int i = 0; t[i] != 0; i++)
        hash[t[i]]++;
    
    int tlen = strlen(t);
    int slen = strlen(s);
    while (end < slen)
    {
        if (hash[s[end]]-- > 0)
            tlen--;
        end++;
        while (tlen == 0)
        {
            if (end - start < minLen)
            {
                minLen = end - start;
                minStart = start;
            }
            if (++hash[s[start]] > 0)
                tlen++;
            start++;
        }
    }
    if(minLen != INT_MAX)//若找得到
    {
        s[minStart + minLen] = '\0';
        return s + minStart;
    }
    return "";//那就找不到啦
}

int main()
{
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";
    //minWindow(s, t);
    printf("%d", strchr(s, *(t + 1)) - s);

}