
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
 struct  ListNode
{
    int val;
    struct ListNode *next;
} ;

typedef struct ListNode node;

node *reverseList(node *head)
{
    node *pre = head, *cur = NULL, *tmp;
    while (pre != NULL)
    {
        tmp = pre->next;
        pre->next = cur;
        cur = pre;
        pre = tmp;
    }
    return cur;
}

void insert(node *head1, node *head2)
{
    node *head1Next, *head2Next;
    while (head1 != NULL && head2 != NULL)
    {
        head1Next = head1->next;
        head2Next = head2->next;
        head1->next = head2;
        head2->next = head1Next;
        head1 = head1Next;
        head2 = head2Next;
    }
}

void reorderList(struct ListNode* head ) {
    // write code here
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return;
    node *slow = head;
    node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *tailList = slow->next;
    slow->next = NULL;
    tailList = reverseList(tailList);
    node *headList = head;
    insert(headList, tailList);
}


//尾插
void addlist(node* head, int x)
{
	if (!head)return;
	while (head->next != NULL)
		head = head->next;
	node* p = (node*)malloc(5 * sizeof(node));
	p->val = x;
	p->next = NULL;
	head->next = p;
}

void prinlist(node* head)
{
	while (head!= NULL)
	{
            printf("%d->", head->val);
		head = head->next;
	}
	printf("NULL");
}
int main()
{
    node* p = (node*) malloc(sizeof(node));
    p->val = 1;
    p->next = NULL;
    addlist(p, 2);
    addlist(p, 3);
    addlist(p, 4);
     reorderList(p);
 
    prinlist(p);
}