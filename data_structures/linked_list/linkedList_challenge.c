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

// print the linked list in reverse order
void printReverse(Node *list)
{
    if (list == NULL)
        return;
    
    printReverse(list->next);
    printf("%d -> ", list->val);
    return;
}
// reverse the linked list
Node *reverseList(Node *head)
{
    Node *prev = NULL, *next = NULL;
    Node *current = head;
    
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int compareTwoLinkedList(Node *list1, Node *list2)
{
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val != list2->val)
            return 0;
        list1 = list1->next;
        list2 = list2->next;
    }
    if (list1 == NULL && list2 == NULL)
        return 1;
    else
        return 0;
}

// merge two sorted linked lists
Node *mergeTwoSortedLinkedList(Node *list1, Node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    Node *mergedList = NULL;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            mergedList = insertTail(mergedList, list1->val);
            list1 = list1->next;
        }
        else
        {
            mergedList = insertTail(mergedList, list2->val);
            list2 = list2->next;
        }
    }

    // append the remaining elements
    while (list1 != NULL)
    {
        mergedList = insertTail(mergedList, list1->val);
        list1 = list1->next;
    }
    while (list2 != NULL)
    {
        mergedList = insertTail(mergedList, list2->val);
        list2 = list2->next;
    }

    return mergedList;
}


// get node from X positions from the end
int getNodeFromTail(Node *list, int pos)
{
    Node *fast = list;
    Node *slow = list;

    for (int i = 0; i < pos; i++)
    {
        if (fast == NULL)
            return -1; // position is out of bounds
        fast = fast->next;
    }
    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->val;
}
int main()
{
    Node *head = NULL;
    head = insertHead(head, 4);
    head = insertHead(head, 3);
    head = insertHead(head, 2);
    head = insertTail(head, 5);
    printList(head);
    printf("Node at position 2 from tail: %d\n", getNodeFromTail(head, 2));
    freeMemory(head);

    return 0;
}