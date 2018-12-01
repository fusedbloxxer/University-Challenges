#include <stdio.h>
#include <stdlib.h>

//FUNCTIONEAZA

void prime()
{
    int index;
    for(index=1;index<=100;index++)
    {
        int ok=0, i;
        for(i=2;i<=index/2;i++)
        if(index%i==0){ok=1;i=index/2;}

        if(ok==0)printf("%d ",index);
    }
}

int main()
{
    prime();

    return 0;
}
