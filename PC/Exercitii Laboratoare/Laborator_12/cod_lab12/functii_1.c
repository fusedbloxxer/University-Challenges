#include <stdio.h>
#include <string.h>

char** GetText(char fileName[], int *lines) {
    FILE *f = fopen(fileName, "r");
    int index;
    char buffer[1000];
    fscanf(f, "%d", lines);fgetc(f);
    char **text = (char **)malloc(*lines * sizeof(char *));
    for(index = 0; index < *lines; index++) {
        fgets(buffer, 1000, f);
        text[index] = (char *)malloc(strlen(buffer) + 1);
        strcpy(text[index], buffer);

    }
    fclose(f);

    return text;
}
void PrintText(char **text, int length) {
    int index;
    for(index = 0; index < length; index++) {
        printf("%s", text[index]);
    }
}
