#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **biarr;
char *sequence;
int index = -1;

void fotografie(int l1, int l2, int c1, int c2) {
    index++;
    // printf("%c:\n", sequence[index]);
    // printBiArray(biarr, 4);

    if (sequence[index] == 'w') {
        // do nothing
    } else if (sequence[index] == 'b') {
        // black
        for (int i = l1; i < l2; i++) {
            for (int j = c1; j < c2; j++) {
                biarr[i][j] = 1;
            }
        }
    } else {
        int lm = l1 + (l2 - l1) / 2;
        int cm = c1 + (c2 - c1) / 2;

        fotografie(l1, lm, cm, c2);
        fotografie(l1, lm, c1, cm);
        fotografie(lm, l2, c1, cm);
        fotografie(lm, l2, cm, c2);
    }


}

void printBiArray(char **biarr, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            printf("%d ", biarr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    FILE *input = fopen("date.in", "r");
    int L, slength;

    fscanf(input, "%d", &L);
    slength = (4 * L * L - 1) / 3;
    fgetc(input);

    biarr = (char **)malloc(L * sizeof(char *));
    for (int i = 0; i < L; i++) {
        biarr[i] = (char *)calloc(L, sizeof(char));
    }

    sequence = (char *)malloc(sizeof(char) * (slength + 1));
    fgets(sequence, slength + 1, input);
    sequence[slength] = '\0';
    fclose(input);

    printf("%s", sequence);
    fotografie(0, L, 0, L);
    printBiArray(biarr, L);

    for (int i = 0; i < L; i++) {
        free(biarr[i]);
    }
    free(biarr);
    free(sequence);

    return 0;
}
