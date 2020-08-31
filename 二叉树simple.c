#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

void preorder(node *nd)
{
    if (nd != NULL)
    {
        printf("%d", nd->data);
        preorder(nd->left);
        preorder(nd->right);
    }
}

void inorder(node *nd)
{
    if (nd != NULL)
    {
        inorder(nd->left);
        printf("%d", nd->data);
        inorder(nd->right);
    }
}

void postorder(node *nd)
{
    if (nd != NULL)
    {
        postorder(nd->left);
        postorder(nd->right);
        printf("%d", nd->data);
    }
}

int main()
{
    node n1, n2, n3, n4;
    n1.data = 5;
    n2.data = 6;
    n3.data = 7;
    n4.data = 8;

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = NULL;
    n3.left = NULL;
    n3.right = NULL;
    n4.left = NULL;
    n4.right = NULL;
    inorder(&n1);
    return 0;
}