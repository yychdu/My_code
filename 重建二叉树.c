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

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};
typedef struct TreeNode node;

struct TreeNode* _buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if(preorderSize == 0)
        return NULL;
    node *root = (node *)malloc(sizeof(node));
    root->val = preorder[0];
    int i;
    for (i = 0; i < inorderSize; i++)
        if(inorder[i] == preorder[0])
            break;
    root->left = buildTree(&preorder[1], i, &inorder[0], i);
    root->right = buildTree(&preorder[i + 1], preorderSize - i - 1, &inorder[i + 1], preorderSize - i - 1);
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    if (postorderSize == 0)
        return NULL;
    node* root = (node*)malloc(sizeof(node));
    root->val = postorder[postorderSize - 1];
    int i;
    for (i = 0; i < inorderSize; i++)
        if (inorder[i] == root->val)
            break;
    root->right = buildTree(&inorder[i + 1], inorderSize - i - 1, &postorder[i], postorderSize - i - 1);
    root->left = buildTree(&inorder[0], i, &postorder[0], i);
    return root;
}