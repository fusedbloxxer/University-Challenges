#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include "functii_1.h"
// a) Adaugati campuri structurii student si scrieti in fisier cel putin 2 instante
// b) Modificati campurile direct in fisier
// c) Cititi fisierul pentru a verifica schimbarile

typedef struct
{
    char facultate[50];
    char specializare[50];
    char nume[20];
    char prenume[20];
    unsigned long int CNP;
    float medie_generala;
    int id, grupa;
    unsigned char an_curent: 5;  // 1-8
    unsigned char status: 2;     // 0Bursier - 1Restant - 2Normal
    unsigned char plata: 1;      // 0Buget   - 1Taxa
    struct student *next;
    struct student *previous;
} student;
void print(student *head, student *tail, int nrOfStudents)
{
    student *index;
    int count;
    printf("NR STUDENTI: %d\n", nrOfStudents);
    printf("Index | ID | Nume | Prenume | Medie | Facultate | Specializare | GRUPA | CNP | Plata | Tip | An\n");
    for(index = head, count = 0; count < nrOfStudents; index = index->next, count++)
    {
        printf("%d. %d %s %s %f %s %s %d %ld %d %d %d\n", count, index->id, index->nume,
               index->prenume, index->medie_generala,index->facultate, index->specializare,
               index->grupa, index->CNP, index->plata, index->status, index->an_curent);
    }
    printf("Press any key to continue.");
    getch();
}
void add(student **head, student **tail)
{
    char s[8];
    unsigned char x;
    student *aux = (student*)malloc(sizeof(student));
    printf("Nume si Prenume: ");
    scanf("%s%s", aux->nume, aux->prenume);
    fflush(stdin);
    printf("Facultate: ");
    fgets(aux->facultate, 50, stdin);
    aux->facultate[strlen(aux->facultate) - 1] = '\0';
    printf("Specializare: ");
    fgets(aux->specializare, 50, stdin);
    aux->specializare[strlen(aux->specializare) - 1] = '\0';
    printf("Grupa: ");
    scanf("%d", &(aux->grupa));
    printf("CNP: ");
    scanf("%ld", &(aux->CNP));
    printf("ID: ");
    scanf("%d", &(aux->id));
    printf("Medie generala: ");
    scanf("%f", &(aux->medie_generala));
    printf("Buget/Taxa: ");
    scanf("%s", s);
    if(strcmp(s, "Taxa") == 0)
        aux->plata = 1;
    else
        aux->plata =0;
    printf("Bursier/Restant/Normal: ");
    scanf("%s", s);
    if(strcmp(s, "Bursier") == 0)
    {
        aux->status = 0;
    }
    else if(strcmp(s, "Restant") == 0)
    {
        aux->status = 1;
    }
    else
        aux->status = 2;
    printf("An curent(1-8): ");
    scanf("%d", &x);
    if(x<=8)
        aux->an_curent = x;
    else
        aux->an_curent = 1;

    if(*head == NULL)
    {
        *head = aux;
        (*head)->next = *head;
        (*head)->previous = *head;
        *tail = *head;
    }
    else
    {
        (*tail)->next = aux;
        aux->next = *head;
        (*head)->previous = aux;
        aux->previous = *tail;
        *tail = aux;
    }
}
void copy(student **head, student **tail, student *aux)
{
    if(*head == NULL)
    {
        *head = aux;
        (*head)->next = *head;
        (*head)->previous = *head;
        *tail = *head;
    }
    else
    {
        (*tail)->next = aux;
        aux->next = *head;
        aux->previous = *tail;
        *tail = aux;
    }
}
void re(student **head, student **tail, int poz, int *nrOfStudent)
{
    if(*head == NULL)
        return;
    else
    {
        if(*head == *tail)
        {
            free(*head);
            *head = *tail = NULL;
            (*nrOfStudent)--;
        }
        else
        {
            int index;
            student *current;
            for(index = 0, current = *head; index < poz; current = current->next, index++);
            student *st, *dr;
            st = current->previous;
            dr = current->next;

            st->next = current->next;
            dr->previous = current->previous;
            (*nrOfStudent)--;

            if(current == *head) *head = dr;
            else if(current == *tail) *tail = st;
            free(current);
        }
    }
}
int CompareA(void *a, void *b)
{
    student *al = (student *)a;
    student *bl = (student *)b;
    if(strcmp(al->nume, bl->nume) != 0)
        return strcmp(al->nume, bl->nume);
    return strcmp(al->prenume, bl->prenume);
}
int CompareM(void *a, void *b)
{
    student *al = (student *)a;
    student *bl = (student *)b;
    if(al->medie_generala > bl->medie_generala) {
        return 1;
    } else if(al->medie_generala < bl->medie_generala) {
        return -1;
    } else
        return 0;

}
int CompareF(void *a, void *b)
{
    student *al = (student *)a;
    student *bl = (student *)b;
    if(strcmp(al->facultate, bl->facultate) != 0)
        return strcmp(al->facultate, bl->facultate);
    return strcmp(al->facultate, bl->facultate);
}
int CompareG(void *a, void *b)
{
    student *al = (student *)a;
    student *bl = (student *)b;
    if(al->grupa > bl->grupa)
        return 1;
    else
        return 0;
}
int CompareS(void *a, void *b)
{
    student *al = (student *)a;
    student *bl = (student *)b;
    if(strcmp(al->specializare, bl->specializare) != 0)
        return strcmp(al->specializare, bl->specializare);
    return strcmp(al->specializare, bl->specializare);
}
void BubbleSort(student *head, int nrOfStudents, int (*f)(void *, void *), int sign)
{
    int ok;
    do
    {
        ok = 0;
        student *index_1;
        int index_2;
        for(index_1 = head, index_2 = 0; index_2 < nrOfStudents - 1; index_1 = index_1->next, index_2++)
        {
            student *next = index_1->next;
            if(f(index_1, next)*sign > 0)
            {
                student swag = *index_1;
                *index_1 = *next;
                *next = swag;

                student *p;
                p = index_1->next;
                index_1->next = next->next;
                next->next = p;

                p = index_1->previous;
                index_1->previous = next->previous;
                next->previous = p;

                ok = 1;
            }
        }
    }
    while(ok == 1);
}
int main()
{
    int linesToPrint;
    char **text = GetText("console_text.txt", &linesToPrint);
    student *head = NULL, *tail = NULL;
    int nrOfStudents = 0;

    for(;;)
    {
        system("cls");
        PrintText(text, linesToPrint);
        char mode[2][6] = {0};
        fscanf(stdin, "%s", mode[0]);
        if (strstr(mode[0], "exit") !=0 )
            return ;
        fscanf(stdin, "%s", mode[1]);

        printf("COMMAND: *%s*\n", mode[0]);
        if(mode[1][0] == '/')
        {
            if(strcmp(mode[0], "re") == 0)
            {
                if(head != NULL)
                {
                    student *index, *remove;
                    if(head->next!=NULL)
                    {
                        remove = index;
                        index = head->next;
                    }
                    while(index != tail)
                    {
                        free(remove);
                        remove = index;
                        index  = index->next;
                    }
                    free(remove);
                    head = tail = NULL;
                    nrOfStudents = 0;
                }
            }
            else if(strcmp(mode[0], "save") == 0)
            {
                FILE *F = fopen("date.txt", "r+b");
                int index;
                student *current;
                fwrite(&nrOfStudents, sizeof(int), 1, F);
                for(current = head, index = 0; index < nrOfStudents; current = current->next, index++)
                {
                    fwrite(current, sizeof(student), 1, F);
                }
                fclose(F);
            }
            else if(strcmp(mode[0], "rf") == 0)
            {
                head = NULL;
                FILE *F = fopen("date.txt", "r+b");
                int index;
                fread(&nrOfStudents, sizeof(int), 1, F);
                for(index = 0; index < nrOfStudents; index++)
                {
                    student *aux = (student *)malloc(sizeof(student));
                    fread(aux, sizeof(student), 1, F);
                    copy(&head, &tail, aux);
                }
                fclose(F);
            }
            else if(strcmp(mode[0], "pr") == 0)
            {
                print(head, tail, nrOfStudents);
            }
            else if(strcmp(mode[0], "add") == 0)
            {
                add(&head, &tail);
                nrOfStudents++;
            }
            else if(strcmp(mode[0], "exit") == 0)
                return 0;
            else
                printf("INPUT ERROR . . .");
        }
        else
        {
            printf("COMMAND: *%s*\n", mode[1]);
            if(strcmp(mode[0], "add") == 0)
            {
                int N, index;
                sscanf(mode[1], "%d", &N);
                for(index = 0; index < N; index++)
                    add(&head, &tail);
                nrOfStudents += N;
            }
            else if(strcmp(mode[0], "rm") == 0)
            {
                int N;
                sscanf(mode[1], "%d", &N);
                re(&head, &tail, N, &nrOfStudents);

            }
            else if(strcmp(mode[0], "up") == 0)
            {
                ///TO DO
                FILE *F = fopen("date.txt", "r+b");
                int N;
                sscanf(mode[1], "%d", &N);
                char facultate[50];
                printf("Denumire Facultate: ");
                fflush(stdin);
                fgets(facultate, 50, stdin);
                facultate[strlen(facultate) - 1] = '\0';
                fseek(F, sizeof(student) * N, SEEK_SET);
                fwrite(facultate, sizeof(facultate), 1, F);
                fclose(F);

            }
            else if(strcmp(mode[0], "sort") == 0)
            {
                int (*f)(void *, void*);
                int index;
                for(index = 0; index < strlen(mode[1]); index++)
                {
                    switch(mode[1][index])
                    {
                    case 'A':
                        f = CompareA;
                        break;
                    case 'M':
                        f = CompareM;
                        break;
                    case 'F':
                        f = CompareF;
                        break;
                    case 'G':
                        f = CompareG;
                        break;
                    case 'S':
                        f = CompareS;
                        break;
                    default:
                        f = CompareM;
                        break;
                    }

                    int sign;
                    if(mode[1][++index] == '-')
                        sign = -1;
                    else
                        sign = 1;
                    BubbleSort(head, nrOfStudents, f, sign);
                }
            }
            else if(strcmp(mode[0], "exit") == 0)
                return 0;
            else
                printf("INPUT ERROR . . .");
        }
    }
    return 0;
}
