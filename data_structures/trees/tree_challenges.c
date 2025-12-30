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

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->val);
    inOrder(root->left);
    inOrder(root->right);
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
    inOrder(root); // Agora vai imprimir: 4 2 1 3 6 5 7
    printf("\n");

    free(vetor); // Libera o vetor auxiliar
    return 0;
}