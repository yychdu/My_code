
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

typedef struct List
{
    int data;
    struct List *next;
    struct List *prior;
} list;

list* createlist(list *head, int data)
{

    head->prior = NULL;
    head->next = NULL;
    head->data = data;
    list *phead = head;
    for (int i = 2; i <=3; i++)
    {
        list *body = (list *)malloc(sizeof(list));
        body->data = i;
        body->next = NULL;
        body->prior = NULL;
        body->prior = phead;
        phead->next = body;
        phead = phead->next;
    }
    return head;
}


void prin(list* head)
{
	while (head->next != NULL)
	{
        printf("%d->", head->data);
		head = head->next;
	}
    printf("%d->", head->data);
	printf("NULL");
    puts("");

    while (head != NULL)
	{
        printf("%d->", head->data);
		head = head->prior;
	}
    printf("NULL");
    puts("");
}
//头插法
void addhead(list *head, int x)
{
    if (!head)
        return;
    list *p = (list *)malloc(sizeof(list));
    p->data = x;
    head->next->prior = p;
    p->next = head->next;
    head->next = p;
    p->prior = head;
}

//尾插法
void addtail(list * head, int x)
{
    if (head ==  NULL)
        return;
    while (head->next != NULL)
    {
        head = head->next;
    }
    list *p= (list *)malloc(sizeof(list));
    p->data = x;
    p->prior = head;
    p->next = NULL;
    head->next = p;
}

list* del(list * head, int x)
{
    if (head == NULL)
        return NULL;
    list *dummy = (list *)malloc(sizeof(list));
    dummy->next = head;
    head->prior = dummy;
    list *cur = dummy;
    while (cur->next != NULL)
    { 
        if (cur->next->data == x)
        {
            cur->next->next->prior = cur;
            cur->next = cur->next->next;
        }
        cur = cur->next;
    }
    return dummy->next;
}

int main() {
    list *head = (list *)malloc(sizeof(list));
    int data = 0;
    head = createlist(head, 1);
    addhead(head, 10);
    addtail(head, 20);

    prin(head);
    head = del(head, 2);
    //prin(head);
    union MyUnion
    {
        unsigned int a;
        unsigned char b[4];
    }c;
    c.a = 0x12345678;
    printf("%x\n", c.b[0]);
    char test[8] = { 0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08 };
    int* test_p = (int*)test;
    int a = *(test_p + 1);
    printf("%#x", a);
    return 0;
}