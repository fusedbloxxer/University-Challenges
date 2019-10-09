#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char * new_string(int n, ...) {
    va_list list;
    va_start(list, n);

    char * string = malloc(1);
    string[0]='\0';

    for(int i = 0; i < n; i++) {
        int x = strlen(string);
        string = realloc(string, x + 1);
        string[x - 1] = va_arg(list, char);
        string[x]='\0';
    }

    va_end(list);
    return string;
}

int main()
{
    printf("%s", new_string(3, 'a', 'b', 'c'));
    return 0;
}
