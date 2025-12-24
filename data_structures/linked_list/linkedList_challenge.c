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
Node *insertHead(Node *head, int x)
{
    Node *new = createNode(x);
    new->next = head;
    return new;
}

// free the memory of the list
void freeMemory(Node *head)
{
    Node *aux;
    while (head != NULL)
    {
        aux = head;
        head = head->next;
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

int main()
{
    Node *head = NULL;
    head = insertHead(head, 4);
    head = insertHead(head, 3);
    head = insertHead(head, 2);
    head = insertHead(head, 1);
    printList(head);
    freeMemory(head);
    return 0;
}