#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmpInt(void *a, void *b) {
    return *(int *)a - *(int *)b;
}

int main()
{
    FILE *input = fopen("date.in", "r");

    int n, *array, index2;
    fscanf(input, "%d", &n);
    array = malloc(sizeof(int) * (n + 1));

    for (int i = 1; i <= n; i++) {
        fscanf(input, "%d", &array[i]);
    }

    int min1 = INT_MAX, min2 = INT_MAX;

    qsort(array, n, sizeof(int), cmpInt);
    min1 = array[0];
    min2 = array[1];
    printf("%d %d ", 0, 1);
    array[1]

    for (int i = 1; i <= n; i++) {
        qsort(array + i, n, sizeof(int), cmpInt);

    }

    free(array);
    fclose(input);
    return 0;
}
