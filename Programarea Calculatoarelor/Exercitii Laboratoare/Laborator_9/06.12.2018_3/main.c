#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char nume[30], prenume[30];
    int nr_legitimatie;
    float medie_admitere;
};

int compare(void *a, void *b) {
    struct student *al = (struct student *) a;
    struct student *bl = (struct student *) b;

    if(al->medie_admitere < bl->medie_admitere) return 1;
    else if(al->medie_admitere > bl->medie_admitere)
            return -1;
            else {
                if(strcmp(al->nume, bl->nume) != 0) return strcmp(al->nume, bl->nume);
                else if(strcmp(al->prenume, bl->prenume) != 0) return strcmp(al->prenume, bl->prenume);
            }
}
// Functioneaza
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

    qsort(List, n, sizeof(struct student), compare);

    // Afisare
    for(index_1 = 0; index_1 < n; index_1++) {
        fprintf(stdout, "%d ", List[index_1].nr_legitimatie);
        fprintf(stdout, "%s ", List[index_1].nume);
        fprintf(stdout, "%s ", List[index_1].prenume);
        fprintf(stdout, "%f\n", List[index_1].medie_admitere);
    }
    return 0;
}
