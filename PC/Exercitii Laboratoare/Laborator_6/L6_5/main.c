#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCTIONEAZA

int main()
{
    FILE*fp=fopen("date.in","r");
    FILE*fo=fopen("date.out","w");

    char term[501], n, count=0;
    fscanf(stdin,"%500s",term);n=strlen(term);
    char s[501];
    while(fscanf(fp,"%500s",s)!=-1)
    {
        int h=strlen(s), f=0;
        for(count=0;count<h;count++)
        {
            if(s[count]==term[f])f++;
        }

        if(f==n)
        {
            fprintf(fo,"%s\n",s);
        }
    }

    fclose(fo);
    fclose(fp);
    return 0;
}
