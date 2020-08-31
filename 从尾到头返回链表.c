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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode {
    int val;
    struct ListNode *next;
};
int* reversePrint(struct ListNode* head, int* returnSize){
    if(head == NULL)
    {
        *returnSize=0;
        return NULL;
    }
    int num = 0;
    *returnSize = 0;
    struct ListNode *p = head;
    // while (p != NULL)
    // {
    //     p = p->next;
    //     num++;
    // }
    // int *arr = (int *)malloc(num * sizeof(int));
    // for (int i = 0; i < num; i++)
    // {
    //     arr[num - i - 1] = head->val;
    //     head = head->next;
    // }
    // *returnSize=num;
    int *arr = (int *)malloc(sizeof(int) * 10000);
    int top = 10000;
    while (p != NULL)
    {
        p = p->next;
        arr[--top] = p->val;
        *returnSize++;
    }

    return arr;
}