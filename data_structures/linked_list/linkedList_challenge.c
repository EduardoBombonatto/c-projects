#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;

} Node;

Node *createNode(int val)
{
    Node *new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
    {
        return NULL;
    }
    new->val = val;
    new->next = NULL;
    return new;
}

// insert at the head of the list
Node *insertHead(Node *list, int x)
{
    Node *new = createNode(x);
    new->next = list;
    return new;
}

// free the memory of the list
void freeMemory(Node *list)
{
    Node *aux;
    while (list != NULL)
    {
        aux = list;
        list = list->next;
        free(aux);
    }
}

// print the linked list
void printList(Node *list)
{
    while (list != NULL)
    {
        printf("%d -> ", list->val);
        list = list->next;
    }
    printf("NULL\n");
}

// insert at the tail of the linked list
Node *insertTail(Node *list, int x)
{
    Node *new = createNode(x);
    if (new == NULL)
        return list;

    if (list == NULL)
        return new;

    Node *aux = list;
    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    aux->next = new;
    return list;
}

int main()
{
    Node *head = NULL;
    head = insertHead(head, 4);
    head = insertHead(head, 3);
    head = insertHead(head, 2);
    head = insertTail(head, 1);
    printList(head);
    freeMemory(head);
    return 0;
}