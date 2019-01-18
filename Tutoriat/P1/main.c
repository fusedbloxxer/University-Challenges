#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char nume[30], prenume[30];
    int grupa, an;
    float medie_admitere;
    struct student *next;
};
struct student* get(struct student *head, int index) {
    int i = 0;

    while (head != NULL) {
        if (index == i)
            return head;
        else
            head = head->next;

        i++;
    }
}
void addAtHead(struct student **head, const char *nume, const char *prenume, int grupa, int an, float medie_admitere) {
    if (*head == NULL) {
        *head = (struct student *)malloc(sizeof(struct student));
        (*head)->next = NULL;
        strcpy((*head)->nume, nume);
        strcpy((*head)->prenume, prenume);
        (*head)->grupa = grupa;
        (*head)->an = an;
        (*head)->medie_admitere = medie_admitere;

    } else {
        struct student *aux = (struct student *)malloc(sizeof(struct student));
        aux->an = an;
        aux->grupa = grupa;
        aux->medie_admitere = medie_admitere;
        strcpy(aux->nume, nume);
        strcpy(aux->prenume, prenume);
        aux->next = *head;
        *head = aux;
    }
}
void grupa(struct student *head, int x) {
    printf("Studentii din grupa %d sunt:\n", x);

    while (head != NULL) {
        if (head->grupa == x)
            printf("%s %s %d %d %f\n", head->nume, head->prenume, head->grupa, head->an, head->medie_admitere);

        head = head->next;
    }

    printf("\n");
}
void readStudents(const char *file_name, struct student **head) {
    FILE *F = fopen(file_name, "r");
    int N;
    fscanf(F, "%d", &N);
    char nume[30], prenume[30];
    int an, grupa;
    float medie_admitere;

    while (N-- != 0) {
        fscanf(F, "%s", nume);
        fscanf(F, "%s", prenume);
        fscanf(F, "%d", &grupa);
        fscanf(F, "%d", &an);
        fscanf(F, "%f", &medie_admitere);
        addAtHead(head, nume, prenume, grupa, an, medie_admitere);
    }

    fclose(F);
}
int compareTo(void *a, void *b) {
    struct student *al = (struct student *)a;
    struct student *bl = (struct student *)b;
    int r = strcmp(al->nume, bl->nume);

    if (r != 0)
        return r;
    else
        return bl->medie_admitere - al->medie_admitere;
}
void BubbleSort(int n, struct student *head) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            struct student *s1 = get(head, i);
            struct student *s2 = get(head, j);

            if (compareTo((void *)s1, (void *)s2) > 0) {
                struct student aux;

                aux = *s1;
                *s1 = *s2;
                *s2 = aux;
                aux.next  = s1->next;
                s1->next  = s2->next;
                s2->next  = aux.next;
            }
        }
    }
}
int main() {
    struct student *head = NULL;
    readStudents("date.txt", &head);
    grupa(head, 152);
    printf("\n");
    BubbleSort(8, head);
    printf("\n");
    grupa(head, 152);
    return 0;
}
