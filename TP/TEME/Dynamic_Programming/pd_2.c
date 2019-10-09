#include <stdio.h>
#include <stdlib.h>

struct dom
{
    int a, b;
};

void dynamic(struct dom *domArray, int n)
{
    if (n == 1)
    {
        printPiece(domArray[0]);
    }
    else
    {
        int *check = (int *)malloc(sizeof(int) * n);
        check[0] = 3;
        for (int i = 1; i < n; i++)
        {
            int rot_1 = -1, rot_2 = -1;
            if (check[i - 1] == 1 || check[i - 1] == 3)
            {
                int ok = 0;
                if (domArray[i - 1].b == domArray[i].a
                        || domArray[i - 1].b + domArray[i].a == 6)
                {
                    ok++;
                    rot_2 = 1;
                }
                if (domArray[i - 1].b == domArray[i].b
                        || domArray[i - 1].b + domArray[i].b == 6)
                {
                    ok++;
                    if (rot_2 == 1)
                    {
                        rot_2 = 3;
                    }
                    else
                    {
                        rot_2 = 2;
                    }
                }
                if (ok >= 1)
                {
                    rot_1 = 1;
                }
            }
            if (check[i - 1] == 2 || check[i - 1] == 3)
            {
                int ok = 0;
                if (domArray[i - 1].a == domArray[i].a
                        || domArray[i - 1].a + domArray[i].a == 6)
                {
                    ok++;
                    if (rot_2 == 2)
                    {
                        rot_2 = 3;
                    }
                    else
                    {
                        rot_2 = 1;
                    }
                }
                if (domArray[i - 1].a == domArray[i].b
                        || domArray[i - 1].a + domArray[i].b == 6)
                {
                    ok++;
                    if (rot_2 == 1)
                    {
                        rot_2 = 3;
                    }
                    else
                    {
                        rot_2 = 2;
                    }
                }
                if (ok >= 1)
                {
                    if (rot_1 == 1)
                    {
                        rot_1 = 3;
                    }
                    else
                    {
                        rot_1 = 2;
                    }
                }
            }

            if (rot_1 == -1 || rot_2 == -1)
            {
                printf("IMPOSIBIL\n");
                for(int i = 0; i <n; i++)
                {
                    if (check[i] == 1 || check[i] == 3)
                    {
                        printPiece(domArray[i]);
                    }
                    else if (check[i] != 0)
                    {
                        printf("(%d, %d)", domArray[i].b, domArray[i].a);
                    }
                }
                printf("\n");
                printArray(check, n);
                goto STOP;
            }
            check[i - 1] = rot_1;
            check[i] = rot_2;
        }
        for(int i = 0; i <n; i++)
        {
            if (check[i] == 1 || check[i] == 3)
            {
                printPiece(domArray[i]);
            }
            else
            {
                printf("(%d, %d)", domArray[i].b, domArray[i].a);
            }
        }
        printf("\n");
        printArray(check, n);

STOP:
        free(check);
    }
}

void printArray(int *array, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void printDomArray(struct dom *domArray, int len)
{
    for (int i = 0; i < len; i++)
    {
        printPiece(domArray[i]);
    }
    printf("\n");
}

void printPiece(struct dom Piece)
{
    printf("(%d, %d)", Piece.a, Piece.b);
}

int main()
{
    FILE *input = fopen("date.in", "r");
    int n;
    struct dom *domArray;
    fscanf(input, "%d", &n);
    domArray = (struct dom *)malloc(sizeof(struct dom) * n);

    for (int i = 0; i < n; i++)
    {
        fscanf(input, "%d %d", &domArray[i].a, &domArray[i].b);
    }

    dynamic(domArray, n);

    free(domArray);
    fclose(input);
    return 0;
}
