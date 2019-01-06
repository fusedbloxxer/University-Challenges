#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list_node.h"

node* sll_reverse( node *first )
{
    if(first == NULL)
        return NULL;
    else
    {
        node *previous, *next = first;
        previous = NULL;
        next = next->next;

        while(next != NULL)
        {
            first->next = previous;
            previous = first;
            first = next;
            next = next->next;
        }
        first->next = previous;
        return first;
    }
}

void add(node **head, int value)
{
    if(*head == NULL)
    {
        *head = (node *)malloc(sizeof(node));
        (*head)->value = value;
        (*head)->next = NULL;
    }
    else
    {
        node *lastNode = *head;
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = (node *)malloc(sizeof(node));
        lastNode = lastNode->next;
        lastNode->next = NULL;
        lastNode->value = value;
    }
}

int main()
{
    node *head = NULL;
    int N, index;
    printf("N = ");
    scanf("%d", &N);
    for(index = 0; index < N; index++)
    {
        add(&head, index);
    }
    node* current;
    for(current = head; current != NULL; current = current->next)
    {
        printf("%d ", current->value);
        if((current->value)%20 == 0 && current->value != 0)
            printf("\n");
    }
    printf("\n\n");
    head = sll_reverse(head);
    for(current = head; current != NULL; current = current->next)
    {
        printf("%d ", current->value);
        if((current->value)%20 == 0 && current->value != 0)
            printf("\n");
    }
    return 0;
}
