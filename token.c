
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include <stdio.h>
#include <string.h>

int main()
{
	const char str[] = "This is - www.runoob.com - website";
	const char ch = '.';
	char* ret;

	ret = (char*)memchr(str, '-', 20);

	printf("|%c| 之后的字符串是 - |%s|\n", ch, ret);

	return(0);
}