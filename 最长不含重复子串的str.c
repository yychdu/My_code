
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "limits.h"
#include "math.h"


//sliding window
int lengthOfLongestSubstring(char* s) 
{
    int lenStr = strlen(s);
    if (lenStr <= 1) return lenStr;
    int dict[128];
    memset(dict, -1, sizeof(dict));
    int l = -1;  // 设置为 -1 保证l未移动时的正确性
    int r = 0;
    int maxNum = 0;
    while (r < lenStr) 
    {
        if (dict[s[r]] >= l) 
            l = dict[s[r]];
         // 前面有重复元素
         // 保证左指针在右侧具有重复元素的最前面
        dict[s[r]] = r; // 记录下标
        maxNum = fmax(maxNum, r - l);
        r++;
    }
    return maxNum;
}

