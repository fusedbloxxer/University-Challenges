#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Este facuta dar se putea mai bine!

typedef struct
{
    char nume[31];
    unsigned long long int CNP: 44;
    unsigned short int varsta: 7;
    unsigned short int norma: 1;

} angajat;

int main()
{
    printf("SizeOfAngajat: %d\n\n",sizeof(angajat));

    FILE*fp=fopen("date.in","r");
    int n;
    fscanf(fp,"%d",&n);
    int i;
    angajat firma[n];

    for(i=0; i<n; i++)
    {
        fgetc(fp);
        fgets(firma[i].nume,30,fp);
        firma[i].nume[strlen(firma[i].nume)-1]='\0';

        unsigned long long int CNP;

        fscanf(fp,"%lld",&CNP);
        firma[i].CNP=CNP;
        fscanf(fp,"%hd",&CNP);
        firma[i].varsta=CNP;
        fscanf(fp,"%hd",&CNP);
        firma[i].norma=CNP;
    }

    unsigned long long test=(unsigned long long)1<<41;
    char *ch=&test;
    for(i=sizeof(unsigned long long)-1;i>=0;i--)
    {
        printf("%d ",*(ch+i));
    }

    for(i=0; i<n; i++)
    {
        if((firma[i].CNP&(test))==0 && (firma[i].varsta&(~0-((1<<5)-1)))==0 && firma[i].varsta!=31)
        printf("Nume: %s\nCNP: %lld\nVarsta: %hd\nNorma: %hd\n\n",firma[i].nume,firma[i].CNP,firma[i].varsta,firma[i].norma);
    }

    fclose(fp);

    return 0;
}
