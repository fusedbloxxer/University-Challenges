#include <stdio.h>
#include <stdlib.h>

struct object
{
    int id, value, quantity;
};

int cmpRatio(void *a, void *b)
{
    struct object al = *(struct object *)a;
    struct object bl = *(struct object *)b;

    return bl.quantity/bl.value - al.quantity/al.value;
}

int cmpIDvoid(void *a, void *b)
{
    struct object al = *(struct object *)a;
    struct object bl = *(struct object *)b;

    return al.id - bl.id;
}


int main()
{
    FILE *input = fopen("date.in", "r");
    FILE *output = fopen("date.out", "w");

    int n, G;
    struct object *array;
    fscanf(input, "%d %d", &n, &G);
    array = malloc(sizeof(struct object) * n);

    for (int i = 0; i < n; i++)
    {
        fscanf(input, "%d %d %d", &array[i].id, &array[i].value, &array[i].quantity);
    }

    qsort(array, n, sizeof(struct object), cmpRatio);

    float sum = 0;
    int i = 0;

    while (G > 0 && i < n)
    {
        G -= array[i].value;
        if (G < 0)
        {
            sum += ((G + array[i].value) / (float) array[i].value) * array[i].quantity;
            fprintf(output, "%d (partial)\n", array[i].id);
            break;
        }
        else
        {
            sum += array[i].quantity;
        }
        fprintf(output, "%d\n", array[i].id);
        i++;
    }
    //

    fprintf(output, "%f", sum);

    free(array);
    fclose(input);
    fclose(output);
    return 0;
}
