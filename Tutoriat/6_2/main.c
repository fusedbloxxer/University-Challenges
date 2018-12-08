#include <stdio.h>
#include <stdlib.h>

struct list {
    int info;
    struct list * next;
};

void add(struct list **head, struct list **tail, int x) {
    struct list * z = (struct list *)malloc(sizeof(struct list));
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
    struct list *head_par = NULL, *tail_par = NULL;
    struct list *head_impar = NULL, *tail_impar = NULL;

    int N, X;
    fscanf(F, "%d", &N);

    while(N-- != 0) {
        fscanf(F, "%d", &X);
        if(X%2==0) {
            add(&head_par, &tail_par, X);
        } else {
            add(&head_impar, &tail_impar, X);
        }
    }

    tail_par->next=head_impar;

    for(struct list *c = head_par; c != NULL; c = c->next) {
        fprintf(FO, "%d ", c->info);
    }

    fclose(F);
    fclose(FO);
    return 0;
}
