#include <stdio.h>
#include <stdlib.h>

//FUNCTIONEAZA

void copy_n(char dst[], char src[], int n)
{
    int index;
    for(index=0;index<n;index++)
    {
        if(src[index]!='\0')dst[index]=src[index];
        else dst[index]='\0';
    }

    dst[n]='\0';
}

int main()
{
    char s1[]="abecedar",s2[1000]="";
    copy_n(s2,s1,8);

    printf("%s",s2);
    return 0;
}
