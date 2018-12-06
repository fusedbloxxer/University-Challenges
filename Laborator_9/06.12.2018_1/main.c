#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sterg(char *p, int poz, int cate) {
    char *u = (char *)malloc(strlen(p));
    strcpy(u, p); // printf("%s", u);
    strcpy(u + poz, u + poz + cate);
    return u;
}

void inserez(char *p, char *s) {
    char *u = (char *)malloc(sizeof(p));
    strcpy(u,p);
    strcat(u,s);
    strcpy(p, u);
}

void replaceWord(char *text) {
    char *word_1 = (char*)malloc(30 * sizeof(char));
    char *word_2 = (char*)malloc(30 * sizeof(char));
    fscanf(stdin, "%s", word_1);
    fscanf(stdin, "%s", word_2);
    char *wordApparition = strstr(text, word_1);

    while(wordApparition != NULL) {

        char AUX[1000];
        strcpy(AUX, word_2);
        strcat(AUX, wordApparition + strlen(word_1));
        strcpy(wordApparition, AUX);
        wordApparition = strstr(wordApparition + strlen(word_2), word_1);
    }

}
// FUNCTIONEAZA

int main()
{
    char buffer[1000];
    char *u = (char *)calloc(1000,sizeof(char));
    FILE *F = fopen("date.in", "r");
    while(fgets(buffer, 1000, F) != NULL) {
        strcat(u, buffer);
    }
    fclose(F);

    F=fopen("date.out", "w");
    replaceWord(u);
    fprintf(F, "%s", u);

    return 0;
}
