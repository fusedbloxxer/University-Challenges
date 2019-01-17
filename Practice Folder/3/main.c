#include <stdio.h>
#include <stdlib.h>

union octeti {
    char bytes[2];
};

void inverse(short int x) {
    printBinary(x);
    union octeti helper;
    helper.bytes[0] = *(char *)&x;
    helper.bytes[1] = *((char *)&x + 1);

    *(char *)&x       = helper.bytes[1];
    *((char *)&x + 1) = helper.bytes[0];
    printBinary(x);
}
void printBinary(short int x)
{
    int i;
    for(i = sizeof(short int) * 8 - 1; i >=0; i--)
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
    short int  x = 5501;
    inverse(x);
    return 0;
}
