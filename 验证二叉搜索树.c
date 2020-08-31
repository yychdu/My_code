
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "limits.h"
#include "math.h"
#include "stdbool.h"
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

void inorder(struct TreeNode *root, int *arr, int *i)
{
    if (root)
    {
        inorder(root->left, arr, i);
        arr[(*i)++] = root->val;
        inorder(root->right, arr, i);
    }
}

bool isValidBST(struct TreeNode* root){
    if (!root)
        return 1;
    int arr[10000];
    int i = 0;
    memset(arr, 0, sizeof(arr));
    inorder(root, arr, &i);
    for (int j = 1; j < i; j++)
    {
        if (arr[j] <= arr[j - 1])
            return false;
    }
    return true;
}

int main(void)
{
    struct TreeNode root;
    struct TreeNode *tree = &root;
    tree->right = NULL;
    tree->val = 1;
    tree->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree->left->val = 1;
    tree->left->left = NULL;
    tree->left->right = NULL;
    printf("%d", isValidBST(tree));
}