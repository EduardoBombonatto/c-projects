#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(int arr[], int inicio, int fim)
{
    if (inicio > fim)
        return NULL;

    int meio = (inicio + fim) / 2;

    Node *root = (Node *)malloc(sizeof(Node));
    root->val = arr[meio];
    root->left = insert(arr, inicio, meio - 1);
    root->right = insert(arr, meio + 1, fim);

    return root;
}

// print tree in order
void preOrder(Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

// print tree pre order
void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}

// print tree post order
void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
}

// free the memory allocated to the tree
void freeTree(Node *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{

    Node *root = NULL;

    int values[] = {1, 2, 3, 4, 5, 6, 7};
    int t = sizeof(values) / sizeof(values[0]);
    root = insert(values, 0, t - 1);

    printf("inOrder: ");
    inOrder(root);
    printf("\n");

    printf("preOrder: ");
    preOrder(root);
    printf("\n");

    printf("postOrder: ");
    postOrder(root);
    printf("\n");

    free(root);
    return 0;
}