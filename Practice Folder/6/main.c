#include <stdio.h>
#include <stdlib.h>
void readIntBytes(int *x)
{
    int i;
    unsigned char byte;

    for(i = 0; i < sizeof(int); i++)
    {
        scanf("%d", &byte);
        *((char*)x + i) = byte;
    }
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
        if(i%8 == 0)
            printf("\n");
    }
}
int main()
{
    int x;
    readIntBytes(&x);
    printBinary(x);
    return 0;
}
