
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"

bool isSubsequence(char * s, char * t){
    char *ptr = strchr(t, *s);
    if (!ptr)
        return false;
    int pos = ptr - t;
    int pos2;
    for (int i = 1; s[i]; i++)
    {
        int tmp = *(s + i);
        ptr = strchr(t, tmp);
        if (ptr == NULL)
            return false;
        else
        {
            pos2 = ptr - t;
            if (pos2 <= pos)
                return false;
            else
            {
                pos = pos2;
            }
        }
    }
    return true;
}

int main()
{
    char s[] = "abc";
    char t[] = "ahbgdc";
    printf("%d", isSubsequence(s, t));
}