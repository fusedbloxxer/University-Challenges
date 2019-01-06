#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    struct node *next;
} node;

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

int countNodes(node *head) {
    int count = 1;
    while(head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}

int main()
{
    node *head = NULL;
    int N, index;

    printf("N = "); scanf("%d", &N);
    for(index = 0; index < N; index++) {
        add(&head, index);
    }

    printf("%d", countNodes(head));
    return 0;
}
