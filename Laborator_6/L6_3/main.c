#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCTIONEAZA

int main()
{
    FILE*fp=fopen("words.txt","r+");

    char Words;

    while(fscanf(fp,"%c",&Words)!=-1)
    {
            if(Words>='a' && Words<='z')Words-=32;
            else if(Words>='A' && Words<='Z')Words+=32;

            fseek(fp,-1,SEEK_CUR);
            fputc(Words,fp);
            fflush(fp);
    }

    fclose(fp);
    return 0;
}
