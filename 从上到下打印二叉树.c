#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#define MAXLINE 2000
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};
typedef struct TreeNode node;
int* levelOrder(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (root == NULL) return NULL;
    node* queue[MAXLINE];
    int front = 0;
    int tail = 0;
    queue[tail++] = root;
    int *res = (int *)malloc(sizeof(int) * MAXLINE);
    while (front < tail)
    {
        node* tmp = queue[front++];
        res[(*returnSize)++] = tmp->val;
        if (tmp->left != NULL)
            queue[tail++] = tmp->left;
        if (tmp->right != NULL)
            queue[tail++] = tmp->right;

    }
    return res;
}