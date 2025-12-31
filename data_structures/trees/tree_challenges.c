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
    int t;
    scanf("%d", &t);

    int *vetor = (int *)malloc(t * sizeof(int));

    for (int i = 0; i < t; i++)
    {
        scanf("%d", &vetor[i]);
    }

    Node *root = insert(vetor, 0, t - 1);

    printf("inOrder: ");
    inOrder(root);
    printf("\n");

    printf("preOrder: ");
    preOrder(root);
    printf("\n");

    free(vetor);
    free(root);
    return 0;
}