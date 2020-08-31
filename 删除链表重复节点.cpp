#include <cstdio>
#include <cstdlib>
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
       if (pHead==NULL || pHead->next==NULL)
           return pHead;
       ListNode* Head = (ListNode *)malloc(sizeof(ListNode));
       Head->next = pHead;
       ListNode *pre = Head;
       ListNode *last = Head->next;
       while (last != NULL)
       {
           if (last->next != NULL && last->val == last->next->val)
           {
               while (last->next != NULL && last->val == last->next->val)
               {
                   last = last->next;
               }
               pre->next = last->next;
                last = last->next;
           } 
           else 
           {
               pre = pre->next;
               last = last->next;
           }
       }
       return Head->next;
    }
};

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *pre = head;
        ListNode *last = pre->next;
        // ListNode *pre = head;
        // ListNode *last = head->next;
        while (last != NULL)
        {
            
            while (last != NULL && last->val == pre->val)
                last = last->next;        
            pre->next = last;  
            pre = pre->next;
            last = last->next;
        }
        return head;
    }
    
};