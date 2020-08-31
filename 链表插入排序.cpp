/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = (ListNode*)malloc(sizeof(ListNode)), *pre;
        dummy->next = head;
        while (head && head->next)
        {
            while (head->val <= head->next->val)
            {
                head = head->next;
                continue;
            }
            pre = dummy;
            while (pre->next->val < head->next->val)
                pre = pre->next;
            ListNode *tmp = head->next;
            head->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return dummy->next;
    }
};