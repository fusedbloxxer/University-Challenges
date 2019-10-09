#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* input = fopen("date.in", "r");
    int nOfElements; fscanf(input, "%d", &nOfElements);
    int left[6] = {0}, right[6] = {0}, auxiliary;

    for (int i = 0; i < nOfElements; i++) {
        int currentElement;
        fscanf(input, "%d", &currentElement);
        left[currentElement]++;
    }

    auxiliary = 2 * nOfElements;

    for (int i = nOfElements; i < auxiliary; i++) {
        int currentElement;
        fscanf(input, "%d", &currentElement);
        right[currentElement]++;
    }

    int Sum = 0;

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (i % 2 != j % 2) {
                Sum += i * left[i] * right[j] * j;
            }
        }
    }

    /// OR

    Sum = 2 *
        ((left[2] + 2 * left[4]) * (right[1] + 3 * right[3] + 5 * right[5]) +
         (right[2] + 2 * right[4]) * (left[1] + 3 * left[3] + 5 * left[5]));

    fprintf(stdout, "%d", Sum);

    fclose(input);
    return 0;
}
