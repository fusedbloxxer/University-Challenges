#include <stdio.h>
#include <stdlib.h>

void invers(unsigned short *x)
{
    char *c1, *c2;

    c1=x;
    c2=c1+1;

    *c1=*(c2)^*(c1);
    *c2=*(c2)^*(c1);
    *c1=*(c2)^*(c1);
}

int main()
{
    int n=20;
    printf("%d ",n);
    invers(&n);
    printf("%d ",n);

    invers(&n);
    printf("%d",n);

    return 0;
}
