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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (1)
        {
            if (!fast || !fast->next)
                return NULL;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};