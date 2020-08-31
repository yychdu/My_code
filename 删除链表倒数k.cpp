#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"

struct ListNode
{
    int val;
    struct ListNode *next;
} ;

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = head;
    ListNode *p1 = head, *p2 = dummy;
    for (int i = 0; i < n; i++)
        p1 = p1->next;
    while (p1 != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    p2->next = p2->next->next;
    return dummy->next;
}