#include <stdio.h>
#include <stdlib.h>

struct spectacol {
    int id, start, end;
};

int compareEndTime(void *a, void *b) {
    struct spectacol al = *(struct spectacol *)a;
    struct spectacol bl = *(struct spectacol *)b;

    return al.end - bl.end;
}

int main()
{
    FILE *input = fopen("date.in", "r");
    int n, length = 0;struct spectacol* array, *ids = NULL;

    fscanf(input, "%d", &n);
    array = malloc(sizeof(struct spectacol) * n);

    for (int i = 0; i < n; i++) {
        fscanf(input, "%d %d %d", &array[i].id, &array[i].start, &array[i].end);
    }

    fclose(input);

    qsort(array, n, sizeof(struct spectacol), compareEndTime);

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
        if (i == 0) {
            ids = malloc(sizeof(struct spectacol));
            ids[length++] = array[0];
        } else {
            if (ids[length - 1].end <= array[i].start) {
                ids = realloc(ids, sizeof(struct spectacol) * ++length);
                ids[length - 1] = array[i];
            }
        }
    }

    FILE *output = fopen("date.out", "w");

    for (int i = 0; i < length; i++) {
        fprintf(output, "%d ", ids[i].id);
    }

    free(ids);free(array);
    fclose(output);
    return 0;
}
