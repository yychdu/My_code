#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

typedef struct  ListNode
{
    int val;
    struct List* next;
}node;

node* createlist(int x)
{
	node* p = (node*)malloc(sizeof(node));
	p->val = x;
	p->next = NULL;
	return p;
}

//尾插
void addlist(node* head, int x)
{
	if (!head)return;
	while (head->next != NULL)
		head = head->next;
	node* p = (node*)malloc(sizeof(node));
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
	printf("NULL\n");
}

node *list_devide(node *head, int value)
{
    node* dummy1 = (node *)malloc(sizeof(node));
    node* dummy2 = (node *)malloc(sizeof(node));
    dummy1->next = NULL;
    dummy2->next = NULL;
    node *p = head;
    while (p != NULL)
    {
        if (p->val < value)
        {
            addlist(dummy1, p->val);
        }
        else
        {
            addlist(dummy2, p->val);
        }
        p = p->next;
    }
    
    node *list1 = dummy1->next;
    node *list1Head = list1;
    node *list2 = dummy2->next;
    prinlist(list1);
    prinlist(list2);
    while (list1->next != NULL)
    {
        list1 = list1->next;
    }
    list1->next = list2;
    return list1Head;
}


struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode *p1Head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p2Head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p1 = p1Head;
    struct ListNode *p2 = p2Head;
    struct ListNode *p = head;

    while(p)
    {
        if(p->val < x)
        {
            p1->next = p;
            p1 = p1->next;
        }
        else
        {
            p2->next = p;
            p2 = p2->next;
        }
        p = p->next;
    }
    p2->next = NULL;
    p1->next = p2Head->next;
    return p1Head->next;
}

int arr[1000] ;
int getKthFromEnd(node* head, int k){
    node *p = head;
    int top = 1000;
    while (p != NULL)
    {
        arr[--top] = p->val;
        p = p->next;
    }
    printf("k : %d\n", arr[top + k -1]);
    return arr[top + k];
}

int main(int argc, char *argv[])
{
    node* head = createlist(1);
    addlist(head, 4);
    addlist(head, 3);
    addlist(head, 2);
    addlist(head, 5);
    addlist(head, 2);
    prinlist(head);
    // prinlist(list_devide(head, 3));
    getKthFromEnd(head, 2);
}