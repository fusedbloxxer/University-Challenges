#include <stdio.h>
#include <stdlib.h>

struct list {
    int info;
    struct list* next;
};

void add(struct list** head, struct list** tail, int X) {
    struct list * z = (struct list *)malloc(sizeof(struct list));
    z->info = X;
    z->next = NULL;

    if((*head) == NULL) {
        (*head) = z;
        (*tail) = z;
    } else {
        (*tail)->next = z;
        (*tail) =z;
    }
}

void pull(struct list **head) {
    struct list * z = (*head);
    (*head) = (*head)->next;
    free(z);
}

int main()
{
    FILE *F = fopen("lista.in", "r");
    FILE *FO = fopen("lista.out", "w");
    int K, X;
    struct list *head = NULL, *tail = NULL;
    fscanf(F, "%d", &K);

    while(fscanf(F,"%d", &X) != -1) {
        add(&head, &tail, X);
    }

    while(K-- != 0) {
        X = head->info;
        pull(&head);
        add(&head, &tail, X);
    }

    for(struct list * c = head; c != NULL; c=c->next) {
        fprintf(FO, "%d ", c->info);
    }

    fclose(F);
    fclose(FO);
    return 0;
}
