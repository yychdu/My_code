
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "limits.h"
#include "math.h"
#include "stdbool.h"
bool wordBreak(char * s, char ** wordDict, int wordDictSize)
{
    for (int i = 0; i < wordDictSize; i++)
    {
        if (strstr(s, wordDict[i]) == s)
        {
            
            s += strlen(wordDict[i]);
            i = -1;
        }
    }
    return *s == '\0';
}

int main()
{
    char *buf[] = {"apple", "pen"};
    printf("%d", wordBreak("applepenapple", buf, 2));
//     "applepenapple"
// ["apple","pen"]
}