#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char * concat1(int n, ...) {
    if(n <= 0) return NULL;

    va_list list;
    va_start(list, n);

    char *sequence = malloc(1);
    sequence[0] = '\0';

    for(int i = 0; i < n; i++) {
        char *sir = va_arg(list, char*);
        char *aux = realloc(sequence, strlen(sequence) + strlen(sir) + 1);
        if(aux == NULL) { va_end(list); return NULL; }
        sequence = aux;
        strcat(aux, sir);
    }

    va_end(list);
    return sequence;
}

char * concat2(char *s, ...) {
    if(s == NULL) return NULL;

    va_list list;
    va_start(list, s);

    char * sequence = malloc(strlen(s) + 1);
    strcpy(sequence, s);

    while((s = va_arg(list, char *)) != NULL) {
        char *aux = realloc(sequence, strlen(s) + strlen(sequence) + 1);
        if(aux == NULL) { va_end(list); return NULL; }
        sequence = aux;
        strcat(sequence, s);
    }

    va_end(list);
    return sequence;
}

int main()
{
    printf("%s\n", concat1(3, "Test", " ", "apel"));
    printf("%s\n", concat2("Test", " ", "apel", NULL));

    return 0;
}
