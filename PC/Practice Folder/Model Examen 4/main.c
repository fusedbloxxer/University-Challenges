#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Felicitari
{
    int nrFelicitari;
    char **mesaj_felicitare;
    int  *lengths;
    struct Cadou ** listaCadouri;
};

struct Cadou
{
    int nrCadouri;
    char denumire[30];
};

struct Felicitari* readFelicitari(char fileName[30])
{
    struct Felicitari* felicitari = (struct Felicitari *)malloc(sizeof(struct Felicitari));
    FILE* file = fopen(fileName, "r");
    fscanf(file, "%d", &felicitari->nrFelicitari);
    felicitari->listaCadouri = (struct Cadou **)malloc(sizeof(struct Cadou *) * felicitari->nrFelicitari);
    felicitari->mesaj_felicitare = (char **)malloc(sizeof(char *) * felicitari->nrFelicitari);
    felicitari->lengths = (int *)malloc(sizeof(int) * felicitari->nrFelicitari);
    fgetc(file);

    int i;
    for(i = 0; i < felicitari->nrFelicitari; i++)
    {
        /// Citirea mesajului
        felicitari->mesaj_felicitare[i] = (char *)malloc(sizeof(char) * 30);
        int length = 0;
        char c;
        do
        {
            /// Citesc cate un caracter diferit de cifre.
            c = fgetc(file);
            felicitari->mesaj_felicitare[i][length++] = c;
        }
        while(c < '0' || c > '9');
        /// Cand s-a gasit prima cifra, o sterg din denumire
        felicitari->mesaj_felicitare[i][length - 1] = '\0';
        /// Dupa care mut cursorul inapoi cu 1 din fisier, pentru a citi din nou cifra care reprezinta numarul de cadouri.
        fseek(file, -1, SEEK_CUR);

        /// Citesc toata linia pana la sfarsit folosind un buffer si separ cifrele/cadourile cu strtok si niste separatori.
        char buffer[1000], separatori[] = " ,.!?";
        fgets(buffer, 1000, file);
        char *p = strtok(buffer, separatori);

        int j = 0;
        while(p != NULL)
        {
            /// Cand j este par citesc numarul de cadouri.
            if(j % 2 == 0)
            {
                if(j == 0)
                {
                    /// MAlloc primul element din lista, ca sa o initializez cu o pereche
                    length = 1;
                    felicitari->listaCadouri[i] = (struct Cadou *)malloc(sizeof(struct Cadou));
                }
                else
                {
                    /// Realloc cate un element in plus.
                    felicitari->listaCadouri[i] = (struct Cadou *)realloc(felicitari->listaCadouri[i], length * sizeof(struct Cadou));

                }
                /// Citesc dintr-un string cifra/numarul de cadouri
                sscanf(p, "%d", &felicitari->listaCadouri[i][length - 1].nrCadouri);
            }
            else
            {
                /// Cand j este impar citesc denumirea cadoului si apoi cresc indexul.
                strcpy(felicitari->listaCadouri[i][length - 1].denumire, p);
                length++;
            }
            j++;
            p = strtok(NULL, separatori);
        }
        /// Inlocuiesc penultimul caracter cu '\0' deoarece acolo ar sta caracterul newline si nu vrem asta
        if(i + 1 != felicitari->nrFelicitari)
        {
            felicitari->listaCadouri[i][length - 2].denumire[strlen(felicitari->listaCadouri[i][length - 2].denumire) - 1] = '\0';
        }
        felicitari->lengths[i] = length - 1;
    }
    fclose(file);
    return felicitari;
}

void afisareFelicitari(struct Felicitari *felicitari)
{
    for(int i = 0; i < felicitari->nrFelicitari; i++)
    {
        //printf("MESAJ: %s\n", felicitari->mesaj_felicitare[i]);
        for(int j = 0; j < felicitari->lengths[i]; j++)
        {
            printf("%d %s ", felicitari->listaCadouri[i][j].nrCadouri, felicitari->listaCadouri[i][j].denumire);
        }
        printf("\n");
    }
    printf("\n");
}

int compareQuantity(void *a, void *b)
{
    struct Cadou *al = (struct Cadou *)a;
    struct Cadou *bl = (struct Cadou *)b;

    return al->nrCadouri - bl->nrCadouri;
}

void sortByQuantity(struct Felicitari *felicitari)
{
    for(int i = 0; i < felicitari->nrFelicitari; i++)
    {
        for(int j = 0; j < felicitari->lengths[i]; j++)
        {
            qsort(felicitari->listaCadouri[i], felicitari->lengths[i], sizeof(struct Cadou), compareQuantity);
        }
    }
}

void addAtIndex(int index, struct Felicitari *felicitari, struct Cadou newCadou)
{
    if(index < felicitari->nrFelicitari)
    {
        int i = 0;
        while(i < felicitari->lengths[index])
        {
            if(compareQuantity((void *)&felicitari->listaCadouri[index][i], (void*)&newCadou) > 0)
                break;
            i++;
        }
        felicitari->listaCadouri[index] = (struct Cadou *)realloc(felicitari->listaCadouri[index], (felicitari->lengths[index] + 1) * sizeof(struct Cadou));
        for(int j = felicitari->lengths[index]; j > i; j--)
        {
            felicitari->listaCadouri[index][j] = felicitari->listaCadouri[index][j - 1];
        }
        felicitari->listaCadouri[index][i] = newCadou;
        felicitari->lengths[index]++;
    }
}

void printToFile(char fileName[30], struct Felicitari *felicitari)
{
    FILE* file = fopen(fileName, "w");
    fprintf(file, "%d\n", felicitari->nrFelicitari);
    sortByQuantity(felicitari);
    for(int i = 0; i < felicitari->nrFelicitari; i++)
    {
        for(int j = 0; j < felicitari->lengths[i]; j++)
        {
            fprintf(file, "%d %s", felicitari->listaCadouri[i][j].nrCadouri, felicitari->listaCadouri[i][j].denumire);
            if(j + 1 < felicitari->lengths[i])
            {
                fprintf(file, ", ");
            }
        }
        if(i + 1 < felicitari->nrFelicitari)
        {
            fprintf(file, "\n");
        }
    }
    fclose(file);
}

int main()
{
    struct Felicitari* felicitari = readFelicitari("date.in");
    afisareFelicitari(felicitari);
    sortByQuantity(felicitari);
    afisareFelicitari(felicitari);

    struct Cadou newCadou;
    strcpy(newCadou.denumire, "PlayStation");
    newCadou.nrCadouri = 5;

    // Adaug acelasi cadou de 3 ori
    addAtIndex(0, felicitari, newCadou);
    afisareFelicitari(felicitari);
    addAtIndex(0, felicitari, newCadou);
    afisareFelicitari(felicitari);
    addAtIndex(0, felicitari, newCadou);
    afisareFelicitari(felicitari);

    printToFile("output.txt", felicitari);
    return 0;
}
