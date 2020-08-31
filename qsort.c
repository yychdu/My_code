
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include <stdio.h>
#include <string.h>
#include "stdlib.h"
typedef struct 
{
    int stunum;
    char name[10];
} student;

int cmpfunc (const student * a, const student * b)
{
	return a->stunum < b->stunum;
}


int main()
{
	int a[] = {4, 5, 9, 0, 3, 1};
	student stu[] =
	{
		9, "a", 2, "b", 3, "c"
	};

	qsort(stu, sizeof(stu) / sizeof(student), sizeof(student), cmpfunc);
	for (int i = 0; i < sizeof(stu) / sizeof(student); i++)
		printf("%d %s\n", stu[i].stunum,stu[i].name);
	return (0);
}