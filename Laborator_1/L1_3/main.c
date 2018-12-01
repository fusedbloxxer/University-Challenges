#include <stdio.h>
#include <stdlib.h>

/*
Se citește un număr întreg n de la tastatură. Să se calculeze n*8, n/4 si n*10 folosind
operatorii logici de deplasare la nivel de bit.
*/

int main()
{
    int n;
    scanf("%d",&n);

    printf("n*8=%d\nn/4=%d\nn*10=%d",n<<3,n>>2,(n<<3+n<<1));

    return 0;
}
