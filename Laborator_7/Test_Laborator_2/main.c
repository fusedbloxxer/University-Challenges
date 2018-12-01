#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct client
{
    char nume[31];
    int IBAN;
    unsigned char stare_civila:1;
    unsigned char bit_paritate:1;
};

//Subpunctul 1
void citire(int *size, struct client*Clienti)
{
    scanf("%d",size);

    int index;
    for(index=0; index<*size; index++)
    {
        scanf("%s",Clienti[index].nume);
        scanf("%d",&Clienti[index].IBAN);

        char aux[31];
        scanf("%s",aux);

        if(strcmp(aux,"casatorit")==0)
            Clienti[index].stare_civila=1;
        else
            Clienti[index].stare_civila=0;

    }
}

void afisare(int size, struct client*Clienti)
{
    int index;
    for(index=0; index<size; index++)
    {
        printf("%s ",Clienti[index].nume);
        printf("%d ",Clienti[index].IBAN);
        printf("bit_stare_civila: %d ",Clienti[index].stare_civila);
        printf("bit_paritate: %d\n",Clienti[index].bit_paritate);
    }

    printf("\n");
}

//Subpunctul 2
int bitCount(int IBAN)
{
    int k=0;
    while(IBAN!=0)
    {
        IBAN=IBAN&(IBAN-1);
        k++;
    }
    return k;
}

int binary(int IBAN)
{
    if(IBAN==0)
    {
        return 0;
    }
    else
        return IBAN%2 + binary(IBAN/2) * 10;
}

void set_bit_paritate(int size, struct client *Clienti)
{
    int index;
    for(index=0; index<size; index++)
    {
        Clienti[index].bit_paritate=bitCount(Clienti[index].IBAN);
        /*
            VARIANTA 2

        int count=0, x=binary(Clienti[index].IBAN);
        while(x!=0)
            {
            if(x%10==1)count++;x=x/10;
            }
        count=count%2;
        Clienti[index].bit_paritate=count;*/
    }
}

//Subpunctul 3
int compare_stare_civila(void *a, void *b)
{
    struct client *al=(struct client*)a;
    struct client *bl=(struct client*)b;

    if(al->stare_civila==1 && bl->stare_civila==0)
        return 1;
    else if(al->stare_civila==0 && bl->stare_civila==1)
        return -1;
    else
        return 0;
}

void reOrdering(int size, struct client *Clienti)
{
    qsort(Clienti,size,sizeof(struct client),compare_stare_civila);
}

//Subpunctul 4
void noMemPrint(FILE*f)
{
    char q[]="AEIOU";

    while(fgetc(f)!=-1)
    {
        fseek(f,-1,SEEK_CUR);

        int ok=0;
        if(strchr(q,fgetc(f))==NULL)
        {
            ok=1;
            fseek(f,-1,SEEK_CUR);
        }

        while(fgetc(f)!='\n')
        {
            if(ok==1)
            {
                fseek(f,-1,SEEK_CUR);
                printf("%c",fgetc(f));
            }
        }

        if(ok==1)printf("\n");
    }

}

int main()
{
    struct client List[40];
    int size;

    citire(&size,List);
    reOrdering(size,List);
    //afisare(size,List);

    noMemPrint(fopen("date.in","r"));

    return 0;
}
