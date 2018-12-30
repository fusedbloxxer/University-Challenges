#include <stdio.h>
#include <stdlib.h>
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
void encrypt(char *data, char const *key)
{
    int index, index_2;
    int N1, N2;

    N1 = strlen(data);
    N2 = strlen(key);

    for(index = 0; index < N1; index++)
    {
        for(index_2 = 0; index_2 < N2; index_2++)
        {
            if(data[index] == ('A' + index_2))
            {
                data[index] = key[index_2];
                break;
            } else if(data[index] == ('a' + index_2)) {
                data[index] = key[index_2] + 32;
                break;
            }
        }
    }
}
void decrypt(char *data, char const *key) {

    int index, index_2;
    int N1, N2;

    N1 = strlen(data);
    N2 = strlen(key);

    for(index = 0; index < N1; index++)
    {
        for(index_2 = 0; index_2 < N2; index_2++)
        {
            if(data[index] == key[index_2])
            {
                data[index] = 'A' + index_2;
                break;
            } else if(data[index] == (key[index_2] + 32)) {
                data[index] = 'a' + index_2;
                break;
            }
        }
    }
}
char * readFile(char fileName[])
{
    FILE *F = fopen(fileName, "r");
    char buffer[1000], check = 0;
    char *data = (char *)malloc(100000 * sizeof(char));
    while(fgets(buffer, 1000, F) != NULL)
    {
        if(check == 0)
        {
            strcpy(data, buffer);
            check = 1;
        }
        else
        {
            strcat(data, buffer);
        }
    }
    fclose(F);
    return data;
}
int main()
{
    char *data = readFile("date.in");
    char *key = (char *)malloc(28 * sizeof(char));
    strcpy(key, "THEKEIESINTHESHADOWSYOUW");

    if(prepare_key(key) == 1)
    {
        int index_2; printf("            ");
        for(index_2 = 0; index_2 < 26; index_2++)
            printf("%c", 'A' + index_2);
        printf("\nTHE KEY IS: %s\n", key);

        encrypt(data, key);
        printf("%s", data);

        decrypt(data, key);
        printf("\n%s", data);
    }
    else
    {
        fprintf(stderr, "AN ERROR OCCURRED!");
    }

    return 0;
}
