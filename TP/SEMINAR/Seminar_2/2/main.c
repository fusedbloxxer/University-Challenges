#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char * prefix(int n, ...)
{
    va_list list;
    va_start(list, n);
    char * current = va_arg(list, char *);
    char * sir = malloc(sizeof(current) + 1);
    strcpy(sir, current);

    for(int i = 1; i < n; i++)
    {
        current = va_arg(list, char *);
        if(current[0] != sir[0])
        {
            free(sir);
            va_end(list);
            return NULL;
        }
        while(strstr(current, sir)!=current && strlen(sir) > 0)
        {
            int n = strlen(sir);
            sir[n - 1] = '\0';
            sir = realloc(sir, n - 1);
        }
    }
    va_end(list);
    return sir;
}

int main()
{
    printf("%s", prefix(3, "bara", "baritim", "barca"));

    return 0;
}
