#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkAnagram(char *a, char *b)
{
    if(a[0] != '\0')
    {
        char *p = strchr(b, a[0]);
        if(p != NULL)
        {
            memcpy(p, p + 1, strlen(p));
            checkAnagram(a + 1, b);
        }
        else return 0;
    }
    else
    {
        if(b[0] == '\0')
            return 1;
        return 0;
    }
}

int main()
{
    char *s1 = malloc(10);
    char *s2 = malloc(10);
    strcpy(s1, "hello");
    strcpy(s2, "olhle");

    printf("%s", (checkAnagram(s1, s2) == 1)?"true":"false");

    free(s1);
    free(s2);
    return 0;
}
