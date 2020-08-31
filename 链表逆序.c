/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
 
 */
int* reversePrint(struct ListNode* head, int* returnSize){
    if(head==NULL){
        *returnSize=0;
        return NULL;
    }
    int num = 0;
    struct ListNode *p = head;
    while (p != NULL)
    {
        p = p->next;
        num++;
    }
    int *arr = (int *)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
    {
        arr[num - i - 1] = head->val;
        head = head->next;
    }
    *returnSize=num;
    return arr;
}

 if(head==NULL){
        *returnSize=0;
        return NULL;
    }
    struct ListNode*p=head;
    int num=0;
    while(p!=NULL){
        p=p->next;
        num++;
    }
    int *res=(int *)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){
        res[num-1-i]=head->val;
        head=head->next;
    }
    *returnSize=num;
    return res;


#define STACK_SIZE 10000

int* reversePrint(struct ListNode* head, int* returnSize)
{
    int size;
    int top;
    int *stack;

    if (head == NULL) {
        *returnSize = 0;
        return NULL;
    }

    stack = malloc(sizeof(int) * STACK_SIZE);
    size = 0;
    top = STACK_SIZE;
    while (head != NULL) {
        stack[--top] = head->val;
        size++;
        head = head->next;
    }

    *returnSize = size;
    return &stack[top];
}

作者：walen918
链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/solution/yong-zhan-lai-bao-cun-lian-biao-de-zhi-by-walen918/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。