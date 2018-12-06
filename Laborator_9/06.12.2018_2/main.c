#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min(int x, int y) {
    if(x < y) return x;
    return y;
}

int main()
{
    FILE *F1 = fopen("inferior.txt", "r");
    FILE *F2 = fopen("superior.txt", "r");

    int aux = 0, size, index_1, index_2, index_3;
    fscanf(stdin, "%d", &size);
    int **inf = (int **)malloc(size * sizeof(int *));
    int **sup = (int **)malloc(size * sizeof(int *));
    int **pro = (int **)calloc(size, sizeof(int *));
    for(index_1 = 0; index_1 < size; index_1++) {
        pro[index_1] = (int *)calloc(size, sizeof(int));
    }

    for(index_1 = 0; index_1 < size; index_1++) {
        inf[index_1] = (int *)malloc((index_1 + 1) * sizeof(int));
        for(index_2 = 0; index_2 < index_1 + 1; index_2++)
            fscanf(F1, "%d", &inf[index_1][index_2]);
     }

     for(index_1 = 0; index_1 < size; index_1++) {
        sup[index_1] = (int *)malloc((size - index_1) * sizeof(int));
        for(index_2 = 0; index_2 < size - index_1; index_2++)
            fscanf(F2, "%d", &sup[index_1][index_2]);
     }

     // Produs
     for(index_1 = 0; index_1 < size; index_1++) {
        for(index_2 = 0; index_2 < size; index_2++) {
            for(index_3 = 0; index_3 <= min(index_1, index_2); index_3++) {
                pro[index_1][index_2] += inf[index_1][index_3] * sup[index_3][index_2-index_3];
            }
        }
     }

     for(index_1 = 0; index_1 < size; index_1++) {
        for(index_2 = 0; index_2 < size; index_2++) {
            printf("%d ", pro[index_1][index_2]);
        }
        printf("\n");
     }

      //Printarea celor doua matrice!
    for(index_1 = 0; index_1 < size; index_1++) {
        for(index_2 = 0; index_2 < index_1 + 1; index_2++)
            printf("%d ", inf[index_1][index_2]);
        printf("\n");
     }

     for(index_1 = 0; index_1 < size; index_1++) {
        for(index_2 = 0; index_2 < size - index_1; index_2++)
            printf("%d ", sup[index_1][index_2]);
        printf("\n");
     }

    fclose(F1);
    fclose(F2);
    return 0;
}
