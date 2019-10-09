#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,p;
    printf("p=");
    scanf("%d",&p);

    for(i=1;i<p;i++)
    for(j=1;j<p;j++)
        if(j+i<p)
        printf("(%d,%d,%d)\n",i,j,p-j-i);

    return 0;
}
