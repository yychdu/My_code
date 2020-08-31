#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
struct ListNode
{
    int val;
    struct ListNode *next;
} ;


ListNode* reverselist(ListNode *head)
{
    ListNode *pre = head, *cur = NULL;
    while (pre != NULL)
    {
        ListNode *tmp = pre->next;
        pre->next = cur;
        cur = pre;
        pre = tmp;
    }
    return cur;
}

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    ListNode *dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = head;
    ListNode *pre = dummy;
    ListNode *tail = dummy;
    for (int i = 0; i < m - 1; i++)
        pre = pre->next;
    for (int i = 0; i < n; i++)
        tail = tail->next;

    ListNode *Rtail = tail->next;
    tail->next = NULL;
    ListNode *Rhead = pre->next;
    pre->next = reverselist(Rhead);
    Rhead->next = Rtail;
    return dummy->next;
}
