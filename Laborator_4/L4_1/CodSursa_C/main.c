#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//MACROSTRUCTURI + CONSTANTE
#define MedieAdmitere(medie,info,mate,bac){\
medie=(float)((info+mate)*0.4+bac*0.2);\
}

#define prag 5

#define AFISARE_LISTA(Lista_Admitere, nr_candidati, c1, c2){\
int i;\
for(i=0; i<nr_candidati; i++)\
{\
    if(((Lista_Admitere+i)->buget==c1 && (Lista_Admitere+i)->admis==c2) || c1==-1 || ((Lista_Admitere+i)->buget==c1 && c2==-1))\
    {\
        int count;\
        char *tip;\
        if((Lista_Admitere+i)->buget==1)\
            {tip="BUGET";count=5;}\
        else\
        {\
            if((Lista_Admitere+i)->buget==0)\
                {tip="TAXA";count=6;}\
            else\
                {tip="PICAT";count=5;}\
        }\
        \
        printf("%s",(Lista_Admitere+i)->nume);\
        int a=strlen((Lista_Admitere+i)->nume);\
        \
        while(a<32){a++;printf(" ");}\
        printf("%d",(Lista_Admitere+i)->nr_legitimatie);\
        \
        a=0;while(a<4){a++;printf(" ");}\
        printf("%s",((Lista_Admitere+i)->admis==1)?"DA":"NU");\
        \
        a=0;while(a<4){a++;printf(" ");}\
        printf("%s",tip);\
        \
        a=0;while(a<count){a++;printf(" ");}\
        printf("%.2f",(Lista_Admitere+i)->medie);\
        printf("\n");\
    }\
}\
printf("________________________________________________________________________________________________\n");\
}
//MACROSTRUCTURI + CONSTANTE

FILE*fp;

typedef struct
{
    char nume[50];
    float nota_mate, nota_info,nota_bac, medie;
    int nr_legitimatie;
    unsigned char admis: 5, buget: 2;

} candidat;

void Admitere(candidat *p)
{
    p->medie=(float)(p->nota_info+p->nota_mate)*0.4+p->nota_bac*0.2; //80% EXAMEN, 20% BAC

    if(p->medie>=5)
        p->admis=1;
    else
        p->admis=0;            //NOTA >=5 PENTRU PROMOVABILITATE
}

int Insert_Candidat(candidat *cap, int index)
{
    //Se citesc informatiile
    fgets(&(cap+index)->nume,32,fp);                     //NUMELE CONCURENTULUI
    (cap+index)->nume[strlen((cap+index)->nume)-1]='\0'; //ELIMIN CARACTERUL '\n' DIN NUME PENTRU A FACE AFISAREA PE UN SINGUR RAND

    fscanf(fp,"%f",&(cap+index)->nota_mate);             //NOTELE SALE
    fscanf(fp,"%f",&(cap+index)->nota_info);
    fscanf(fp,"%f",&(cap+index)->nota_bac);
    fscanf(fp,"%d",&(cap+index)->nr_legitimatie);

    float f;
    fscanf(fp,"%c",&f);                                  //SE CITESTE CARACTERUL '\n' PENTRU A PUTEA CITI URMATORUL NUME!!

    //Se calculeaza media si promovabilitatea
    MedieAdmitere((cap+index)->medie,(cap+index)->nota_info,(cap+index)->nota_mate,(cap+index)->nota_bac);
    if((cap+index)->medie>=prag)
        (cap+index)->admis=1;
    else (cap+index)->admis=0;

    //VARIABILA FOLOSITA LA FINAL
    f=(cap+index)->medie;

    //Se parcurge vectorul si se compara cu fiecare element, sortandu-se astfel crescator(ord. alfabetica) la fiecare inserare.
    if(index)
    {
        candidat u=*(cap+index);
        int i=0;

        for(i=0; i<index; i++)
            if(strcmp((cap+i)->nume,u.nume)>0)
            {
                int j;
                for(j=index; j>i; j--)
                    *(cap+j)=*(cap+j-1);
                *(cap+i)=u;
                i=index;
            }
    }

    if(f>=prag)    //Se foloseste pentru a determina cati au fost admisi.
        return 1;
    return 0;
}

void bubblesort_medie(candidat *cap,int n)
{
    int ok;
    do
    {
        ok=0;
        int i;
        for(i=0; i<n-1; i++)
        {
            if((cap+i)->medie<(cap+i+1)->medie)
            {
                candidat u=*(cap+i);
                *(cap+i)=*(cap+i+1);
                *(cap+i+1)=u;
                ok=1;
            }
        }

    }
    while(ok==1);
}

void bubblesort_alfabetic(candidat *cap,int n)
{
    int ok;
    do
    {
        ok=0;
        int i;
        for(i=0; i<n-1; i++)
        {
            if(strcmp((cap+i)->nume,(cap+i+1)->nume)>0)
            {
                candidat u=*(cap+i);
                *(cap+i)=*(cap+i+1);
                *(cap+i+1)=u;
                ok=1;
            }
        }

    }
    while(ok==1);
}

