#include <stdio.h>
#include <stdlib.h>

char *sequence;

void bk(int k, int open, int n)
{
    int check;
    for (int i = 0; i <= 1; i++)
    {
        check = 0;
        if (i == 0)
        {
            sequence[k] = '(';
        }
        else
        {
            sequence[k] = ')';
        }

        if (open > n / 2)
        {
            check = 1;
        }

        if (k - open > open)
        {
            check = 1;
        }

        if (check == 0)
        {
            if (k == n)
            {
                printSequence(n);
                return;
            }
            else
            {
                if (i == 0)
                    bk(k + 1, open + 1, n);
                else
                    bk(k + 1, open, n);
            }
        }

    }
}

void printSequence(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("n=");
    scanf("%d", &n);

    sequence = (char *)malloc(sizeof(char) * (n + 1));
    if (n % 2 == 0)
    {
        bk(0, 0, n);
    }
    else
    {
        printf("N trebuie sa fie par !!");
    }

    free(sequence);
    return 0;
}
