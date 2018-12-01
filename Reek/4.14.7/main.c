#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCTIONEAZA

void deblank(char string[])
{
    int index=0;
    for(index=0;index<strlen(string)-1;index++)
    {
        if(string[index]==' ' && string[index+1]==' ')
        {
            strcpy(string+index,string+index+1);
            index--;
        }
    }

    string[strlen(string)]='\0';
    printf("%s",string);
}

int main()
{
    char s[]="Acee     este u  n c  a d   o   u     l    o     o   l";
    deblank(s);

    return 0;
}
