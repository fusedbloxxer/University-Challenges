#include <stdio.h>
#include <stdlib.h>

/*COMPLETA
Se citesc de la tastatură m și n naturale nenule reprezentând dimensiunile unei matrice și
elementele matricei. Să se construiască ṣi să se afiṣeze matricea transpusă.
*/

int main()
{
    unsigned int m, n, i ,j;
    scanf("%d%d",&n,&m);


    FILE*fp=fopen("date.in","r");

    unsigned int v[20][30];

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {fscanf(fp,"%d", &v[j][i]);}

    for(i=0;i<m;i++)
        {for(j=0;j<n;j++)
        printf("%d ",v[i][j]);printf("\n");}

    fclose(fp);
    return 0;
}
