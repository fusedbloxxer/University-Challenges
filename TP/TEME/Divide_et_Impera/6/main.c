#include <stdio.h>
#include <stdlib.h>

int  math_abs(int a, int b) {
    if (a - b < 0) {
        return b - a;
    }
    return a - b;
}

void findBug(int *array, int start, int end) {
    if (start <= end) {
        int middle = start + (end - start) / 2;
        int diff1 = math_abs(array[middle - 1], array[middle]);
        int diff2 = math_abs(array[middle + 1], array[middle]);

        if (diff1 > diff2) {
            printf("%d", (array[middle - 1] + array[middle]) / 2);
        } else if (diff2 > diff1) {
            printf("%d", (array[middle + 1] + array[middle]) / 2);
        } else {
            findBug(array, start, middle - 1);
            findBug(array, middle + 1, end);
        }
    }
}

int main()
{
    FILE *input = fopen("date.in", "r");
    int n, *array;
    fscanf(input, "%d", &n);
    array = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &array[i]);
    }
    findBug(array, 1, n - 2);
    fclose(input);
    return 0;
}
