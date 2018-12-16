#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compress(char* sir, int lungime)
{
    int index, index2, count;
    for(index = 0; index < lungime; index++)
        if(sir[index]<'a' || sir[index]>'z') return 0;

    char *aux = (char *)malloc(lungime + 1);
    for(index = 0; index < lungime - 1; index++)
    {
        count = 0;
        for(index2 = index + 1; index2 < lungime; index2++)
        {
            if(sir[index] == sir[index2])
            {
                strcpy(sir + index2, sir + index2 + 1);
                index2--;
                lungime--;
                count++;
            } else index2 = lungime; // With or without this? Case not shown in the example: aabbaacc -> a4b2c2 or a2b2a2c2 ?
        }
        int copy_count = count + 1;
        count = 0;
        while(copy_count > 0)
        {
            count = count * 10 + copy_count%10;
            copy_count /= 10;
        }
        while(count > 1)
        {
            strcpy(aux, sir + index);
            strcpy(sir + index + 1, aux);
            sir[index + 1] = count%10 + '0';
            count /= 10;
            index++;
            lungime++;
        }
    }
    free(aux);
    return strlen(sir);
}

int main()
{
    char s[1000];
    fscanf(stdin, "%s", s);

    printf("%d\n%s", compress(s, strlen(s)), s);
    return 0;
}
