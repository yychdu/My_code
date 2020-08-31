#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverse(struct ListNode *head)
{
    struct ListNode *cur = NULL, *pre = head, *temp;
    while (pre != NULL)
    {
        temp = pre->next;
        pre->next = cur;
        cur = pre;
        pre = temp;
    }
    return cur;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if (head == NULL)
        return NULL;
    struct ListNode *pre, *end,*dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    pre = dummy;
    end = dummy;
    while (end->next != NULL)
    {
        for (int i = 0; i < k && end != NULL; i++)
            end = end->next;
        if (end == NULL)
            break;
        struct ListNode *start = pre->next;
        struct ListNode *tail = end->next;
        end->next = NULL;
        pre->next = reverse(start);
        start->next = tail;
        pre = start;
        end = start;
    }
    return dummy->next;
}