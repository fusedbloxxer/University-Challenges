#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char * new_string(char c, ...) {
    if(c == NULL) {
        return NULL;
    }

    va_list list;
    va_start(list, c);

    char * letter;
    char * sir = (char *)malloc(2);
    sir[0] = c; sir[1] = '\0';

    while((letter = va_arg(list, char *)) != NULL) {
        int n = strlen(sir);
        char *aux = (char *)realloc(sir, n + 2);

        if(aux != NULL) {
            sir = aux;
            sir[n] = letter;
            sir[n + 1] = '\0';
        } else { va_end(list); return sir; }
    }

    va_end(list);
    return sir;
}

int main()
{
    printf("%s", new_string('a', 'b', 'c', 'h', 'e', NULL));
    return 0;
}
