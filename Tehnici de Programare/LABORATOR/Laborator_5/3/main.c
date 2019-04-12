#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array, i, j, nOfElements, X;
    scanf("%d", &X);

    FILE *input = fopen("date.in", "r");
    fscanf(input, "%d", &nOfElements);
    array = (int *)malloc(sizeof(int) * nOfElements);

    for (int i = 0; i < nOfElements; i++) {
        fscanf(input, "%d", &array[i]);
    }

    i = 0; j = nOfElements - 1;

    while (i < j) {
        if (array[i] > X) break;
        if (array[i] + array[j] == X) {
            printf("%d + %d = %d\n", array[i], array[j], X);
            return 0;
        }
        if (array[i] + array[j] > X) {
            j--;
        } else {
            i++;
        }
    }

    printf("No pair equals %d", X);

    free(array);
    fclose(input);
    return 0;
}
