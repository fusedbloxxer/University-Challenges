#include <stdio.h>
#include <stdlib.h>

/*
Fișierul date.in conține pe prima linie numerele n și k (k<=n<=10000),
apoi n numere întregi, reprezentând elementele unei mulțimi.

Să se determine o submulțime S a mulțimii date, a
stfel încât aceasta să aibă cardinalul k și suma elementelor lui S să fie maximă. Datele se scriu în fișierul date.out.
*/

int compareInt(void *a, void *b) {
    return *(int *)b - *(int *)a;
}

int main()
{
    FILE *input = fopen("date.in", "r");
    int n, k, *array;
    fscanf(input, "%d %d", &n, &k);

    array = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &array[i]);
    }

    qsort(array, n, sizeof(int), compareInt);

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += array[i];
        printf("%d ", array[i]);
    }

    printf("\nThe sum is: %d", sum);

    free(array);
    fclose(input);
    return 0;
}
