#include <stdio.h>
#include <stdlib.h>

struct list
{
    int info;
    struct list * next;
};

void add(struct list **head, struct list **tail, int x)
{
    struct list * z = (struct list *)malloc(sizeof(struct list));
    z->info = x;
    z->next = NULL;
    if((*head) == NULL)
    {
        (*head) = z;
        (*tail) = z;
    }
    else
    {
        (*tail)->next = z;
        (*tail) = z;
    }
}

void insert_half(struct list *head)
{
    struct list * c;
    if(head->info%2 == 0)
    {
        struct list * z = (struct list *)malloc(sizeof(struct list));
        z->info = (head->info)/2;
        z->next = head->next;
        head->next = z;
        c = z-> next;
    }
    else
    {
        c=head->next;
        for(c; c!= NULL; c=c->next)
        {
            if(c->info%2 == 0)
            {
                struct list * z = (struct list *)malloc(sizeof(struct list));
                z->info = (c->info)/2;
                z->next = c->next;
                c->next = z;
                c = c->next;
            }
        }
    }
}

int main()
{
    FILE*F = fopen("date.in", "r");
    FILE*FO = fopen("date.out", "w");
    struct list *head = NULL, *tail = NULL;
    int X;
    while(fscanf(F, "%d", &X) != -1) {

        add(&head, &tail, X);
    }

    insert_half(head);
    for(struct list *c = head; c!= NULL; c=c->next) {
        fprintf(FO, "%d ", c->info);
    }

    fclose(F);
    fclose(FO);
    return 0;
}
