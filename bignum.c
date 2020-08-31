#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"


char *AddBigNumber(char *s, char *p)
{
    int x = 0;
	int len1 = strlen(s) - 1;
	int len2 = strlen(p) - 1;
	int len3 = max(len1, len2) + 1;
	char *arr = (char *)malloc((len3 + 1) * sizeof(char));
	arr = &arr[len3];
	s = &s[len1];
	p = &p[len2];
	*arr = '\0';
	while (!((*s == '\0') && (*p == '\0')))
	{
		if (*s != '\0')
			x += *(s--) - '0';
		if (*p != '\0')
			x += *(p--) - '0';
		*(--arr) = (x % 10) + '0';
		x /= 10;
	}
	if (x == 1)
		*(--arr) = '1';
	return arr;
}

char res[5103] = {'\0'};
char * addStrings(char * num1, char * num2)
{
    short s1 = strlen(num1), s2 = strlen(num2), len = 5101, carry = 0;
    for (s1--, s2--; s1 >= 0 || s2 >= 0 || carry;)
	{
        carry += (s1 >= 0 ? num1[s1--] - '0': 0) + (s2 >= 0 ? num2[s2--] - '0' : 0);  //最长遍历处理
        res[len--] = carry % 10 + '0';
        carry /= 10;
    }
    return &res[len+1];  // 返回指针，取地址
}

int main() {
    // char *s = "111111111111111111111111111";
	// char *p = "22222222222222222222222";
	// puts(AddBigNumber(s,p));
	int num[] = {1, 1, 1, 1, 1, 1};
	int n = sizeof(num)/sizeof(int);
	printf("%d", n);
	return 0;
}