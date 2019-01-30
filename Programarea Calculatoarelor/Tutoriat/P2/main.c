#include <stdio.h>
#include <stdlib.h>

struct elev {
    char nume[30], prenume[30];
    float medie;
};

struct clasa {
    int clasa;
    int nrElevi;
    char litera;
    struct elev **elevi;
    float media_clasei;
};

struct registru {
    struct clasa **clase;
    int nrPromovoati, nrTotal;
};

struct elev * elevNou(char *nume, char *prenume, int medie)
{
    struct elev * myElev = (struct elev *)malloc(sizeof(struct elev));
    strcpy(myElev->nume, nume);
    strcpy(myElev->prenume, prenume);
    myElev->medie = medie;

    return myElev;
}

void asignare(struct elev* my_elev, struct clasa * my_clasa)
{
    my_clasa->elevi
    my_clasa->nrElevi++;
}

int main()
{

    return 0;
}
