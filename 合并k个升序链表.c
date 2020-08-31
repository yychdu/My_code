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

typedef struct ListNode ListNode;

ListNode *merge2Lists(ListNode *head1, ListNode *head2)
{
    if (!head1 || !head2)
        return head1 ? head1 : head2;
    ListNode *dummy = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p = dummy;
    while (head1 && head2)
    {
        if (head1->val < head2->val)
        {
            p->next = head1;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    p->next = head1 ? head1 : head2;
    return dummy->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    ListNode *ans = NULL;
    for (int i = 0; i < listsSize; i++)
        ans = merge2Lists(ans, lists[i]);
    return ans;
}