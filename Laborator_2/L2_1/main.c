#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Metoda(int x)
{
    printf("\nMetoda2: ");

    int i;
    for(i=31;i>=0;i--)
        printf("%d",(x&(1<<i))?1:0);
}

int main()
{
    int x;

    scanf("%d",&x);

    Metoda(x);

    return 0;
}
