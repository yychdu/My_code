#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 struct TreeNode {
     int val;
    struct TreeNode *left;
      struct TreeNode *right;
 };
bool helper(struct TreeNode * A, struct TreeNode * B)
{
    if (A == NULL || B == NULL)
        return !B;
    if (A->val != B->val)
        return false;
    return helper(A->left, B->left) && helper(A->right, B->right);
}

bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
    if (A == NULL || B == NULL)
        return !B;
    return isSubStructure(A->left, B) || isSubStructure(A->right, B) || helper(A, B);
}
