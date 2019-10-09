#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void Array(int **array, int *n, int x, ...) {
    va_list list;
    va_start(list, x);

    if(x == 0) {
        *array = NULL;
        *n = 0;
        return;
    }

    *n = 0;
    *array = (int *)malloc(sizeof(int));
    (*array)[*n] = x; *n += 1;

    while((x = va_arg(list, int)) != 0) {
        int *aux =  (int *)realloc(*array, (*n + 1) * sizeof(int));
        if(aux != NULL) {
            *array = aux;
            (*array)[*n] = x;
            *n += 1;
        } else { va_end(list); return NULL; }
    }

    va_end(list);
}

void printArray(int **array, int *n) {
    for(int i = 0; i < *n; i++) {
        printf("%d ", (*array)[i]);
    }

    free(*array);
    *array = NULL;
    *n = 0;
}

int main()
{
    int *array, n;
    Array(&array, &n, 1, 2, -5, 0);
    printArray(&array, &n);

    return 0;
}
