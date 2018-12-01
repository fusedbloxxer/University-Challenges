#include <stdio.h>
#include <stdlib.h>

//0 - dreapta, 1 - jos, 2 - stanga, 3 - dreapta
int or,n,m,u;
int T[1000][1000];
int v[1000][1000];
int dir[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};

/* COMPLETA
Să se parcurgă o matrice în spirală.
Exemplu: Pentru 1 2 3
4 5 6
7 8 9
10 11 12
se va afiṣa 1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8.
*/

void spirt(int i,int j)
{
    if(T[i][j]==0 && i<n && j<m && i>=0 && j>=0)
    {
        T[i][j]=1;
        u++;
        printf("%d ",v[i][j]);

        int x=i+dir[or%4][0], y=j+dir[or%4][1];

        if(!(x>=0 && x<n && y>=0 && y<m) || T[x][y]==1)or++;
        {
            x=i+dir[or%4][0]; y=j+dir[or%4][1];
        }

        spirt(x, y);
    }

}

int main()
{
    scanf("%d%d",&n,&m);

    int i,j;
    FILE*fp=fopen("date.in","r");
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            fscanf(fp,"%d",&v[i][j]);
    fclose(fp);

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            printf("%d ",v[i][j]);
        printf("\n");
    }
    printf("\n");


    spirt(0,0);


    return 0;
}
