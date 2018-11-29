#include <stdio.h>
#include <stdlib.h>

//varianta buna
void spirala(int **m, int N)
{
    int c=1;
    int Dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    ///N-1, N-2, ...
    ///N-1, N-2
    int M=N*N;
    int u, u1, i = 0, j = 0, index = 0;

    while(M!=-1)
    {
        for(u=0; u<N-1; u++)
        {
            for(u1=0; u1<N-1; u1++)
            {

                M--;
                //m[i][j]=c++;
                printf("m[%d][%d]=%d, M=%d\n",i,j,m[i][j],M);
                i=i+Dir[index][0];j=j+Dir[index][1];
                if(M==0){goto A;}
            }

            index++;

            if(index==4)
                index=0;
        }

        N--;
    }

    A:;
}

//O varianta dar sare pe -1
void spirala2(int **m, int N)
{
    int Dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    int index=0, i=0, j=0;int c=1;
    int L=N;
    N*=N;
    while(N!=0)
    {
        //m[i][j]=c++;
        printf("m[%d][%d]=%d\n",i,j,m[i][j]);
        m[i][j]=-1;
        int y=i+Dir[index][0], x=j+Dir[index][1];

        if(x>=L || x<0 || y<0 || y>=L || m[y][x]==-1)
        {
            index++;
            if(index==4)
                index=0;

            i=i+Dir[index][0];
            j=j+Dir[index][1];
        }
        else
        {
            i=y;
            j=x;
        }


        N--;
    }
}

int main()
{
    int N;
    fscanf(stdin, "%d", &N);
    int **m=(int **)malloc(N*sizeof(int *));
    int index, count_element=1, index2;

    for(index = 0; index < N; index++)
    {
        m[index] = (int *)malloc(N*sizeof(int));
        for(index2=0;index2<N;index2++)
            m[index][index2]=count_element++;
    }

    spirala(m, N);printf("/n");

    for(index = 0; index < N; index++)
    {for(index2 = 0; index2 < N; index2++)
        printf("%d ",m[index][index2]);
        printf("\n");
    }


    return 0;
}
