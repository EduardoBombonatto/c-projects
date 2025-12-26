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

// insert at a specific position in the linked list
Node *insertAtPosition(Node *list, int x, int pos)
{
    if (pos == 0)
    {
        return insertHead(list, x);
    }

    Node *new = createNode(x);
    if (new == NULL)
        return list;
    
    Node *aux = list;
    for (int i = 0; i < pos - 1; i++)
    {
        if (aux == NULL)
        {
            free(new);
            return list; // position is out of bounds
        }
        aux = aux->next;
    }
    new->next = aux->next;
    aux->next = new;
    return list;
}

// delete a node at a specific position in the linked list
Node *deleteNode(Node *list , int pos)
{
    if (list == NULL)
        return NULL;

    if (pos == 0)
    {
        Node *temp = list;
        list = list->next;
        free(temp);
        return list;
    }

    Node *aux = list;
    for (int i = 0; i < pos - 1; i++)
    {
        if (aux->next == NULL)
            return list; // position is out of bounds
        aux = aux->next;
    }

    Node *temp = aux->next;
    if (temp != NULL)
    {
        aux->next = temp->next;
        free(temp);
    }
    return list;
}

void printReverse(Node *list)
{
    if (list == NULL)
        return;
    
    printReverse(list->next);
    printf("%d -> ", list->val);
    return;
}

int main()
{
    Node *head = NULL;
    head = insertHead(head, 4);
    head = insertHead(head, 3);
    head = insertHead(head, 2);
    head = insertTail(head, 1);
    head = insertAtPosition(head, 5, 2); // Insert 5 at position 2
    printList(head);
    printReverse(head);
    printf("NULL\n");
    freeMemory(head);
    return 0;
}