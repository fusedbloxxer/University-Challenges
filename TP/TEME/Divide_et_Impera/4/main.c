#include <stdio.h>
#include <stdlib.h>

void munte(int *array, int start, int end, FILE* output)
{
    if (start <= end)
    {
        int middle = start + (end - start) / 2;
        int diff = array[middle] - array[middle + 1];
        if (array[middle] - array[middle - 1] > 0 &&
            diff > 0) {
                printf("Munte: %d", array[middle]);
                return;
            } else if (diff > 0) {
                munte(array, start, middle - 1, output);
            } else {
                munte(array, middle + 1, end, output);
            }
    }
}

int main()
{
    FILE *input = fopen("date.in", "r");
    FILE *output = fopen("date.out", "w");
    int n, *array;
    fscanf(input, "%d", &n);
    if (n >= 3)
    {
        array = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            fscanf(input, "%d", &array[i]);
        }
        munte(array, 1, n - 2, output);
        free(array);
    }
    fclose(output);
    fclose(input);
    return 0;
}
