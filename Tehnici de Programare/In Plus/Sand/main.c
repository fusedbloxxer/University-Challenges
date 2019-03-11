#include <stdio.h>
#include <stdlib.h>


struct nod {
    int info;
    struct nod * urm;
};

void modif(int *x) {
    *x = *x - 1;
}

void modif(int x) {
    x = x - 1;
}

void eliminare_elemente(struct nod **L, int x) {
    struct nod *aux;
    /// Eliminate at head
    while(*L != NULL && (*L)->info == x) {
        aux = *L;
        *L = (*L)->urm;
        free(aux);
    }
    /// Eliminate elsewhere
    if(*L != NULL) {
        aux = *L;
        while(aux->urm != NULL) {
            int checkElimination = 0;
            if(aux->urm->info == x) {
                struct nod *elim = aux->urm;
                aux->urm = elim->urm;
                free(elim);
                checkElimination = 1;
            }
            if(checkElimination == 0)
            aux = aux->urm;
        }
    }
}

void add(struct nod** head, int x) {
    if(*head == NULL) {
        *head = malloc(sizeof(struct nod));
        (*head)->info = x;
        (*head)->urm = NULL;
    } else {
        struct nod *index = *head;
        while(index->urm != NULL) {
            index = index->urm;
        }
        index->urm = malloc(sizeof(struct nod));
        index->urm->info = x;
        index->urm->urm = NULL;
    }
}

void printList(struct nod* head) {
    while(head != NULL) {
        printf("%d ", head->info);
        head = head->urm;
    }
}

int main()
{
    struct nod *lista = NULL;
    for(int i = 1; i < 10; i++) {
        add(&lista, i % 3);
    }

    eliminare_elemente(&lista, 0);
    printList(lista);
    return 0;
}
