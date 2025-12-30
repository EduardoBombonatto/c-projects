#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        Node *new = (Node *)malloc(sizeof(Node));
        new->val = val;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    else
    {
        Node *cur;
        if (val <= root->val)
        {
            cur = insert(root->left, val);
            root->left = cur;
        }
        else
        {
            cur = insert(root->right, val);
            root->right = cur;
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;

    int t;
    int data;

    scanf("%d", &t);

    while (t-- > 0)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }

    return 0;
}