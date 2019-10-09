#include <iostream>
#include <fstream>
#include <limits.h>
#include "utils.cpp"

using namespace std;

struct interval {
    int a, b;
};

int cmpStart(void *a, void *b) {
    struct interval al = *(struct interval *)a;
    struct interval bl = *(struct interval *)b;

    return al.a - bl.a;
}

int cmpInt(void *a, void *b) {
    int al = *(int *)a;
    int bl = *(int *)b;

    return al - bl;
}

int min(int a, int b){
    return (a < b)?a:b;
}

void printAxis(struct interval *array, int length) {
    int i1 = 0, i2 = 0, n;
    int *start = (int *)malloc(sizeof(int) * length);
    int *end   = (int *)malloc(sizeof(int) * length);

    for (int i = 0; i < length; i++) {
        start[i] = array[i].a;
        end[i] = array[i].b;
    }

    mergeSort(start, length, sizeof(int), cmpInt);
    mergeSort(end, length, sizeof(int), cmpInt);

    n = end[length - 1] - start[0] + 1;
    char *output = (char *)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) {
        output[i] = '-';
    }
    output[n] = '\0';

    while (i1 < length && i2 < length) {
        if (start[i1] < end[i2]) {
            output[start[i1] - array[0].a] = '[';
            i1++;
        } else if (start[i1] > end[i2]) {
            output[end[i2] - array[0].a] = ']';
            i2++;
        } else {
            output[start[i1] - array[0].a] = '|';
            i1++;
            i2++;
        }
    }

    while (i1 < length) {
        output[start[i1] - array[0].a] = '[';
        i1++;
    }

    while (i2 < length) {
        output[end[i2] - array[0].a] = ']';
        i2++;
    }

    printf("%s", output);
    free(output);
    free(start);
    free(end);
}

int main()
{
    FILE *input = fopen("date.in", "r");
    FILE *output = fopen("date.out", "w");
    int n; fscanf(input, "%d", &n);
    struct interval *array = (struct interval *)malloc(sizeof(struct interval) * n);

    for (int i = 0; i < n; i++) {
        fscanf(input, "%d %d", &array[i].a, &array[i].b);
    }

    mergeSort(array, n, sizeof(struct interval), cmpStart);

    int countRemoved = 0;
    struct interval pivot = array[0];

    for (int i = 1; i < n; i++) {
        if (array[i].a < pivot.b && array[i].b < pivot.b) {
            countRemoved++;
        } else {
            pivot = array[i];
        }
    }

    fprintf(output, "%d", countRemoved);
    printAxis(array, n);

    free(array);
    fclose(input);
    fclose(output);
    return 0;
}
