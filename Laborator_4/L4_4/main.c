#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char adresa[101], tip[31];
    union
    {
        char sir[17];
        unsigned char balcon: 1;
        unsigned char comandat: 7;
    };
    float suprafata;
    unsigned int nr_camere;

} casa;

int main()
{
    FILE*fp=fopen("date.in","r");
    int N, i;
    fscanf(fp,"%d",&N);

    casa Lista[N];int m=-1;

    for(i=0; i<N; i++)
    {
        fgetc(fp);
        fgets(Lista[i].adresa,31,fp);
        Lista[i].adresa[strlen(Lista[i].adresa)-1]='\0';

        fscanf(fp,"%f",&Lista[i].suprafata);
        fscanf(fp,"%s",Lista[i].tip);
        fscanf(fp,"%u",&Lista[i].nr_camere);

        if(m==-1 && strcmp(Lista[i].tip,"garsoniera")==0)m=i;else if(m!=-1)
        if(Lista[m].suprafata<Lista[i].suprafata && strcmp(Lista[i].tip,"garsoniera")==0)m=i;

        if(strcmp(Lista[i].tip,"garsoniera")==0)
        {
            int u;
            fscanf(fp,"%d",&u);
            Lista[i].balcon=u;
        }
        else
        {
            if(strcmp(Lista[i].tip,"apartament")==0)
            {
                fgetc(fp);

                char u;
                fscanf(fp,"%c",&u);
                Lista[i].comandat=u;
            }
            else
            {
                if(strcmp(Lista[i].tip,"casa")==0)
                {
                    fgetc(fp);
                    fgets(Lista[i].sir,15,fp);
                }
            }
        }

    }

    printf("%s ",Lista[m].adresa);

    fclose(fp);
    return 0;
}
