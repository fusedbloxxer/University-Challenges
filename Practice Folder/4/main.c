#include <stdio.h>
#include <stdlib.h>
struct rar
{
    int l, c, x;
};
void readRare(const char *file_name, int *N, int *M, int *len, struct rar **head)
{
    FILE* input = fopen(file_name, "r");
    int l, x, c;
    fscanf(input, "%d", N);
    fscanf(input, "%d", M);
    fscanf(input, "%d %d %d", &l, &c, &x);
    *head = (struct rar*)malloc(sizeof(struct rar));
    *len = 1;
    (*head)->c = c;
    (*head)->x = x;
    (*head)->l = l;
    while(fscanf(input, "%d %d %d", &l, &c, &x) != -1)
    {
        *len += 1;
        *head = realloc(*head, *len * sizeof(struct rar));
        (*head + *len - 1)->c = c;
        (*head + *len - 1)->x = x;
        (*head + *len - 1)->l = l;
    }
    fclose(input);
}
void printRare(struct rar *head, int len, int N, int M)
{
    int i, j, index = 0;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            if(head[index].c == j && head[index].l == i)
            {
                printf("%d ", head[index].x);
                index++;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
    printf("\n");
}
struct rar * sumRare(struct rar *m1, struct rar* m2, int len1, int len2, int *size)
{
    *size = 1;
    int i = 0, j = 0;
    struct rar *result;
    if(m1[i].l < m2[j].l)
    {
        result = (struct rar*)malloc(sizeof(struct rar));
        result[0] = m1[i];
        i++;
    }
    else if(m1[i].l > m2[j].l)
    {
        result = (struct rar*)malloc(sizeof(struct rar));
        result[0] = m2[j];
        j++;
    }
    else if(m1[i].c < m2[j].c)
    {
        result = (struct rar*)malloc(sizeof(struct rar));
        result[0] = m1[i];
        i++;
    }
    else if(m1[i].c > m2[j].c)
    {
        result = (struct rar*)malloc(sizeof(struct rar));
        result[0] = m2[j];
        j++;
    }
    else
    {
        result = (struct rar*)malloc(sizeof(struct rar));
        result[0].c = m2[j].c;
        result[0].l = m2[j].l;
        result[0].x = m2[j].x + m1[i].x;
        j++;
        i++;
    }

    while(i < len1 && j < len2)
    {
        if(m1[i].l < m2[j].l)
        {
            *size = *size + 1;
            result = realloc(result, *size * sizeof(struct rar));
            result[*size - 1] = m1[i];
            i++;
        }
        else if(m1[i].l > m2[j].l)
        {
            *size = *size + 1;
            result = realloc(result, *size * sizeof(struct rar));
            result[*size - 1] = m2[j];
            j++;
        }
        else if(m1[i].c < m2[j].c)
        {
            *size = *size + 1;
            result = realloc(result, *size * sizeof(struct rar));
            result[*size - 1] = m1[i];
            i++;
        }
        else if(m1[i].c > m2[j].c)
        {
            *size = *size + 1;
            result = realloc(result, *size * sizeof(struct rar));
            result[*size - 1] = m2[j];
            j++;
        }
        else
        {
            *size = *size + 1;
            result = realloc(result, *size * sizeof(struct rar));
            result[*size - 1].c = m1[i].c;
            result[*size - 1].l = m1[i].l;
            result[*size - 1].x = m1[i].x + m2[j].x;
            i++;
            j++;
        }
    }

    while(i < len1)
    {
        *size = *size + 1;
        result = realloc(result, *size * sizeof(struct rar));
        result[*size - 1] = m1[i];
        i++;
    }
    while(j < len2)
    {
        *size = *size + 1;
        result = realloc(result, *size * sizeof(struct rar));
        result[*size - 1] = m2[j];
        j++;
    }

    return result;
}
struct rar* proRare(struct rar *m1, struct rar *m2, int len1, int len2, int N1, int M1, int N2, int M2, int *size)
{
    int i, j, k;
    int ok = 0;
    *size  = 1;
    struct rar *result;

    for(i = 0; i < N1; i++)
    {
        for(j = 0; j < M1; j++)
        {
            int aij = 0;
            for(k = 0; k < N1; k++)
            {
                int check = 0;
                int z, value;
                for(z = 0; z < len1; z++)
                {
                    if(m1[z].c == k && m1[z].l == i)
                    {
                        check = 1;
                        value = m1[z].x;
                        z = len1;
                    }
                }
                if(check == 1)
                    for(z = 0; z < len2; z++)
                    {
                        if(m2[z].c == j && m2[z].l == k)
                        {
                            check = 2;
                            value = value * m2[z].x;
                            z = len1;
                        }
                    }
                if(check == 2)
                {
                    aij = aij + value;
                }
            }
            if(aij != 0)
            {
                /// insert
                if(*size == 1)
                {

                    result = (struct rar *)malloc(sizeof(struct rar));
                    result[0].c = j;
                    result[0].l = i;
                    result[0].x = aij;
                    *size = *size + 1;
                }
                else
                {
                    result = realloc(result, *size * sizeof(struct rar));
                    result[*size - 1].c = j;
                    result[*size - 1].l = i;
                    result[*size - 1].x = aij;
                    *size = *size + 1;

                }
            }
        }
    }

    return result;
}
int main()
{
    int N1, M1,
        N2, M2,
        len1, len2,
        size, i;

    struct rar *m1, *m2, *aux;
    readRare("date.in",  &N1, &M1, &len1, &m1);
    readRare("date2.in", &N2, &M2, &len2, &m2);
    printRare(m1, len1, N1, M1);
    printRare(m2, len2, N2, M2);

    /// SUM
    aux = sumRare(m1, m2, len1, len2, &size);
    printf("SUM:\n");
    printRare(aux, size, N1, M1);

    /// PRODUCT
    aux = proRare(m1, m2, len1, len2, N1, M1, N2, M2, &size);
    printf("PRODUCT:\n");
    printRare(aux, size, N1, M1);

    return 0;
}
