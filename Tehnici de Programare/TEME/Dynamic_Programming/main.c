#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void sequence(int *array, int n, int x) {
    int *vals = malloc(sizeof(int) * n);
    int *succ = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        vals[i] = 1;
        int max = INT_MIN;
        int poz = -1;
        for (int j = 0; j < i; j++) {
            if (array[i] - array[j] >= x
                && max < vals[j]) {
                    poz = j;
                    max = vals[j];
                }
        }
        if (poz != -1) {
            succ[i] = poz;
            vals[i] += max;
        } else succ[i] = -1;
    }
    /*
    printArr(array, n);
    printArr(vals, n);
    printArr(succ, n);
    */
    int i = n - 1;
    while(succ[i] != -1) {
        printf("%d ", array[i]);
        i = succ[i];
    }
    printf("%d", array[i]);

    free(succ);
    free(vals);
}

void printArr(int *array, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int n, x, *array;
    FILE *input = fopen("date.in", "r");
    fscanf(input, "%d %d", &n, &x);
    array = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &array[i]);
    }

    // TODO PD
    sequence(array, n, x);

    fclose(input);
    free(array);
    return 0;
}
