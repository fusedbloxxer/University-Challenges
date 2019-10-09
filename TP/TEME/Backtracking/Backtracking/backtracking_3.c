#include <stdio.h>
#include <stdlib.h>

/** La fiecare pas ma misc pe coloane, la fiecare salt pe linii
    Memorez indecsii reginelor si verific urmatoarele reguli treptat:
    - Sa nu se repete i sau j
    - Sa nu se repete j - i
    - Sa nu se repete i + j
*/

int n, *regine;

void printSolution() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (regine[i] == j) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void printArray(int k) {
    for (int i = 0; i < k; i++) {
        printf("[%d, %d] ", i, regine[i]);
    }
    printf("\n");
}

void bk(int k) {
    int check, i, j;
    for (i = 0; i < n; i++) {
        check = 0;
        regine[k] = i;

        for (j = 0; j < k; j++) {
            if (regine[j] == regine[k]) {
                check = 1;
                break;
            } else if (regine[j] + j == regine[k] + k) {
                check = 1;
                break;
            } else if (regine[j] - j == regine[k] - k) {
                check = 1;
                break;
            }
        }

        if (check == 0) {
            if (k == n - 1) {
                // printArray(k);
                printSolution();
            } else if (k < n) {
                bk(k + 1);
            }
        }
    }
}

int main() {
    printf("Tabla are dimensiunea NxN, unde N = ");
    scanf("%d", &n);

    regine = (int *)malloc(sizeof(int) * n);

    bk(0);

    free(regine);
    return 0;
}
