#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct produs
{
    char nume[30];
    struct magazin *m;
    int x, y;
    int nOfMagazine;
};
struct nod
{
    struct produs p;
    struct nod *next;
};
struct magazin
{
    char nume[30];
    float pret;
    int gps_x;
    int gps_y;
};
void readProducts(int *N, struct produs **head)
{
    FILE *f = fopen("date.in", "r");
    fscanf(f, "%d", N);
    *head = (struct produs *)malloc(*N * sizeof(struct produs));
    int i;
    for(i = 0; i < *N; i++)
    {
        int j;
        fscanf(f, "%s", (*(*head + i)).nume);
        fscanf(f, "%d", &(*head + i)->nOfMagazine);
        //fscanf(f, "%d", &head[i].nOfMagazine);
        //fscanf(f, "%d", &head[i].nOfMagazine);

        (*head + i)->m = (struct magazin *)malloc((*head + i)->nOfMagazine * sizeof(struct magazin));
        for(j = 0; j < (*head + i)->nOfMagazine; j++)
        {
            fscanf(f, "%s", (*head + i)->m[j].nume);
            fscanf(f, "%f", &(*head + i)->m[j].pret);
            fscanf(f, "%d", &(*head + i)->m[j].gps_x);
            fscanf(f, "%d", &(*head + i)->m[j].gps_y);
        }
    }
    fclose(f);
    return head;
}
void addMagazin(struct produs* head, int N, char *numeProdus, char *numeMagazin, int gps_x, int gps_y)
{
    int i;
    float pret;

    for(i = 0; i < N; i++)
    {
        if(strcmp(head[i].nume, numeProdus) == 0)
        {
            int j;
            pret = head[i].m[0].pret;
            for(j = 1; j < head[i].nOfMagazine; j++)
            {
                if(pret > head[i].m[j].pret)
                    pret = head[i].m[j].pret;
            }

            head[i].m = (struct magazin *)realloc(head[i].m, sizeof(struct magazin) * (head[i].nOfMagazine + 1));
            head[i].m[head[i].nOfMagazine].gps_x = gps_x;
            head[i].m[head[i].nOfMagazine].gps_y = gps_y;
            head[i].m[head[i].nOfMagazine].pret  = pret;
            strcpy(head[i].m[head[i].nOfMagazine].nume, numeMagazin);

            head[i].nOfMagazine++;
            return;
        }
    }
}
void afis(struct produs *head, int N, int LINE)
{
    int i;
    for(i = 0; i < N; i++)
    {
        int j;
        printf("%s ", head[i].nume);
        printf("%d: \n", head[i].nOfMagazine);

        for(j = 0; j < head[i].nOfMagazine; j++)
        {
            printf("%s ", head[i].m[j].nume);
            printf("%.2f ", head[i].m[j].pret);
            printf("%d ", head[i].m[j].gps_x);
            printf("%d ", head[i].m[j].gps_y);
            printf("\n");
        }
        printf("\n");
    }
    if(LINE == 1)
    printf("--------------------\n");
}
int compareDistance(void *a, void *b)
{
    struct produs *al = (struct produs *)a;
    struct produs *bl = (struct produs *)b;
    int P1 = 0, P2 = 0;
    int i;
    for(i = 0; i < al->nOfMagazine; i++)
    {
        float d = sqrt(pow((al->m[i].gps_x - al->x), 2) + pow((al->m[i].gps_y - al->y), 2));
        if(d < 5)
            P1++;
    }
    for(i = 0; i < bl->nOfMagazine; i++)
    {
        float d = sqrt(pow((bl->m[i].gps_x - bl->x), 2) + pow((bl->m[i].gps_y - bl->y), 2));
        if(d < 5)
            P2++;
    }
    // printf("Produs 1: %s, d = %d\nProdusul 2: %s, d = %d\n\n", al->nume, P1, bl->nume, P2);
    if(P1 > P2)
        return 1;
    else if(P1 < P2)
        return -1;
    else
        return 0;
}
void sortByLocation(struct produs *head, int N, int x, int y)
{
    int i;
    for(i = 0; i < N; i++)
    {
        head[i].x = x;
        head[i].y = y;
    }
    qsort(head, N, sizeof(struct produs), compareDistance);
}
void adaugare(struct nod **L, struct produs *P)
{
    if(*L == NULL)
    {
        *L = (struct nod *)malloc(sizeof(struct nod));
        (*L)->p = *P;
        (*L)->next = NULL;
    }
    else
    {
        /// cazul pentru inserarea inaintea capului.
        int r = compareDistance((void *)P, (void *)&((*L)->p));
        if(r == -1)
        {
            struct nod *aux = (struct nod*)malloc(sizeof(struct nod));
            aux->p = *P;
            aux->next = *L;
            *L = aux;
        }
        else
        {
            struct nod *current = *L;
            while(current->next != NULL && compareDistance((void *)P, (void *)&(current->next->p))>=0)
            {
                current = current->next;
            }

            struct nod* aux = (struct nod*)malloc(sizeof(struct nod));
            aux->p = *P;
            aux->next = current->next;
            current->next = aux;
        }
    }
}
void afisList(struct nod *head)
{
    while(head != NULL)
    {
        afis(&(head->p), 1, 0);
        head = head->next;
    }
    printf("--------------------\n");
}
int main()
{
    int N, i;

    /// Exercitiul 1:
    struct produs *list;
    readProducts(&N, &list);
    printf("PRODUSE CITITE:\n\n");
    afis(list, N, 1);

    /// Exercitiul 2:
    addMagazin(list, N, "Lapte", "Laptarie_3", 5, 11);
    printf("MAGAZIN ADAUGAT:\n\n");
    afis(list, N, 1);

    /// Exercitiul 3:
    sortByLocation(list, N, 50, 50);
    printf("VECTOR SORTAT CRESCATOR:\n\n");
    afis(list, N, 1);

    /// Exercitiul 4:
    struct nod *head = NULL;
    /// Le punem pe dos si vedem daca se respecta ordinea.
    /// Daca distanta a doua sau mai multe produse este egala(primele 3 produse din fisier au d = 0) se pun in alta ordine, deoarece nu are relevanta.
    for(i = N - 1; i >= 0; i--)
        adaugare(&head, &list[i]);
    printf("LISTA INITIALIZATA, ORDONATA CRESCATOR:\n\n");
    afisList(head);
    return 0;
}
