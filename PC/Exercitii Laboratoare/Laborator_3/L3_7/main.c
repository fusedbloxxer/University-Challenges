#include <stdio.h>
#include <stdlib.h>

/* COMPLETA
Se citește o matrice A de dimenisiuni N x N(1<=N<=100), (0 <= A[i][j] < 232). Să se efectueze o rotire spre dreapta a matricei A.
*/

unsigned long int A[101][101], B[101][101];

int main()
{
    FILE*fp=fopen("date.in","r");
    int N;
    scanf("%d",&N);

    int i,j;
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        {
            fscanf(fp,"%ld",&A[i][j]);
            B[j][N-i-1]=A[i][j];
        }

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            printf("%d ",B[i][j]);
        printf("\n");
    }

    fclose(fp);
    return 0;
}
