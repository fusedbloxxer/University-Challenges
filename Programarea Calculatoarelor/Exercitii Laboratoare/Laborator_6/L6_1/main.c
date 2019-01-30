#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCTIONEAZA

int main()
{
    FILE *fp=fopen("date.in","r+");
    char c; int n=0;
    char text[1001];

    fscanf(fp,"%c",&c);

    //metoda 1
   // fgets(text,1000,fp); n=strlen(text);
    //metoda 2

    while(fscanf(fp,"%c",&text[n])!=-1)n++;
    text[n+1]='\0';

    int i;
    for(i=0;i<n;i++)
    if(text[i]==c)
    {
        int j;
        for(j=i;j<n-1;j++)
            text[j]=text[j+1];
        i--;
        n--;
    }

    text[n]='\0';

    //b)
    fprintf(fp,"%s",text);
    //a)
    fp=fopen("date.out","w");
    fprintf(fp,"%s",text);


    return 0;
}
