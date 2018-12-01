#include <stdio.h>
#include <stdlib.h>

/*
COMPLETA

Se citesc: n, cele n elemente ale unui vector sortat crescator, apoi x și y două elemente din
vector. Să se afișeze toate elementele vectorului cuprinse între x și y.
Optim: folosiți căutarea binară.
*/

void binSE2(int Left, int Right, int x,int y, int v[])
{
    if(Left<=Right)
    {
        int Mid=((unsigned int)Left + (unsigned int)Right)>>1;

        if(v[Mid]>=x && v[Mid]<=y)
        {
            printf("%d ",v[Mid]);
            binSE2(Left, Mid-1, x, y, v);
            binSE2(Mid+1, Right, x, y, v);
        }
        else
        if(v[Mid]>y)binSE2(Left, Mid-1, x, y, v);
        if(v[Mid]<x)binSE2(Mid+1, Right, x, y, v);

    }
}

int main()
{
    int n,i;
    FILE *fp=fopen("date.in","r");

    fscanf(fp, "%d", &n);
    int v[n];

    for(i=0;i<n;i++)
        fscanf(fp, "%d",&v[i]);

    int x,y;
    scanf("%d%d",&x,&y);

    binSE2(0, n, x, y, v);

    fclose(fp);
    return 0;
}
