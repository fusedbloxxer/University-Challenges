#include <stdio.h>
#include <stdlib.h>

struct interval {
    int x, y;
};

int cmpInt(void *a, void *b) {
    struct interval al = *(struct interval *)a;
    struct interval bl = *(struct interval *)b;
    return al.x - bl.x;
}

int main()
{
    FILE *input = fopen("date.in", "r");
    int n = 0, length = 0;struct interval *array, *result = NULL;
    fscanf(input, "%d", &n);

    array = malloc(sizeof(struct interval) * n);

    for (int i = 0; i < n; i++) {
        fscanf(input, "%d %d", &array[i].x, &array[i].y);
    }

    qsort(array, n, sizeof(struct interval), cmpInt);

    FILE *output = fopen("date.out", "w");

    result = malloc(sizeof(struct interval));
    result[length++] = array[0];

    for (int i = 1; i < n; i++) {
        if (array[i].x <= result[length - 1].y) {
            result[length - 1].x = array[i].x;
            if (array[i].y < result[length - 1].y) {
                result[length - 1].y = array[i].y;
            }
        } else if (array[i].x > result[length - 1].y) {
            result = realloc(result, sizeof(struct interval) * ++length);
            result[length - 1] = array[i];
        }
    }

    for (int i = 0; i < length; i++) {
        fprintf(output, "%d ", result[i].x + (result[i].y - result[i].x) / 2);
    }

    free(array);
    free(result);
    fclose(input);
    fclose(output);
    return 0;
}
