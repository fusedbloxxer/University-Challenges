#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCTIONEAZA

int main()
{
    char c[1000];
    fgets(c,1000,stdin);

    int index;
    for(index=0; index<strlen(c); index++)
    {
        if(c[index]<='Z' && c[index]>='A')
        {
            if(c[index]+13>'Z')
                c[index]-=13;
            else
                c[index]+=13;
        }
        else
        {
            if(c[index]<='z' && c[index]>='a')
            {
                if(c[index]+13>'z')
                    c[index]-=13;
                else
                    c[index]+=13;
            }

        }
    }

    printf("%s",c);

    return 0;
}
