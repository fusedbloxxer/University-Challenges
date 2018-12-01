#include <stdio.h>
#include <stdlib.h>

//FUNCTIONEAZA

float root(float Term, float pTerm)
{
    float cTerm=(pTerm+Term/pTerm)/2;

    if(pTerm==cTerm){printf("%f",cTerm);return;}
    else
    {
        root(Term,cTerm);
    }

}

int main()
{
    float N;
    scanf("%f",&N);
    root(N,1);

    return 0;
}
