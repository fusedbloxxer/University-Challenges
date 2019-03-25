#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input = fopen("date.in", "r");
    int x, check = 0, *array = calloc(10, sizeof(int));

    while(fscanf(input, "%d", &x) != -1) {
        if (x < 10) {
            if (check == 1) {
                array[x]++;
            } else {
                for (int i = 0; i < 10; i++) {
                    array[i] = 0;
                }
                array[x]++;
                check = 1;
            }
        } else check = 0;
    }

    for (int i = 0; i < 10; i++) {
        while (array[i]-- != 0) {
            printf("%d ", i);
        }
    }

    free(array);
    fclose(input);
    return 0;
}
