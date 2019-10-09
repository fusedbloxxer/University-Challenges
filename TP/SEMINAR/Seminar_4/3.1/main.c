#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Fișierul date.in conține cel mult 10000 de numere întregi, reprezentând elementele unei mulțimi.
Să se determine o submulțime S a mulțimii date, astfel încât suma elementelor lui S să fie maximă. Datele se scriu în fișierul date.out.
*/

int main()
{
    FILE *input = fopen("date.in", "r");
    int *subset = NULL, n = 0, currentElement, maxNeg = INT_MIN;

    while (fscanf(input, "%d", &currentElement) != -1)
    {
        if (n == 0)
        {
            if (currentElement < 0)
            {
                if (maxNeg < currentElement)
                {
                    maxNeg = currentElement;
                }
            }
            else
            {
                subset = malloc(sizeof(int) * ++n);
                subset[n - 1] = currentElement;
            }
        }
        else
        {
            if (currentElement >= 0)
            {
                subset = realloc(subset, sizeof(int) * ++n);
                subset[n - 1] = currentElement;
            }
        }
    }

    FILE *output = fopen("date.out", "w");
    if (n == 0)
    {
        if (maxNeg != INT_MIN)
        {
            fprintf(output, "%d", maxNeg);
        }
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += subset[i];
            fprintf(output, "%d ", subset[i]);
        }
        fprintf(output, "\nSum is: %d", sum);
    }

    free(subset);
    fclose(output);
    fclose(input);
    return 0;
}
