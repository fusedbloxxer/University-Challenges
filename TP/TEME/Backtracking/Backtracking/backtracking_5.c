#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m, n;
char **words;
int *sol;

void printSolution(int k)
{
    for (int i = 0; i <= k; i++)
    {
        printf("%s ", words[sol[i]] + 1);
    }
    printf("\n\n");
}

void bk(int k)
{
    int check = 0;
    for (int i = 0; i < m; i++)
    {
        sol[k] = i;

        if (k != 0)
        {
           // printf("%s: %c %c - ", words[sol[k - 1]] + 1, words[sol[k - 1]][words[sol[k - 1]][0] - 1], words[sol[k - 1]][words[sol[k - 1]][0]]);
           // printf("%s: %c %c\n", words[sol[k]] + 1, words[sol[k]][1], words[sol[k]][2]);

            if (words[sol[k]][1] != words[sol[k - 1]][words[sol[k - 1]][0] - 1]
                    || words[sol[k]][2] != words[sol[k - 1]][words[sol[k - 1]][0]])
            {
                continue;
            }
        }

        check = 0;
        for (int j = 0; j < k; j++)
        {
            if (sol[k] == sol[j])
            {
                check = 1;
                break;
            }
        }

        if (check == 0)
        {

            if (k + 1 == n)
            {
               printSolution(k);
            }
            else if (k < n)
            {
                bk(k + 1);
            }
        }
    }
}

int main()
{
    FILE *input = fopen("cuvinte.txt", "r");
    fscanf(input, "%d", &m);
    char buffer[100];
    words = (char **)malloc(sizeof(char *) * m);
    for (int i = 0; i < m; i++)
    {
        fscanf(input, "%s", buffer);
        words[i] = (char *)malloc(sizeof(char) * (strlen(buffer) + 2));
        strcpy(words[i] + 1, buffer);
        words[i][0] = strlen(buffer);
    }

    printf("N = ");
    fscanf(stdin, "%d", &n);
    sol = (int *)malloc(sizeof(int) * n);

    bk(0);

    for (int i = 0; i < m; i++)
    {
        free(words[i]);
    }
    free(sol);
    free(words);
    fclose(input);
    return 0;
}
