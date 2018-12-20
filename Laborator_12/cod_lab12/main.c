#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "functii_1.h"
// a) Adaugati campuri structurii student si scrieti in fisier cel putin 2 instante
// b) Modificati campurile direct in fisier
// c) Cititi fisierul pentru a verifica schimbarile

typedef struct{
   // struct an* ani_studiu[8];
   char facultate[50];
   char specializare[50];
   char nume[20];
   char prenume[20];
   struct data *data_nasterii;
   unsigned long int CNP;
   float medie_generala;
   int id, grupa;
   unsigned char an_curent: 5;  // 1-8
   unsigned char status: 2;     // 0Bursier - 1Restant - 2Normal
   unsigned char plata: 1;      // 0Buget   - 1Taxa
   struct student *next;
   struct student *previous;
} student;
struct data {
    unsigned int zi, luna, an;
};
struct an {
    struct semestru * semestru[2];
};
struct semestru {
   float curs[7];
};
struct medie {
    float Anul1, Anul2, Anul3, Anul4;
};
void print(student *head, student *tail, int nrOfStudents) {
    student *index; int count;
    printf("Index | ID | Nume | Prenume | Medie | Data Nasterii | Facultate | Specializare | GRUPA | CNP | Plata | Tip\n");
    for(index = head, count = 0; count < nrOfStudents; index = index->next, count++) {
        printf("%d. %d %s %s %f %d.%d.%d %s %s %d %ld %d %d\n", count, index->id, index->nume,
               index->prenume, index->medie_generala, index->data_nasterii->zi, index->data_nasterii->luna, index->data_nasterii->an,
               index->facultate, index->specializare, index->grupa, index->CNP, index->plata, index->status);
    }
}
void add(student **head, student **tail) {
   char s[8]; unsigned char x;
   student *aux = (student*)malloc(sizeof(student));
   printf("Nume si Prenume: "); scanf("%s%s", aux->nume, aux->prenume);
   printf("Data nasterii(zi.luna.an): ");
   aux->data_nasterii = (struct data*)malloc(sizeof(struct data));
   scanf("%d.%d.%d", &aux->data_nasterii->zi, &aux->data_nasterii->luna, &aux->data_nasterii->an);
   printf("Facultate: "); fgets(aux->facultate, 50, stdin);
   printf("Specializare: "); fgets(aux->facultate, 50, stdin);
   printf("Grupa: "); scanf("%d", &(aux->grupa));
   printf("CNP: "); scanf("%d", &(aux->CNP));
   printf("ID: "); scanf("%d", &(aux->id));
   printf("Medie generala: "); scanf("%f", &(aux->medie_generala));
   printf("Buget/Taxa: "); scanf("%s", s); if(strcmp(s, "Taxa") == 0) aux->plata = 1; else aux->plata =0;
   printf("Bursier/Restant/Normal: "); scanf("%s", s);
   if(strcmp(s, "Bursier") == 0) { aux->status = 0;
   } else if(strcmp(s, "Restant") == 0) { aux->status = 1;
   } else aux->status = 2;
   printf("An curent(1-8): "); scanf("%d", &x); if(x<=8) aux->an_curent = x; else aux->an_curent = 1;

   if(*head == NULL) {
        *head = aux;
        (*head)->next = NULL;
        (*head)->previous = NULL;
        *tail = *head;
   } else {
        aux->next = *head;
        aux->previous = *tail;
        *tail = aux;
   }
}
int main() {
    FILE *F = fopen("binStudentList", "w+b");
    int linesToPrint;
    char **text = GetText("console_text.txt", &linesToPrint);
    student *head = NULL, *tail = NULL;
    int nrOfStudents = 0;

    for(;;) {
        system("cls");
        PrintText(text, linesToPrint);
        char mode[2][6] = {0};
        fscanf(stdin, "%s", mode[0]); if (strstr(mode[0], "exit") !=0 )return ;
        fscanf(stdin, "%s", mode[1]);

        printf("COMMAND: *%s*\n", mode[0]);
        if(mode[1][0] == '/'){
            if(strcmp(mode[0], "re") == 0) {
            } else if(strcmp(mode[0], "save") == 0) {
                fwrite(head, sizeof(student), nrOfStudents, F);
            } else if(strcmp(mode[0], "rf") == 0) {
            } else if(strcmp(mode[0], "pr") == 0) {
                print(head, tail, nrOfStudents);
            } else if(strcmp(mode[0], "add") == 0) {
                add(&head, &tail); nrOfStudents++;
            } else if(strcmp(mode[0], "exit") == 0) return 0;
              else printf("INPUT ERROR . . .");
        } else {
            printf("COMMAND: *%s*\n", mode[1]);
            if(strcmp(mode[0], "add") == 0) {
                int N, index;
                sscanf(mode[1], "%d", &N);
                for(index = 0; index < N; index++)
                    add(&head, &tail);
                nrOfStudents += N;
            } else if(strcmp(mode[0], "rm") == 0) {
            } else if(strcmp(mode[0], "up") == 0) {
            } else if(strcmp(mode[0], "sort") == 0){
            } else if(strcmp(mode[0], "exit") == 0) return 0;
              else printf("INPUT ERROR . . .");
        }

        printf("\nWaiting . . .");
        Sleep(5000);
    }

    fclose(F);
    return 0;
}
