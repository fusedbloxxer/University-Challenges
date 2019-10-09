#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// VARIANTA _ 1

void printArray(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void cut(int *array, int start, int end) {
    if (start < end) {
        int middle = start + (end - start) / 2;
        if ((end - start + 1) % 2 == 1) {
            array[middle] = INT_MIN;
            cut(array, start, middle - 1);
            cut(array, middle + 1, end);
        }
    }
}

void elim(int **array, int poz, int *length) {
    for (int i = poz; i < *length; i++) {
        *(*array + i) = *(*array + i + 1);
    }
    *length = *length - 1;
    *array = (int *)realloc(*array, sizeof(int) * (*length));
}

int main()
{
    int n, count = 0;
    int *array;
    printf("n=");
    scanf("%d", &n);
    array = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    cut(array, 0, n - 1);
    for (int i = 1; i < n; i++) {
        if (array[i] == INT_MIN) {
            elim(&array, i--, &n);
        }
    }
    printArray(array, n);

    free(array);
    return 0;
}
