#include <stdio.h>
#include <stdlib.h>
//0 - dreapta, 1 - jos, 2 - stanga, 3 - dreapta
int or,n,m,u=1,f=0;
int T[1000][1000];
int v[1000][1000];
int dir[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};

/* COMPLETA
Sa se creeze o matrice patratică, în spirală, dupa regulile:

o numerele pornesc de la 1, din 1 in 1, în ordine crescătoare;
o dupa fiecare număr neprim x se adaugă cel mai mic divizor propriu al său, dupa care
se continuă cu x+1.
*/

void spirt(int i,int j)
{
    if(T[i][j]==0 && i<n && j<m && i>=0 && j>=0)
    {
        T[i][j]=1;

        int x=i+dir[or%4][0], y=j+dir[or%4][1];

        if(f==0)
        {
            v[i][j]=u;
            u++;
        }
        else
        {
            v[i][j]=f;
        }

        int calcPrim=Prim(v[i][j]);
        if(calcPrim==0)f=minDiv(v[i][j]);
        else f=0;

        if(!(x>=0 && x<n && y>=0 && y<m) || T[x][y]==1)or++;
        {
            x=i+dir[or%4][0];
            y=j+dir[or%4][1];
        }

        spirt(x, y);
    }

}

int minDiv(int x)
{
    int i;
    for(i=2; i<x; i++)
        if(x%i==0)return i;
}

int Prim(int x)
{
    int i;
    for(i=2; i<=x/2; i++)
        if(x%i==0)return 0;

    return 1;
}

int main()
{
    scanf("%d",&n);
    m=n;

    spirt(0,0);

    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            printf("%d ",v[i][j]);
        printf("\n");
    }


    return 0;
}
