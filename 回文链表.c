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

typedef struct ListNode node;

node *reverse(node* head)
{
    node *tmp, *pre = head, *cur = NULL;
    while (pre != NULL)
    {
        tmp = pre->next;
        pre->next = cur;
        cur = pre;
        pre = tmp;
    }
    return cur;
}

int stack[5000];

bool isPalindrome(struct ListNode* head){
    node *p = head;
    int top = 5000;
    while (p != NULL)
    {
        stack[--top] = p->val;
        p = p->next;
    }
    while (head != NULL)
    {
        if (head->val != stack[top++])
            return false;
        head = head->next;
    }
    return true;
}