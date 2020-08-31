/*
题目描述
输入一个单向链表，输出该链表中倒数第k个结点，链表的倒数第1个结点为链表的尾指针。

链表结点定义如下：

struct ListNode

{

int       m_nKey;

ListNode* m_pNext;

};

详细描述：

接口说明

原型：

ListNode* FindKthToTail(ListNode* pListHead, unsignedint k);

输入参数：

ListNode* pListHead  单向链表

unsigned int k  倒数第k个结点

输出参数（指针指向的内存区域保证有效）：

无

返回值：

正常返回倒数第k个结点指针，异常返回空指针



输入描述:
输入说明
1 输入链表结点个数
2 输入链表的值
3 输入k的值

输出描述:
输出一个整数

示例1
输入
8
1 2 3 4 5 6 7 8
4
输出
5
*/

#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void Insert(node *head,int indata)
{
    node *p = (node *)malloc(sizeof(node));
    p -> data = indata;
    while (head -> next != NULL)
        head = head->next;
    head->next = p;
    p->next = NULL;
}

void show(node* head, int k)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
}

int main()
{
    int headdata,num, i , k;
    while (scanf("%d", &num) != EOF)
    {
        node *head = (node *)malloc(sizeof(node));
        scanf("%d", &headdata);
        head->data = headdata;
        head->next = NULL;
        for (i = 1; i < num; i++)
        {
            scanf("%d", &headdata);
            Insert(head, headdata);
        }
        scanf("%d", &k);
        if(k == 0)
        {
            printf("%d\n",0);
            continue;
        }
        for (i = 0; i < num - k; i++)
        {
            head = head->next;
        }
        printf("%d", head->data);
        printf("\n");
    }
    
}
