#include <stdio.h>
#include <stdlib.h>

int sum(int *u, int *v, int n)
{
    int i, sum = 0, min = u[0];
    for(i = 0; i < n; i++)
    {
        if(min > u[i])
            min = u[i];
    }
    for(i = 0; i < n; i++)
    {
        if(v[i] > min)
            sum += v[i];
    }
    return sum;
}
void afisMatrix(int **m, int n)
{
    int i, j;
    printf("The matrix is:\n");
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    for(j = 0; j < n; j++)
    {
        printf("%d ", m[n - 1][j]);
    }
    printf("\n");
}
int ** allocMatrix(int n)
{
    FILE *F = fopen("date.in", "r");
    int i, j;
    int **m = (int **)malloc(sizeof(int *) * n);

    for(i = 0; i < n - 1; i++)
    {
        m[i] = (int *)malloc(sizeof(int) * (n - i));
        for(j = 0; j < n - i; j++)
        {
            fscanf(F, "%d ", &m[i][j]);
        }
    }
    m[n - 1] = (int *)malloc(sizeof(int) * n);
    for(j = 0; j < n; j++)
    {
        fscanf(F, "%d ", &m[n - 1][j]);
    }
    fclose(F);
    return m;
}
int * proMatrix(int **m, int *x, int n)
{
    int *y = (int *)calloc(n, sizeof(int));
    int i, j;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i; j++)
        {
            y[i] += m[i][j] * x[j + i];
        }
    }

    for(j = 0; j < n; j++)
    {
        y[n - 1] += m[n - 1][j] * x[j];
    }

    return y;
}
void printVector(int n, int *v)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d\n", v[i]);
    printf("\n");
}
struct Produs
{
    char nume[30];
    int cantitate;
    float pret;
};
int compareTo(void *a, void *b)
{
    struct Produs *al = (struct Produs *)a;
    struct Produs *bl = (struct Produs *)b;
    int r = bl->cantitate - al->cantitate;
    if(r != 0)
        return r;
    else
    {
        return strcmp(bl->nume, al->nume);
    }
}
void sortTablou(struct Produs * v, int n)
{
    qsort(v, n, sizeof(struct Produs), compareTo);
}
struct produs * readProduse(const char *file_name, int *N)
{
    FILE *F = fopen(file_name, "r");
    fscanf(F, "%d", N);
    struct Produs *head;
    head = (struct Produs *)malloc(sizeof(struct Produs) * *N);
    int i;
    for(i = 0; i < *N; i++)
    {
        fscanf(F, "%s", head[i].nume);
        fscanf(F, "%d", &head[i].cantitate);
        fscanf(F, "%f", &head[i].pret);
    }
    fclose(F);
    return head;
}
void afisProduse(struct Produs *lista, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Nume: %s Cantitate: %d Pret: %f\n", lista[i].nume, lista[i].cantitate, lista[i].pret);
    }
    printf("\n");
}
void numeProduseInFisier(struct Produs *v, int n)
{
    FILE *F = fopen("binar", "wb");
    int i;
    for(i = 0; i < n; i++)
    {
        if(v[i].pret > 10)
        {
            fwrite(v[i].nume, sizeof(char) * 29, 1, F);
            fseek(F, 1, SEEK_CUR);
        }
    }
    fclose(F);
}
void citireNumeProduseInFisier()
{
    FILE *F = fopen("binar", "rb");
    while(feof(F) == 0)
    {
        char nume[30];
        fread(nume, sizeof(char) * 30, 1, F);
        printf("%s ", nume);
    }
    fclose(F);
}
int cmp(const void *a, const void *b)
{
    char al = *(char *)a;
    char bl = *(char *)b;

    if(al < bl)
        return -1;
    return 1;
}
void * numarare(const void* v, int n, int d, int cmp(const void *, const void *))
{
    int i, contor;
    void *maxim = v;
    for(i = 1; i < n; i++)
    {
        int j;
        char *octet1 = (char *)maxim;
        char *octet2 = (char *)(v + i * d);
        for(j = d - 1; j >= 0; j--)
        {
            if(cmp((void *)(octet1 + j), (void *)(octet2 + j)) == -1)
            {
                maxim = v + i * d;
                j = 0;
            }
        }
    }
    printf("\nThe maximum value is: (char)%c (int)%d", *(char *)maxim, *(int *)maxim);
    contor = 0;
    for(i = 0; i < n; i++)
    {
        int j;
        char *octet1 = (char *)maxim;
        char *octet2 = (char *)(v + i * d);
        for(j = d - 1; j >= 0; j--)
        {
            if(cmp((void *)(octet2 + j), (void *)(octet1 + j)) == -1)
            {
                contor++; j = 0; break;
            }
        }
    }
    printf("\nThere are %d values smaller than the maximum one.", contor);
}
int main()
{
    /// Subpunctul 1
    int a[] = {1,2,3,4,5};
    int b[] = {8, 10, 2, 8, 9};
    printf("The sum is: %d\n", sum(b,a,5));

    /// Subpunctul 2
    /// a)
    int **m = allocMatrix(5);
    afisMatrix(m, 5);
    printf("\n");
    /// b)
    printf("The vector is: \n");
    printVector(5, b);
    printf("The product is: \n");
    int *y = proMatrix(m, b, 5);
    printVector(5, y);

    /// Subpunctul 3
    /// a)
    int length;
    struct Produs *listaProduse = readProduse("date2.in", &length);
    printf("Before sorting:\n");
    afisProduse(listaProduse, length);
    sortTablou(listaProduse, length);
    printf("After sorting:\n");
    afisProduse(listaProduse, length);

    ///b)
    numeProduseInFisier(listaProduse, length);
    printf("Reading from the binary file:\n");
    citireNumeProduseInFisier();

    ///Subpunctul 4
    char caractere[] = "adfcfe";
    int  values[] = {1, 2, 4, 5, 5, 5};

    numarare(values, 6, sizeof(int), cmp);
    numarare(caractere, strlen(caractere), sizeof(char), cmp);

    return 0;
}
