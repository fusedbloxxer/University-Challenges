#include <stdio.h>
#include <stdlib.h>

struct list {
    int info;
    struct list * next;
};

void add(struct list **head, struct list **tail,int x) {
    struct list *z = (struct list *)malloc(sizeof(struct list));
    z->info = x;
    z->next = NULL;
    if((*head) == NULL) {
        (*head) = z;
        (*tail) = z;
    } else {
        (*tail)->next = z;
        (*tail) = z;
    }
}

int main()
{
    FILE* F = fopen("date.in", "r");
    FILE* FO = fopen("date.out", "w");
    struct list *head = NULL, *tail = NULL;
    int N, X;
    fscanf(F, "%d", &N);
    while(N-- != 0) {
        fscanf(F, "%d", &X);
        add(&head, &tail, X);
    }
    fscanf(F, "%d", &X);

    if(head->info == X) {
        struct list * z = head;
        head = head->next;
        free(z);
    }
    else
    for(struct list *c = head; c->next != NULL; c=c->next) {
        if(c->next->info == X) {
            struct list * z= c->next;
            c->next = c->next->next;
            free(z);
            break;
        }
    }

    for(struct list *c = head; c != NULL; c=c->next) {
        fprintf(FO, "%d ", c->info);
    }

    fclose(F);
    fclose(FO);
    return 0;
}
