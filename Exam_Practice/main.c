#include <stdio.h>
#include <stdlib.h>

int *** biDiag(int ***matrix, const char *file_name, int *N)
{
    FILE *F = fopen(file_name, "r");
    fscanf(F, "%d", N);
    int i, j;
    *matrix = (int **)malloc(*N * sizeof(int *));

    for(i = 0; i < *N; i++)
    {
        if(i != (*N - 1))
        {
            (*matrix)[i] = (int *)malloc(2 * sizeof(int));
            for(j = 0; j < 2; j++)
            {
                fscanf(F, "%d", *(*matrix + i) + j);
            }
        }
        else
        {
            (*matrix)[i] = (int *)malloc(sizeof(int));
            fscanf(F, "%d", *(*matrix + i));
        }
    }

    fclose(F);
    return matrix;
}
void printMatrix(int **matrix, int N)
{
    printf("The matrix is:\n");
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(i == j)
                printf("%d ", matrix[i][0]);
            else if(i == (j - 1))
                printf("%d ", matrix[i][1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int * proMatrix(int **matrix, int *x, int n)
{
    printf("Calculating:\n");
    printMatrix(matrix, n);
    printf("Inmultit cu \n");
    printVector(x);

    int *result = (int *)malloc(n * sizeof(int));
    if(n == 1)
    {
        result[0] = x[0] * matrix[0][0];
    }
    else
    {
        int i, j;
        for(i = 0; i < n - 1; i++)
        {
            result[i] = matrix[i][0] * x[i] + matrix[i][1] * x[i + 1];
        }
        result[i] = matrix[i][0] * x[i];
    }

    return result;
}
void printVector(int *x, int n)
{
    printf("The vector is:\n");
    int i = 0;
    for(i = 0; i < n; i++)
    {
        printf("%d\n", x[i]);
    }
}
int main()
{
    int length, i;
    int **matrix;

    /// Subpunctul a)
    biDiag(&matrix, "date.txt", &length);
    printMatrix(matrix, length);

    /// Subpunctul b)
    int *vector = (int *)malloc(length * sizeof(int));

    for(i = 0; i < length; i++)
    {
        vector[i] = 1;
    }
    vector = proMatrix(matrix, vector, length);
    printVector(vector, length);


    return 0;
}
