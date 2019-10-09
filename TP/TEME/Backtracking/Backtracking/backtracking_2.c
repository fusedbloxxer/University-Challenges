#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **words, *sol;
int n, length;

void printWords()
{
    for (int i = 0; i < length; i++)
    {
        printf("%c = %s\n", 'A' + i, words[i]);
    }
}

char hashCode(char *string)
{
    for (int i = 0; i < length; i++)
    {
        if (strcmp(words[i], string) == 0)
        {
            return 'a' + i;
        }
    }
}

void printSol(char *sol, int k)
{
    for (int i = 0; i <= k ; i++)
    {
        printf("%s ", words[sol[i]]);
    }
    printf("\n");
    for (int i = 0; i <= k; i++)
    {
        printf("%c ", hashCode(words[sol[i]]));
    }
    printf("\n");
}

void bk(int k, int len)
{
    for (int i = 0; i < length; i++)
    {
        sol[k] = i;
        if (k == 0)
        {

            if (words[sol[k]][0] != '.')
            {
                continue;
            }
        }

        if (strlen(words[sol[k]]) + len > n)
        {
            continue;
        }


        if (len + strlen(words[sol[k]]) == n)
        {
            if (words[sol[k]][strlen(words[sol[k]]) - 1] == '.')
            {
                printSol(sol, k);
            }
        }
        else
        {
            bk(k + 1, len + strlen(words[sol[k]]));
        }
    }
}

void bk2(int k)
{
    for (int i = 0; i < length; i++)
    {
        sol[k] = i;
        if (k == 0)
        {

            if (words[sol[k]][0] != '.')
            {
                continue;
            }
        }

        if (k + 1 == n)
        {
            if (words[sol[k]][strlen(words[sol[k]]) - 1] == '.')
            {
                printSol(sol, k);
            }
        }
        else if (k < n)
        {
            bk2(k + 1);
        }
    }
}

void bk3(int k, int n) {
    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            sol[k] = '.';
        } else {
            sol[k] = '-';
        }

        if (k == n) {
            printf(". ");
            for (int i = 0; i < k; i++) {
                printf("%c ", sol[i]);
            }
            printf(". ");
            printf("\n");
            break;
        } else bk3(k + 1, n);
    }
}

int main()
{
    FILE *input = fopen("morse.txt", "r");
    char buffer[5];
    length = 26;

    words = (char **)malloc(sizeof(char *) * length);
    for (int i = 0; i < length; i++)
    {
        fscanf(input, "%s", buffer);
        words[i] = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(words[i], buffer);
    }

    printWords();

    printf("\nWord length = ");
    scanf("%d", &n);
    sol = (char *)malloc(sizeof(char) * (n + 1));

    // bk(0, 0);  // Generare pe .-
    bk2(0);    // Generare pe a-z
    // bk3(0, n); // Generare banala

    for (int i = 0; i < length; i++)
    {
        free(words[i]);
    }
    free(words);
    free(sol);
    fclose(input);
    return 0;
}
