#include <stdio.h>
#include <stdlib.h>

/*
Sa se construiasca o structura pentru a reprezenta numerele complexe.
    a) Adăugați în structură pointeri la funcții de afișare și citire ;
    b) Utilizand pointeri si functii definite in afara structurii, efectuati adunarea si
inmultirea a n numere complexe.
    c) Scrieţi o funcţie ce va avea ca parametri două numere complexe și un parametru
de tip pointer la funcţie. Folosind aceasta funcţie, tabelaţi aceste operații
matematice pentru numerele de forma a+ib cu 1<=a,b<=k (k citit).
*/

struct complex
{
    float Real, Imaginary;
    void (*Print)(struct complex *);
    void (*Read)(struct complex *);
};

void printComplex(struct complex* element)
{
    printf("%.2f %.2fi\n", element->Real, element->Imaginary);
}
void readComplex(struct complex* element)
{
    scanf("%f", &(element->Real));
    scanf("%f", &(element->Imaginary));
}
void sumComplex(struct complex* element, struct complex* Sum)
{
    Sum->Real = Sum->Real + element->Real;
    Sum->Imaginary = Sum->Imaginary + element->Imaginary;
}
void multiComplex(struct complex* element, struct complex* multi)
{
    float U= element->Real * multi->Real - (element->Imaginary * multi->Imaginary);
    multi->Imaginary = element->Imaginary * multi->Real + multi->Imaginary * element->Real;
    multi->Real = U;
}


struct complex* f_Math(struct complex* element, struct complex* element_2,
                        struct complex* (*operation)(struct complex*, struct complex*))
{

    return operation(element, element_2);
}
int main()
{
    int N, index, index_2, K;
    struct complex* SUM = (struct complex*)calloc(2, sizeof(struct complex));
    SUM->Print = printComplex;
    struct complex* MULTI = (struct complex*)malloc(sizeof(struct complex));
    MULTI->Print= printComplex;

    printf("N=");
    fscanf(stdin, "%d", &N);
    struct complex *Head = (struct complex *)malloc(N * sizeof(struct complex));

    for(index = 0; index < N; index++)
    {
        (Head + index)->Read = readComplex;
        (Head + index)->Print = printComplex;
        (Head + index)->Read(Head + index);

        sumComplex((Head + index), SUM);
        if(index==0)
        {
            MULTI->Real = Head->Real;
            MULTI->Imaginary = Head->Imaginary;
        }
        else
         multiComplex(Head + index, MULTI);
    }

    for(index = 0; index < N; index++)
    {
        (Head + index)->Print(Head + index);
    }

    printf("Sum of elements = ");SUM->Print(SUM);
    printf("Product of elements = ");MULTI->Print(MULTI);

    fprintf(stdout, "Read K: ");
    fscanf(stdin, "%d", &K);

    unsigned char op;
    struct complex *a = (struct complex *)malloc(sizeof(struct complex));
    struct complex *b = (struct complex *)malloc(sizeof(struct complex));

    printf("Read the first element(a, b): ");
    readComplex(a);
    if(a->Real<1 || a->Imaginary<1 || a->Imaginary>k || a->Real>k){printf("Eroare!");return -1;}

    printf("Read the second element(a, b): ");
    readComplex(b);
    if(b->Real<1 || b->Imaginary<1 || b->Imaginary>k || b->Real>k){printf("Eroare!");return -1;}

    printf("What operation do you want to execute: +, - ,*, /");
    fscanf(stdin, "%c", &op);

    switch(op)
    {
        case '+':
            {
                sumComplex(a,b);
                printComplex(b);
            }break;
        case '-':
            {
                sumComplex(a,b);
                printComplex(b);
            }break;
        case '*':
            {
                multiComplex(a,b);
                printComplex(b);
            }break;
        case '/':
            {
                sumComplex(a,b);
                printComplex(b);
            }break;
    }



    return 0;
}
