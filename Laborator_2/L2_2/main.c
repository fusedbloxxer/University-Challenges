#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
2.Se citesc 2 numere întregi x și n unde n este între 0 si 15. Să se afișeze: bitul n din x,
numărul x în care se situeaza bitul n, numărul x în care se șterge bitul n, numărul x în care se
complementează bitul n
*/

int main()
{
    int x;
    unsigned short int n;
    int i;

    printf("X=");
    scanf("%d",&x);
    printf("\nN=");
    scanf("%hd",&n);


    //Primul subpunct
    printf("\nBitul %d din %d este: ",n,x);

    if(x&(1<<n))
        printf("1");
    else printf("0");

    //Al doilea subpunct
     printf("\nNumarul %d in care se seteaza bitul %d este: %d",x,n,x|(1<<n));

    //Al treilea subpunct
    i=pow(2,32)-1;i^=(1<<n);
    printf("\nNumarul %d in care se sterge bitul %d este: %d",x,n,x&i);

    //Al patrulea subpunct
    printf("\nNumarul %d in care se complementeaza bitul %d este: %d",x,n,x^(1<<n));

    return 0;
}
