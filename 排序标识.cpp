/*
题目描述
输入整型数组和排序标识，对其元素按照升序或降序进行排序（一组测试用例可能会有多组数据）

接口说明

原型：

void sortIntegerArray(Integer[] pIntegerArray, int iSortFlag);

输入参数：

Integer[] pIntegerArray：整型数组

int  iSortFlag：排序标识：0表示按升序，1表示按降序

输出参数：

无

返回值：

void


输入描述:
1、输入需要输入的整型数个数

输出描述:
输出排好序的数字

示例1
输入
复制
8
1 2 4 9 3 55 64 25
0
输出
复制
1 2 3 4 9 25 55 64
*/
#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include "stdlib.h"
using namespace std;

int main()
{
    int num,i,stat;
    while (scanf("%d",&num) != EOF)
    {
        int *arr = (int *)malloc(num * sizeof(int));
        for (i = 0; i < num;i++)
            scanf("%d", &arr[i]);
        scanf("%d", &stat);
        if (!stat)
            sort(arr, arr + num);
        else
            sort(arr, arr + num, greater<int>());
        for (i = 0; i < num;i++)
            printf("%d ", arr[i]);
        printf("\n");
        free(arr);
    }
    return 0;
}