#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCTIONEAZA

int substr( char dst[], char src[], int start,  int len )
{
    if(start<0 || len<0 || start>=strlen(src)){dst[0]=' ';dst[1]='\0';}
    else
    {
        int index, n=0;
        for(index=start;index<start+len;n++,index++)
            if(index<strlen(src))dst[n]=src[index];

        dst[n]='\0';
        printf("%s\n",dst);
    }

    return strlen(dst);
}

int main()
{
    char s1[]="ABECEDARabecedar\\SCAOAL!!";
    char s2[1000];

    int length=substr(s2,s1,27,5);
    printf("dst size is %d.",length);
    return 0;
}
