
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#define N 100

typedef struct
{
    int top;                //统计栈中有多少个元素，data[top]是栈顶
    int data[N];            //数组用于存放数据
} stack;

stack mystack = {-1, {0}};
//-1代表栈中没有元素 {0}将数组全部初始化为0

int isempty();//判定下一栈是否为空
void setempty();//设置栈为空
int push(int data);//压入一个数据
int pop();//取出一个数组

int isempty() //1代表栈为空 0代表不为空
{
    if (mystack.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void setempty()
{
    mystack.top = -1;
}

int push(int data)//成功返回1 失败返回0 0代表栈溢出
{
    if (mystack.top + 1 <= N - 1)
    {
        mystack.data[mystack.top + 1] = data;//数组上升一个 接受新数据
        mystack.top++;
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop()
{
    if (isempty() == 0)
    {
        mystack.top--;
        return mystack.data[mystack.top + 1];//弹出一个数据
    }
    else 
    {
        return -1;//为空 返回-1
    }
}

// void main()
// {
//     int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     for (int i = 0; i < 10; i++)
//         push(a[i]);
//     while (!isempty())
//         printf("%d ", pop());
// }

//十进制转2进制
//递归可以实现顺序逆序
void ten2two(int n)
{
    if (n == 0)
    {

    }
    else
    {
        int m = n % 2;
        // printf("%d", m);  //递归前 调用 顺序
        ten2two(n / 2);
        printf("%d", m);       //递归后调用 逆序
    }   
} 

void main()
{
    ten2two(10);
    puts("");
    int num = 10;
    // while (num)
    // {
    //     // printf("%d ", num % 2);
    //     push(num % 2);
    //     num /= 2;
    // }
    // while (!isempty())
    //     printf("%d ", pop());
    int *stack1 = (int *)malloc(sizeof(int) * N);
    int size = 0, top = N;
    while (num)
    {
        stack1[--top] = num % 2;
        size++;
        num /= 2;
    }
    for (int i = top; i < top+size; i++)
        printf("%d ", stack1[i]);
}


