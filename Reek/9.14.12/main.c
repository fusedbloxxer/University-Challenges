#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int prepare_key(char *key)
{
    int index, index_2;
    int N = strlen(key);

    if(strcmp(key, "") == 0) return 0;
    for(index = 0; index < N; index++)
    {
        if(key[index] > 'z' || (key[index] > 'Z' && key[index] < 'a') || key[index] < 'A')
            return 0;
        if(key[index] >= 'a' && key[index] <= 'z')
            key[index] -= 32;
    }

    for(index = 0; index < N - 1; index++)
        for(index_2 = index + 1; index_2 < N; index_2++)
        {
            if(key[index] == key[index_2])
            {
                strcpy(key+index_2, key+index_2+1);
                index_2--;
                N--;
            }
        }

    index = 'A';
    while(index <= 'Z') {
        if(strchr(key, index) == NULL) {
            key[N++] = index;
        } else {
            index++;
        }
    }
    key[N] = '\0';
    return 1;
}
int main()
{
    char *string = (char *)malloc(27 * sizeof(char));
    strcpy(string, "trailblazers");
    prepare_key(string);
    printf("%s", string);
    return 0;
}
