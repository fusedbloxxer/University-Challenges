#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max;
    int a,b,c;
    printf("Sa se introduca 3 numere intregi: ");
    scanf("%d%d%d",&a,&b,&c);

    max=(a<b)?b:a;
    max=(max<c)?c:max;

    printf("\nMaximul este: %d",max);

    return 0;
}
