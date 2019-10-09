#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char * concat(int n, ...) {
    va_list list;
    char *sir = malloc(1);
    sir[0]='\0';
    char *current;
    va_start(list, n);

    for(int i = 0; i < n; i++) {
        current = va_arg(list, char *);
        sir = realloc(sir, strlen(sir) + strlen(current) + 1);
        strcat(sir, current);
    }

    va_end(list);
    return sir;
}

int main()
{
    printf("%s", concat(3, "hey", " ce", " faci?"));
    return 0;
}
