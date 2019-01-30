#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCTIONEAZA

int main()
{
    char c[1000];
    fgets(c,1000,stdin);

    int index;
    for(index=0;index<strlen(c);index++)
        if(c[index]>='A' && c[index]<='Z')c[index]+=32;

    printf("%s",c);

    return 0;
}
