#include <stdio.h>
#include <stdlib.h>

//FUNCTIONEAZA

int main()
{
    unsigned long int x, y , z;

    fscanf(stdin,"%u%u%u", &x, &y, &z);

    if(x==y && y==z)
    {
        printf("equilateral");
    }
    else
    {
        if(x==y || x==z || y==z)
            printf("isosceles");
        else printf("scalene");
    }

    return 0;
}
