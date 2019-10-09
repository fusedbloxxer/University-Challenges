#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** crosswordPuzzle(int crossword_count, char** crossword, char* words, int* result_count) {

}

int main()
{
    FILE *file = fopen("date.in", "r");
    char **crossword = (char **)malloc(sizeof(char *) * 10);
    for(int i = 0; i < 10; i++) {
        crossword[i] = (char *)malloc(sizeof(char) * 11);
        fgets(crossword[i], 11, file);
    }
    char *buffer = (char *)malloc(sizeof(char) * 1000);
    fgets(buffer, 1000, file);
    /*char **word_list = (char **)malloc(sizeof(char *));
    char *p = strtok(buffer, ";");
    while(p) {
        if(n == 0) {
            word_list[n] = (char *)malloc(sizeof(char) * (strlen(p) + 1));
            strcpy(word_list[n], p);
            n++;
        } else {
            word_list = (char **)realloc(word_list, (n + 1) * sizeof(char *));
            word_list[n] = (char *)malloc(sizeof(char) * (strlen(p) + 1));
            strcpy(word_list[n], p);
            n++;
        }
        p = strtok(NULL, ";");
    }*/
    int crossword_count = 10;
    int result_count;
    crossword = crosswordPuzzle(crossword_count, crossword, buffer, &result_count);

    fclose(file);
    return 0;
}
