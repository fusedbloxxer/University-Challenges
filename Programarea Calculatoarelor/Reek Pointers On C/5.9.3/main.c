#include <stdio.h>
#include <stdlib.h>

//FUNCTIONEAZA

unsigned int reverse_bits( unsigned int value )
{
    unsigned int finalValue=0;int ok=0;
    unsigned int index;
    for(index=0;index<sizeof(unsigned int)*8;index++)
    {
        if(((1<<index)&value)!=0)
        {
            printf("1");
            finalValue=finalValue|(1<<(sizeof(unsigned int)*8-1-index));
        }else printf("0");
    }

    return finalValue;
}

int main()
{
    printf(" %u",reverse_bits(25));

    return 0;
}
