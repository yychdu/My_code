#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int i, j;
    *returnSize = TSize;
    int *res = (int*)calloc(sizeof(int), TSize);
    for (i = 0; i < TSize; i++)
    {
        for (j = i + 1; j < TSize; j++)
        {
            if (T[j] > T[i])
            {
                res[i] = j - i;
                break;
            }
        }
    }
    return res;
}

int* dailyTemperatures(int* T, int TSize,int* returnSize){
    *returnSize = TSize;
    int *result = (int*)calloc(sizeof(int), TSize); //动态数组
    int stack[TSize];  //数组模拟堆栈
    //栈的思路是：
    //栈的下标是0,1,2,3(top = -1为空栈)（废话）,,,栈里面放的数值是：对应此时（T[i](温度)）的下标，也就是i
    //栈顶是小的，栈下面是大的（这里的大小，我们所比较的是此时的T[i]和栈顶元素T[stack[top]]的大小）（详细一点是，T[栈顶元素对应下标]）
    int i,top = -1; //top为 栈顶指针
    //正序遍历
    for (i = 0; i < TSize; ++i)//主要控制的是i,也就是T[i]，也就是T数组的下标
    {

        while (top > -1 && T[i] > T[stack[top]])
        {//注意这是while,这说明了，对于一次for循环（固定i的时候），可以做到多次对result进行赋值
            result[stack[top]] = i - stack[top];
            //进行了赋值后，我们进行top--，此时的T[i]是不是还栈里面的元素大
            top--;
        }
        stack[++top] = i;
    }
    return result;
}