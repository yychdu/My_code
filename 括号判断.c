
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "limits.h"
#include "math.h"
#include "stdbool.h"
char pairs(char a) {
    if (a == '}') return '{';
    if (a == ']') return '[';
    if (a == ')') return '(';
    return 0;
}

bool isValid(char* s) {
    int n = strlen(s);
    if (n % 2 == 1) 
        return false;
    int stk[n + 1], top = 0;
    for (int i = 0; i < n; i++) 
    {
        char ch = pairs(s[i]);
        if (ch) 
        {
            if (top == 0 || stk[--top] != ch) 
                return false;
        } 
        else 
            stk[top++] = s[i];
    }
    return top == 0;
}

