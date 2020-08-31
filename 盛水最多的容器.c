#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int maxArea(int* height, int heightSize){
    int left = 0, right = heightSize - 1;
    int res;
    while (left < right)
    {
        res = height[left] < height[right] ? fmax(res, (right - left) * height[left++]) : fmax(res, (right - left) * height[right--]);
    }
    return res;
}