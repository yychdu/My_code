/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode {
     int val;   
      ListNode *next;
   
  };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0)
            return head;
        ListNode* p = head, *q = nullptr, *node = head;
        int len = 1;
        while(p->next)
        {
            p = p->next;
            len++;
        }
        if(k == len || k%len == 0)
            return head;
        p->next = head; // 成环
        p = head;
        k = len - (k % len);
        while(p && k)
        {
            q = p;  // 新的尾节点
            p = p->next;    // 新的头结点
            k--;
        }
        q->next = nullptr;
        return p;
    }
};