void Tip_Finantare(candidat *cap, int n, int NR_ADMISI)
{
    int i, ratio;
    ratio=floor(0.75*NR_ADMISI);

    //Se sorteaza descrescator in functie de medie.
    bubblesort_medie(cap, n);

    for(i=0; i<n; i++)
        if(i<=ratio-1)
        {

            if((cap+i)->admis==1)(cap+i)->buget=1;  //Primele 75% de locuri sunt la BUGET.
        }
        else
        {
            if((cap+i)->admis==1)(cap+i)->buget=0;  //Restul 25% sunt la TAXA
            else
            {
                (cap+i)->buget=2;                   //Ceilalti au PICAT examenul.
            }
        }
}

int main()
{
    fp=fopen("date.in","r");
    int nr_candidati, i, NR_ADMISI=0;

    ///DECLARARE
    printf("Introduceti numarul de candidati! N=");
    scanf("%d",&nr_candidati);
    candidat Lista_Admitere[2000];

    ///Inserarea fiecarui candidat in lista de concurenti.
    for(i=0; i<nr_candidati; i++)
        NR_ADMISI+=Insert_Candidat(Lista_Admitere, i);

    ///Introducerea tipului de finantare(buget/taxa).
    Tip_Finantare(Lista_Admitere, nr_candidati, NR_ADMISI);

    ///0-Exit, 1-Toti candidatii Alfabetic, 2-Cei admisi la buget, 3-cei admisi la taxa, 4-cei respinsi(descrescator dupa medie;
    printf("NUMARUL DE ADMISI: %d NUMARUL DE CONCURENTI: %d\n",NR_ADMISI,nr_candidati);

    int x=-1, a=-2,f;
    while(x)
    {
        //FORMATARI PENTRU AFISARE
        printf("1-Toti candidatii alfabetic\n2-Cei admisi la buget\n3-Cei admisi la taxa\n4-Cei respinsi\n0-Exit\n\n");
        scanf("%d",&x);
        system ("cls"); ///WINDOWS ONLY!!!
        printf("\n________________________________________________________________________________________________\n");
        printf("            NUME               |LEGIT.|ADMIS|FINANTARE|MEDIE|Mod de afisare(");

        switch(x)
        {
        case 0:
            return 0;
        case 1:
        {
            printf("ALFABETIC)\n");
            bubblesort_alfabetic(Lista_Admitere,nr_candidati);
            a=-1;
            f=0;
            AFISARE_LISTA(Lista_Admitere,nr_candidati,a,f);

        }
        break;
        case 2:
        {
            a=1;
            f=1;
            printf("DOAR BUGET, DESCRESCATOR)\n");
            bubblesort_medie(Lista_Admitere,nr_candidati);
            AFISARE_LISTA(Lista_Admitere,nr_candidati,a,f);
        }
        break;
        case 3:
        {
            a=0;
            f=1;
            printf("DOAR TAXA, DESCRESCATOR)\n");
            bubblesort_medie(Lista_Admitere,nr_candidati);
            AFISARE_LISTA(Lista_Admitere,nr_candidati,a,f);
        }
        break;
        case 4:
        {
            a=2;
            f=-1;
            printf("RESPINSI)\n");
            bubblesort_medie(Lista_Admitere,nr_candidati);
            AFISARE_LISTA(Lista_Admitere,nr_candidati,a,f);
        }
        break;
        default:
            printf("Eroare. Cititi una din optiunile meniului.");
        }
    }
    fclose(fp);

    return 0;
}

/*
Incercari de quicksort.

void quicksort(candidat *cap, int left, int right)
{
    int i=left, j=right;

    while(i<=j)
    {
        int pivot=(i+j)/2;
        while((cap+i)->medie>(cap+pivot)->medie)
            i++;
        while((cap+j)->medie<(cap+pivot)->medie)
            j--;

        if(i<=j)
        {
            candidat x=*(cap+i);
            *(cap+i)=*(cap+j);
            *(cap+j)=x;
            i++;
            j--;
        }

    }

    if(j>left)
        quicksort(cap,left,j);
    if(right>i)
        quicksort(cap,i,right);
}

void alfsort(candidat *cap, int left, int right)
{
    int i=left, j=right;

    while(i<=j)
    {
        int pivot=(i+j)/2;
        while(strcmp((cap+i)->nume,(cap+pivot)->nume)<0)
            i++;
        while(strcmp((cap+j)->nume,(cap+pivot)->nume)>0)
            j--;

        if(i<=j)
        {
            candidat x=*(cap+i);
            *(cap+i)=*(cap+j);
            *(cap+j)=x;
            i++;
            j--;
        }

    }

    if(j>left)
        quicksort(cap,left,j);
    if(right>i)
        quicksort(cap,i,right);
}
*/
