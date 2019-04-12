#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareInt(void *a, void *b) {
    return *(int *)a - *(int *)b;
}

void replace(void *array, int n, int dim, void *x, void *y, int (*cmp)(void *, void *)) {
    char *index;
    for(int i = 0; i < n; i++) {
        index = (char *)array + i * dim;
        if(cmp(index, x) == 0) {
            memcpy(index, y, dim);
        }
    }
}

void printArray(int *array, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}

int main()
{
    int x = 3, y = 0;
    int arr_3[] = {3, 1, 2, 4, 3, 6, 3};

    replace(arr_3, 7, sizeof(int), &x, &y, compareInt);
    printArray(arr_3, 7);

    return 0;
}
