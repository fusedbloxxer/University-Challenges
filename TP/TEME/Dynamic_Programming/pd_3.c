#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct square_coord{
    int x, y;
};

int dynamic(int **bi_arr, int n, int m) {
    struct square_coord max_point;
    max_point.x = INT_MIN;
    int square_count = 0;
    int **sol  = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        sol[i] = (int *)malloc(sizeof(int) * m);
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (j == m - 1 || i == n - 1) {
                if (bi_arr[i][j] == 0) {
                    sol[i][j] = 1;
                    if (max_point.x == INT_MIN) {
                        max_point.x = i;
                        max_point.y = j;
                    }
                } else {
                    sol[i][j] = INT_MIN;
                }
            } else if (bi_arr[i][j] == 0) {
                int min = sol[i + 1][j + 1];
                if (min > sol[i + 1][j]) {
                    min = sol[i + 1][j];
                }
                if (min > sol[i][j + 1]) {
                    min = sol[i][j + 1];
                }

                if (min == INT_MIN) {
                    sol[i][j] = 1;
                } else {
                    sol[i][j] = min + 1;
                    if (sol[i][j] > 2) {
                        square_count += sol[i][j] - 1;
                    } else square_count += 1;
                    if (sol[max_point.x][max_point.y] < sol[i][j]) {
                        max_point.x = i;
                        max_point.y = j;
                    }
                }
            } else {
                sol[i][j] = INT_MIN;
            }
        }
    }

    printf("Biggest square: dim = %d, coord = (%d, %d)\n",
           sol[max_point.x][max_point.y], max_point.x + 1, max_point.y + 1);
    print_bi_arr(sol, n, m);
    free_bi_arr(&sol, &n, &m);
    return square_count;
}

void print_trace(int *array, int len) {
    for (int i = 2; i <= len; i++) {
        if (array[i] > 0) {
            printf("Latura %d: %d patrate.\n", i, array[i]);
        }
    }
    printf("\n");
}

int max(int a, int b) {
    return (a < b)? b : a;
}

void free_bi_arr(int ***bi_arr, int *n, int *m) {
    for (int i = 0; i < *n; i++) {
        free((*bi_arr)[i]);
    }
    free(*bi_arr);
    *bi_arr = NULL;
    *n = 0;
    *m = 0;
}

void print_bi_arr(int **bi_arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", bi_arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    FILE *input = fopen("date.in", "r");
    int n, m, **bi_arr;
    fscanf(input, "%d %d", &n, &m);
    bi_arr = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        bi_arr[i] = (int *)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            fscanf(input, "%d", &bi_arr[i][j]);
        }
    }

    printf("Square count: %d", dynamic(bi_arr, n, m));

    free_bi_arr(&bi_arr, &n, &m);
    fclose(input);
    return 0;
}
