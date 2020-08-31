#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#define N 100
#define datatype char

typedef struct
{
    datatype data[N];
    int front;      //允许删除的一端 队头
    int rear;        //允许插入的一端 rear
} queue;

void initQ(queue *sq);
int isempty(queue *sq);
datatype gethead(queue *sq);
void enQ(queue *sq, datatype data);//入队
datatype dqQ(queue *sq);//出队

void initQ(queue *sq)
{
    sq->front = sq->rear = 0;   
}

int isempty(queue *sq)
{
    if (sq->front == sq->rear)
        return 1;
    return 0;
}

datatype gethead(queue *sq)
{
    return isempty(sq)?-1:sq->data[sq->front];
}


void enQ(queue *sq, datatype data)
{
    if (sq->rear == N)
    {
        puts("full");
        return;
    }
    sq->data[sq->rear] = data;
    sq->rear++;
}

datatype dqQ(queue *sq)
{
    isempty(sq) ? -1 : (sq->front++, sq->data[sq->front - 1]);
}

void showQ(queue *sq)
{
    if (isempty(sq))
        return;
    else 
    {
        puts("");
        for (int i = sq->front; i < sq->rear;i++)
        {
            printf("%c ", sq->data[i]);
        }
    }
}

void main()
{

}