#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCTIONEAZA

int main()
{
    FILE*fp=fopen("date.in","r");
    FILE*fo=fopen("date.out","w");

    char s1[129], s2[129];

    int check=0;
    fgets(s1,128,fp);

    while(fgets(s2,128,fp)!=NULL)
    {
        if(strcmp(s1,s2)==0){check=1;}
        else if(check==1){check=0;fprintf(fo,"%s",s1);}

        strcpy(s1,s2);
    }

    if(check==1)fprintf(fo,"%s",s1);

    return 0;
}
