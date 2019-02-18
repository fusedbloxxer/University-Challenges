#include <stdio.h>
#include <stdlib.h>

/*
    TOATE DIN FISIER!
    FOLOSIND FUNCTII, POINTERI LA FUNCTII
    a) Sa se aloce dinamic o matrice de numere complexe.
    b) Sa se sorteze crescator liniile impare si descrescator liniile pare.
     ) Sa se afiseze matricea normal
    c) Sa se afiseze matricea in spirala.
    d) Sa se elimine coloana k sau linia k
    e) Sa se insereze coloana k sau linia k
    f) Sa se afiseze in spirala in sens invers al ceasornicului.

    *g) Se reiau subpunctele, dar matricea va fi rara si nu se vor memora zerourile!.
*/
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _b : _a; })

struct complex {
    float real, img;
};

void readMatrix(struct complex ***a, int *n, int *m) {
    FILE *file = fopen("normal.txt", "r");
    fscanf(file, "%d%d", n, m);
    *a = (struct complex **)malloc(sizeof(struct complex *) * (*n));
    int i;
    for(i = 0; i < *n; i ++) {
        (*a)[i] = (struct complex *)malloc(sizeof(struct complex) * (*m));
        int j;
        for(j = 0; j < *m; j++) {
            fscanf(file, "%f", &((*a)[i][j].real));
            if(fgetc(file) == '+') {
                fscanf(file, "%fi", &((*a)[i][j].img));
            } else {
                fseek(file, -1, SEEK_CUR);
                fscanf(file, "%fi", &((*a)[i][j].img));
            }
        }
    }
    fclose(file);
}

int ascending(void *a, void *b) {
    struct complex al = *(struct complex *)a;
    struct complex bl = *(struct complex *)b;
    return  al.real * al.real + al.img * al.img
            - ( bl.real * bl.real + bl.img * bl.img);
}

int descending(void *a, void *b) {
    return ascending(a, b) * -1;
}

void sortLine(struct complex *a, int m, int (*f)(void *, void *)) {
    qsort(a, m, sizeof(struct complex), f);
}

void evenOddSort(struct complex **a, int n, int m) {
    int i;
    for(i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sortLine(a[i], m, &descending);
        } else {
            sortLine(a[i], m, &ascending);
        }
    }
}

void printComplex(struct complex a, FILE *output) {
    fprintf(output, "%.0f", a.real);
    if(a.img < 0) {
        fprintf(output, "%.0fi", a.img);
    } else {
        fprintf(output, "+%.0fi", a.img);
    }
}

void printMatrix(struct complex **a, int n, int m, FILE* output) {
    int i;
    for(i = 0; i < n; i++) {
        int j;
        for(j = 0; j < m; j++) {
            printComplex(a[i][j], stdout);
            if(j + 1 != m) {
                fprintf(output, " ");
            }
        }
        fprintf(output, "\n");
    }
    printf("\n");
    //fclose(output);
}

void printSpiral(struct complex **a, int n, int m, FILE* output) {
    int i, l1 = 0, l2 = n - 1, c1 = 0, c2 = m;
    while(c1 <= c2 && l1 <= l2) {
        for(i = c1; i < c2; i++) {
            printComplex(a[l1][i], output);
            fprintf(output, " ");
        }
        for(i = l1 + 1; i < l2; i++) {
            printComplex(a[i][c2], output);
            fprintf(output, " ");
        }
        for(i = c2 - 1; i >= c1; i--) {
            printComplex(a[l2][i], output);
            fprintf(output, " ");
        }
        for(i = l2 - 1; i > l1; i--) {
            printComplex(a[i][c1], output);
            fprintf(output, " ");
        }

        c1++;
        c2--;
        l1++;
        l2--;
    }
    fclose(output);
}

void eliminateRow(struct complex ***a, int *n, int k) {
    int i;
    free((*a)[k]);
    for(i = k; i < *n - 1; i++) {
        (*a)[i] = (*a)[i + 1];
    }
    (*n) = (*n) - 1;
    *a = realloc(*a, sizeof(struct complex *) * (*n));
}

void eliminateCol(struct complex **a, int n, int *m, int k) {
    int i;
    for(i = 0; i < n; i++) {
        int j;
        for(j = k; j < *m - 1; j++) {
            a[i][j] = a[i][j + 1];
        }
        a[i] = realloc(a[i], (*m - 1) * sizeof(struct complex));
    }
    *m = *m - 1;
}

void insertCol(struct complex **a, int n, int *m, int k) {
    if(k > *m) {
        k = *m;
    } else if (k < 0) {
        k = 0;
    }

    int i;
    for(i = 0; i < n; i++) {
        a[i] = (struct complex *)realloc(a[i], sizeof(struct complex) * (*m + 1));
        int j;
        for(j = *m; j > k; j--) {
            a[i][j] = a[i][j - 1];
        }
        // INSERT NEW ELEMENTS !
    }
    *m = *m + 1;
}

void insertRow(struct complex ***a, int *n, int m, int k) {
    if(k > *n) {
        k = *n;
    } else if (k < 0) {
        k = 0;
    }
    *a = realloc(*a, sizeof(struct complex *) * (*n + 1));
    int i;
    for(i = *n; i > k; i--) {
        (*a)[i] = (*a)[i - 1];
    }
    *n = *n + 1;
}

void printSpiralBackwards(struct complex **a, int n, int m, FILE *output) {
    int i, c1 = 0, l2 = n - 1, c2 = m - 1, l1 = 0;
    while(c1 <= c2 && l1 <= l2) {
        for(i = l1; i <= l2; i++) {
            printComplex(a[i][c1], output);
            fprintf(output, " ");
        }
        for(i = c1 + 1; i <= c2; i++) {
            printComplex(a[l2][i], output);
            fprintf(output, " ");
        }
        for(i = l2 - 1; i >= l1; i--) {
            printComplex(a[i][c2], output);
            fprintf(output, " ");
        }
        for(i = c2 - 1; i > c1; i--) {
            printComplex(a[l1][i], output);
            fprintf(output, " ");
        }

        c1++;
        c2--;
        l1++;
        l2--;
    }
    fclose(output);
}
int main()
{
    struct complex **a; int n, m;
    readMatrix(&a, &n, &m);
    // evenOddSort(a, n, m);
    // printMatrix(a, n, m, stdout);
    //printSpiral(a, n, m, stdout);
    //eliminateRow(&a, &n, 0);
    //eliminateCol(a, n, &m, 1);
    insertCol(a, n, &m, 0);
    insertCol(a, n, &m, 0);
    insertRow(&a, &n, m, 0);
    insertRow(&a, &n, m, 0);
    printMatrix(a, n, m, stdout);
    printSpiralBackwards(a, n, m, stdout);
    return 0;
}
