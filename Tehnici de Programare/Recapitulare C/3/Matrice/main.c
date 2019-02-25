#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readMatrix(int ***a, int *n, int *m, char *file_name) {
    FILE*file = fopen(file_name, "r");
    fscanf(file, "%d %d", n, m);
    (*a) = (int **)malloc(sizeof(int *) * (*n));
    for(int i = 0; i < *n; i++) {
        *(*a + i)= (int *)malloc(sizeof(int) * (*m));
        for(int j = 0; j < *m; j++) {
            fscanf(file, "%d", *(*a + i) + j);
        }
    }
    fclose(file);
}

void printMatrix(int **a, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void printBytes(void *a, int nr_oct) {
    unsigned char *p = (unsigned char *)a;
    for(int i = 0; i < nr_oct; i++) {
        for(int j = 7; j>=0; j--) {
                if((*(p + i) & (1 << j)) != 0) {
                    printf("1");
                } else {
                    printf("0");
                }
        }
        printf(" ");
    }
}

int main()
{
    int **a, n, m;
    readMatrix(&a, &n, &m, "date.in");
    //printMatrix(a, n, m);
    int x = 0;
    *(unsigned char *)&x = 7;
    *((unsigned char *)&x + 1) = 7;
    //memset(&x, 7, 1);
    printBytes(&x, sizeof(int));
    return 0;
}
