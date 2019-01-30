#include <stdio.h>
#include <stdlib.h>
#include "cod.h"

int main()
{
    char a[21], index;
    int n1, n2;
    citire(a,n1,n2,index);
    printf("N1=%d, N2=%d, Valoarea expresiei citite este: %s\n",n1,n2,a);
    operatie(a[index],n1,n2);

    return 0;
}
