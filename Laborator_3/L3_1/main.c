#include <stdio.h>
#include <stdlib.h>

int v[4000];
/* COMPLETA
Se citesc n, m și apoi două mulțimi A și B cu n, respectiv m numere întregi cuprinse între [-x,x],
x<=2000. Să se afișeze numărul de elemente comune mulțimii.
(Indicație: mulțimile A și B nu se vor memora - se va crea un vector de frecvență).
*/
int main()
{
    int n, m;
    FILE*fp=fopen("date.in","r");
    fscanf(fp,"%d%d",&n,&m);

    while(n)
    {
        int x;
        fscanf(fp,"%d",&x);
        n--;
        if(x<0)v[x+2000]++;
        else v[x]++;
    }

    while(m)
    {
        int x;
        fscanf(fp,"%d",&x);
        m--;
        if(x<0)v[x+2000]++;
        else v[x]++;
    }

    n=0;

    for(m=0;m<=4000;m++)
        if(v[m]>1)n++;

    printf("%d",n);

    fclose(fp);

    return 0;
}
