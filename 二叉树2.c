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

typedef struct 
{
    node *root;
} Tree;

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

void insert(Tree *tree, int value)
{
    node *nd = (node*)malloc(sizeof(node));
    nd->data = value;
    nd->left = NULL;
    nd->right = NULL;
    if (tree->root == NULL)
    {
        tree->root = nd;
    }
    else
    {
        node *temp = tree->root;
        while (temp != NULL)
        {
            if (temp->data > value)
            {
                if (temp->left == NULL)
                {
                    temp->left = nd;
                    return;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = nd;
                    return;
                }
                else
                    temp = temp->right;
            }
        }
    }
}

int get_height(node* nd)
{
    if (nd == NULL)
        return 0;
    int left_height = get_height(nd->left);
    int right_height = get_height(nd->right);
    int max = left_height;
    if (right_height > max)
        max = right_height;
    return max + 1;
}

int get_maximum(node *nd)
{
    if (nd == NULL)
        return -1;
    int m1 = get_maximum(nd->left);
    int m2 = get_maximum(nd->right);
    int m3 = nd->data;
    int max = m1;
    if (m2 > max)
        max = m2;
    if (m3 > max)
        max = m3;
    return max;
}

int _max(int *arr, int size)
{
    int n = size - 1;
    int maxn = _max(arr, n - 1);
    if (size == 1)
        return arr[0];
    else if (maxn > arr[n])
        return maxn;
    else
        return arr[n];
}
int Max(int arr[], int n)
{
    if (n >= 1)
    {
        if (Max(arr,n-1) < arr[n])
            return arr[n];
        else 
            return Max(arr, n-1);
    }
    else
        return arr[n];
}

int main()
{
    int arr[] = {6, 3, 8, 2, 5, 1, 9};
    printf("  %d\n", Max(arr, 6));
    Tree tree;
    tree.root = NULL;
    for (int i = 0; i < 7;i++)
        insert(&tree, arr[i]);
    preorder(tree.root);
    puts("\n");
    // inorder(tree.root);
    printf("%d", get_maximum(tree.root));

}