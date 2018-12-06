#include <stdio.h>
#include <stdlib.h>

struct student {
    char nume[30], prenume[30];
    int nr_legitimatie;
    float medie_admitere;
};

int compare(void *a, void *b) {
    struct student *al = (struct student *) a;
    struct student *bl = (struct student *) b;

    if(al->medie_admitere < al->medie_admitere) return 1;
    else if(al->medie_admitere > al->medie_admitere) {
            return -1;
            else if()
    }
}

int main()
{
    int n, index_1;
    fscanf(stdin, "%d", &n);

    FILE *F = fopen("date.in", "r");
    struct student *List = (struct student *)malloc(sizeof(struct student) * n);
    for(index_1 = 0; index_1 < n; index_1++) {
        fscanf(F, "%d", &List[index_1].nr_legitimatie);
        fscanf(F, "%s", List[index_1].nume);
        fscanf(F, "%s", List[index_1].prenume);
        fscanf(F, "%f", &List[index_1].medie_admitere);
    }

    //qsort(List, n, sizeof(List), compare);


    // Afisare
    for(index_1 = 0; index_1 < n; index_1++) {
        fprintf("%d ", &List[index_1].nr_legitimatie);
        fprintf("%s ", List[index_1].nume);
        fprintf("%s ", List[index_1].prenume);
        fprintf("%f\n", &List[index_1].medie_admitere);
    }


    return 0;
}
