#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include <stdio.h>
#include <string.h>
#include "stdlib.h"
char* intToRoman(int num) {
    int nums[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    char* romans[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    static char R[200] = { 0 };
    int index = 0;
    while (index < 13)
    {
        while (num >= nums[index])
        {
            strcat(R, romans[index]);
            num -= nums[index];
        }
        index++;
    }
    return R;

}

int main()
{
    printf("%s", intToRoman(4));
}