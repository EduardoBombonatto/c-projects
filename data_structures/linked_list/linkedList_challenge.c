#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;

} node;

node *new_node(int val)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        return NULL;
    }
    new->val = val;
    new->next = NULL;
    return new;
}

int main()
{
}