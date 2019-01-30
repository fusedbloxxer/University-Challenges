#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCTIONEAZA

int main()
{
    FILE *fp=fopen("date.in","r+");
    char firstLetter, secondLetter;
    char currentChar;

    fscanf(fp,"%c",&firstLetter);
    fgetc(fp);
    fscanf(fp,"%c",&secondLetter);
    fgetc(fp);

    while(fscanf(fp,"%c",&currentChar)!=-1)
    {
        if(currentChar==firstLetter)
        {
            fseek(fp,-1,SEEK_CUR);
            fprintf(fp,"%c",secondLetter);
            fflush(fp);
        }
    }
    return 0;
}
