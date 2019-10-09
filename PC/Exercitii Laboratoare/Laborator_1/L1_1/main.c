#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,c;
    printf("ax^2+bx+c=0\nSa se introduca a,b,c cu spatiu intre ele:");
    scanf("%d%d%d",&a,&b,&c);

    long double delta;
    delta=b*b-4*a*c;

    if(delta<0)
    {
        if(b<0)b=b*-1;delta*=-1;a*=2;
        printf("x1=(-%d+isqrt(%d))/%d\nx2=(-%d-isqrt(%d))/%d",b,(int)delta,a,b,(int)delta,a);
    }
    else
    {
        if(delta==0)
        {
            a*=2;b*=-1;
            printf("x=%.2lf",b/(double)a);
        }
        else
        {
            b*=-1;delta=(double)sqrt(delta);a*=2;
            printf("x1=%.3lf\nx2=%.3lf",(double)(b+delta)/a,(double)(b-delta)/a);
        }
    }

    return 0;
}
