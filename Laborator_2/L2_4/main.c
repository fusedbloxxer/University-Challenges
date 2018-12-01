#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
4. Scrieți un program care primește ca input de la tastatură scrierea unui număr în baza 2 și
calculează direct scrierea acestuia în baza 16 (nu mai trece prin baza intermediară 10).
Realizați acest lucru inversând cele două baze (input – scrierea în baza 16, output – scrierea
în baza 2).
*/

void Decimal_to_HD(int x)
{
    int u=0,i,ok=0;
    for(i=31; i>=0; i--)
    {
        if((x&(1<<i))!=0)
        {
            u=u+pow(2,i%4);
            ok=1;
        }
        if(i%4==0)
        {
            if(ok==1)
            {
                if(u<10)printf("%d",u);
                else
                {
                    fflush(stdin);
                    switch(u)
                    {
                    case 10:
                        printf("a");
                        break;
                    case 11:
                        printf("b");
                        break;
                    case 12:
                        printf("c");
                        break;
                    case 13:
                        printf("d");
                        break;
                    case 14:
                        printf("e");
                        break;
                    case 15:
                        printf("f");
                        break;
                    default:
                        printf("N");
                        break;
                    }
                }
            }
            u=0;
        }
    }
}

//x - elementul, i - pozitia curenta, k - suma curenta, ok
void Binary_to_HD(int x,int i,int k)
{
    if(i<32)
    {
        k=k+pow(2,i%4)*(x%10);
        if(i%4==3 && i!=0)Binary_to_HD(x/10,i+1,0);
        else Binary_to_HD(x/10,i+1,k);

        if(i%4==3 && i!=0)
        {
            if(k<10 & k!=0)printf("%d",k);
                else
                {
                    switch(k)
                    {
                    case 10:
                        printf("A");
                        break;
                    case 11:
                        printf("B");
                        break;
                    case 12:
                        printf("C");
                        break;
                    case 13:
                        printf("D");
                        break;
                    case 14:
                        printf("E");
                        break;
                    case 15:
                        printf("F");
                        break;
                    }
                }
        }
    }
}

void HD_to_Binary(int x)
{
    printf("\nMetoda2: ");

    int i;
    for(i=31;i>=0;i--)
        printf("%d",(x&(1<<i))?1:0);
}

int x;

int main()
{
    int i=0,u=0,ok=0;
    scanf("%d",&x);

    //HD_to_Binary(x); //"%xd" - in scanf pentru citire.
    Binary_to_HD(x,0,0);

    return 0;
}
