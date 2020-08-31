/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
#define MAX_RETURN_NUM 1000
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};
typedef struct TreeNode node;
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
// 整理输入输出
    int **ret = (int**)calloc(MAX_RETURN_NUM , sizeof(int*));
    *returnColumnSizes = (int*)calloc(MAX_RETURN_NUM, sizeof(int));
    *returnSize = 0;
// 建立指向节点的指针队列和两个索引
    struct TreeNode *queue[10000];
    int outIndex = 0;
    int inIndex = 0;
// 判断异常输入，进入while循环之前初始化
    if (root == NULL)
        return NULL;
    queue[inIndex++] = root;
    int levelcount = inIndex - outIndex;
// BFS
    while (levelcount > 0)
    {
        ret[*returnSize] = (int *)calloc(levelcount, sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelcount;
// 每一层的动作
        for (int i = 0; i < levelcount; i++)
        {
            if (queue[outIndex]->left != NULL)
                queue[inIndex++] = queue[outIndex]->left;
            if (queue[outIndex]->right != NULL)
                queue[inIndex++] = queue[outIndex]->right;
            ret[*returnSize][i] = queue[outIndex]->val;
            outIndex++;
        }
// 进入下一层之前的动作
        (*returnSize)++;
        levelcount = inIndex - outIndex;
    }
    return ret;
}
