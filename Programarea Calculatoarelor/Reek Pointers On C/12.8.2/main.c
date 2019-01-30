#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list_node.h"

void add(node **head, int value) {
    if(*head == NULL) {
        *head = (node *)malloc(sizeof(node));
        (*head)->value = value;
        (*head)->next = NULL;
    } else {
        node *lastNode = *head;
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = (node *)malloc(sizeof(node));
        lastNode = lastNode->next;
        lastNode->next = NULL;
        lastNode->value = value;
    }
}

node* findNodeByValue(node* head, int value) {
    while(head != NULL && head->value != value ) {
        head = head->next;
    }
    return head;
}

int main()
{
    node *head = NULL;
    int N, index;

    printf("N = "); scanf("%d", &N);
    for(index = 0; index < N; index++) {
        add(&head, index);
    }

    printf("%p", findNodeByValue(head, 10));
    return 0;
}
