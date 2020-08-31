
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

void sort(int *a, int left, int right)
{
	if (left >= right) return;
	int i = left;
	int j = right;
	int key = a[i];
	while (i < j)
	{
		while (i < j && key <= a[j])
			j--;
		a[i] = a[j];
		while (i < j && a[i] <= key)
			i++;
		a[j] = a[i];
	}
	a[i] = key;
	sort(a, i + 1, right);
	sort(a, left, i - 1);
}

int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int binsearch(int* sortedSeq, int seqLength, int keyData)
{
	int left = 0, right = seqLength - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (keyData < sortedSeq[mid])
			right = mid - 1;
		else if (keyData > sortedSeq[mid])
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	int key = 9;
	int a[] = {4, 5, 9, 0, 3, 1};
	int *item = (int*) bsearch (&key, a, 6, sizeof (int), cmpfunc);
	if( item != NULL ) 
	{
		printf("Found item = %d\n", item - a);
	}
	else 
	{
		printf("Item = %d could not be found\n", *item);
	}

	return (0);
}