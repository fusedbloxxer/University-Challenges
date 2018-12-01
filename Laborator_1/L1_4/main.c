#include <stdio.h>
#include <stdlib.h>

//Se citește un număr întreg de la tastatură. Să se determine dacă acesta este par sau impar
//folosind doar operatorii logici la nivel de biți.

int main()
{
    int x;
    scanf("%d",&x);
    (x&1==1)?printf("impar"):
    printf("par");

    return 0;
}
