#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
#include "math.h"


/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 struct  ListNode
{
    int val;
    struct ListNode *next;
} ;

typedef struct ListNode node;

node *reverse(node *head)
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

/**
 * 
 * @param head1 ListNode类 
 * @param head2 ListNode类 
 * @return ListNode类
 */



struct ListNode* addInList(struct ListNode* head1, struct ListNode* head2 ) {
    // write code here
    head1 = reverse(head1);
    head2 = reverse(head2);
    // node* dummy1 = (node*) malloc(sizeof(node));
    // node* dummy2 = (node*) malloc(sizeof(node));
    node* dummy3 = (node*) malloc(sizeof(node));
    // dummy1->next = head1;
    // dummy2->next = head2;
    node *cur1 = head1;
    node* cur2 = head2;
    node *cur3 = dummy3;
    int carry = 0;
    while (cur1 || cur2) 
    {
        carry += (cur1 ? cur1->val : 0) + (cur2 ? cur2->val : 0);
        cur3->next = (node *)malloc(sizeof(node));
        cur3->next->val = carry % 10;
        cur3 = cur3->next;
        carry /= 10;
        if (cur1)
            cur1 = cur1->next;
        if (cur2)
            cur2 = cur2->next;
    }
    if (carry)
    {
        cur3->next = (node *)malloc(sizeof(node));
        cur3->next->val = carry;
    }
    return reverse(dummy3->next);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    node *dummy1 = (node *)malloc(sizeof(node));
    dummy1->next = NULL;
    int carry = 0;
    node *cur1 = l1;
    node *cur2 = l2;
    node *cur3 = dummy1;
    while (cur1 || cur2)
    {
        carry += (cur1 ? cur1->val : 0) + (cur2 ? cur2->val : 0);
        node *p = (node *)malloc(sizeof(node));
        cur3->next = p;
        cur3->next->val = carry % 10;
        carry /= 10;
        cur3 = cur3->next;
        if (cur1)
            cur1 = cur1->next;
        if (cur2)
            cur2 = cur2->next;
    }
    if (carry)
    {
        node *p = (node *)malloc(sizeof(node));
        cur3->next = p;
        cur3->next->val = carry;
    }
    return dummy1->next;
}