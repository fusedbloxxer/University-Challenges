#include <stdio.h>
#include <stdlib.h>

void copy_bits(int *x, int p, int n, int y)
{
    printBinary(*x);
    *x = (*x & ~(((1 << n) - 1) << (p - n)))
        | ((((1 << n) - 1) & y) << (p - n));
    printBinary(*x);
}

void printBinary(int x)
{
    int i;
    for(i = sizeof(int) * 8 - 1; i >=0; i--)
    {
        if(((1 << i) & x) != 0)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main()
{
    int x = 4095, y = 5, n = 4, p = 5;
    copy_bits(&x, p, 4, y);
    return 0;
}
