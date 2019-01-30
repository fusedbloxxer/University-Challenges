#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list_node.h"

int sll_remove( struct NODE **rootp, struct NODE *node ) {
    if(*rootp == NULL) {
        return 0;
    } else if(*rootp == node) {
        *rootp = (*rootp)->next;
        free(node);
        return 1;
    } else {
        struct NODE *current = *rootp;
        while(current->next->next != NULL && current->next != node ) {
            current = current->next;
        }
        if(current->next  == node) {
            current->next = node->next;
            free(node);
            return 1;
        }
        return 0;
    }
}

void add(struct NODE **head, int value)
{
    if(*head == NULL)
    {
        *head = (struct NODE *)malloc(sizeof(struct NODE));
        (*head)->value = value;
        (*head)->next = NULL;
    }
    else
    {
        struct NODE *lastNode = *head;
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = (struct NODE *)malloc(sizeof(struct NODE));
        lastNode = lastNode->next;
        lastNode->next = NULL;
        lastNode->value = value;
    }
}

int main()
{
    struct NODE *head = NULL;
    int N, index;
    printf("N = ");
    scanf("%d", &N);
    for(index = 0; index < N; index++)
    {
        add(&head, index);
    }

    sll_remove(&head, head->next);
    sll_remove(&head, head->next);
    sll_remove(&head, head->next);

    struct NODE* current;
    for(current = head; current != NULL; current = current->next)
    {
        printf("%d ", current->value);
        if((current->value)%20 == 0 && current->value != 0)
            printf("\n");
    }

    return 0;
}
