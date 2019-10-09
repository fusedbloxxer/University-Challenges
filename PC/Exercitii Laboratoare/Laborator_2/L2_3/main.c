#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
3. Se citesc întregii x, y, n, p. Să se copieze în x, începând din poziția p, ultimii n biți din y și
să se afișeze noua valoare a lui x.
*/

void Metoda1()
{
    int x,y,n,p;

    FILE*fp;
    fp=fopen("date.in","r");
    fscanf(fp,"%d%d%d%d",&x,&y,&n,&p);

    //Copiez bitii in i;
    int i=pow(2,n)-1;
    i=y&i;

    //Fac spatiu in X
    int u,j,f=pow(2,32)-1;
    for(u=p;u>=n;u--)
        f=f-pow(2,u);
    x=x&f;

    //Transfer bitii salvati in x pe pozitia p ->;
    x=x|(i<<p-n+1);

    printf("%d",x);
}

void Metoda2()
{
    int x,y,n,p;

    FILE*fp;
    fp=fopen("date.in","r");
    fscanf(fp,"%d%d%d%d",&x,&y,&n,&p);

    int z=y&((1<<n)-1);

    x=x&((~0-((1<<p)-1))+((1<<n)-1));

    x=x|(z<<(p-n+1));

    printf("%d",x);

    fclose(fp);
}

int main()
{

    Metoda2();
   // Metoda1();
    return 0;
}
