#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    if(a < b) return a;
    else return b;
}

void genMatrix_1(int ***a, int *n) {
    printf("N=");
    scanf("%d", n);
    *a = (int **)malloc(sizeof(int) * (*n));
    for(int i = 0; i < *n; i++) {
        (*a)[i] = (int *)malloc(sizeof(int) * (*n));
        for(int j = 0; j < *n; j++) {
            (*a)[i][j] = min(i, j);
        }
    }
}

void genMatrix_2(int ***a, int *n) {
    int k;
    printf("K=");
    scanf("%d", &k);
    *n = 2 * k - 1;
    *a = (int **)malloc(sizeof(int) * (*n));
    for(int i = 0; i < k; i++) {
        (*a)[i] = (int *)malloc(sizeof(int) * (k - i));
        for(int j = 0; j < k - i; j++) {
            (*a)[i][j] = k - i;
        }
    }
    for(int i = k; i < *n; i++) {
        (*a)[i] = (int *)malloc(sizeof(int) * (i - k + 2));
        for(int j = 0; j < i - k + 2; j++) {
            (*a)[i][j] = i - k + 2;
        }
    }
    *n = k;
}

void printMatrix_2(int **a, int k) {
    int n = k * 2 - 1;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k - i; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for(int i = k; i < n; i++) {
        for(int j = 0; j < i - k + 2; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void printMatrix(int **a, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void getArray(int **a, int *n) {
    FILE *f = fopen("date.in", "r");
    *a = NULL; *n = 0;
    int x;
    while(fscanf(f, "%d", &x) != -1 && x !=0) {
        if(firstDec(x) == x % 10) {
            *a = (int *)realloc(*a, sizeof(int) * ((*n) + 1));
           (*a)[*n] = x;
            *n = *n + 1;
        }
    }
    fclose(f);
}

void printArray(int *a, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int f1(int x) {
    return x- 1;
}

int f2(int x) {
    return 2 * x * x + 10;
}

int f3(int x) {
    if(x < 0) return -1;
    else if(x == 0) return 0;
    else return 1;
}

int genericSum(int m, int n, int (*f)(int)) {
    if(m <= n) {
        return f(m) + genericSum(m + 1, n, f);
    } else return 0;
}

int firstDec(int x) {
    if(x > 9) {
        return firstDec(x / 10);
    } else {
        return x;
    }
}

int main()
{
    /** Exercitiul 1
        int **a, n;
        genMatrix_1(&a, &n);
        printMatrix(a, n);
    */
    /** Exercitiul 2
        int **a, n;
        genMatrix_2(&a, &n);
        printMatrix_2(a, n);
    */
    /** Exercitiul 3

    */

    /** Exercitiul 4
        int *a, n;
        getArray(&a, &n);
        printArray(a, n);
    */

    /** Exercitiul 5
        int m, n;
        scanf("%d %d", &m, &n);
        printf("s1=%d s2=%d s3=%d", genericSum(m, n, f1), genericSum(m, n, f2), genericSum(m, n, f3));
    */


    return 0;
}
