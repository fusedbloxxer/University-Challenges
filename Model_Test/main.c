#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
struct produs
{
    char nume[30];
    char eticheta[30];
    float pret;
    struct produs *next;
};
void scumpire(void *a, struct produs* produsCurent)
{
    produsCurent->pret += *(float*)a;
}
void ieftinire(void *a, struct produs* produsCurent)
{
    produsCurent->pret -= *(float*)a;
}
void schimbEticheta(void *a, struct produs* produsCurent)
{
    strcpy(produsCurent->eticheta, (char *)a);
}
void changeProducts(int *indexes, int nOfIndexes, void *a, void *operatie(void *, struct produs*), struct produs *head)
{
    int i = 0;
    struct produs* current;
    for(current = head; current != NULL; current = current->next)
    {
        int j;
        for(j = 0; j < nOfIndexes; j++)
        {
            if(indexes[j] == i)
                operatie(a, current);
        }
        i++;
    }
}
struct produs* get(int index, struct produs* head)
{
    /// Se obtine adresa nodului de pe pozitia index.
    int i;
    struct produs* current;
    for(current = head, i = 0; current != NULL; current = current->next, i++)
    {
        if(i == index)
            return current;
    }

    return NULL;
};
void innerSort(int left, int middle, int right, struct produs* head)
{
    int i = 0, j = 0;
    int N1, N2;
    N1 = middle - left + 1;
    N2 = right  - middle;
    struct produs* leftPart  = (struct produs*)malloc(sizeof(struct produs) * N1);
    struct produs* rightPart = (struct produs*)malloc(sizeof(struct produs) * N2);
    struct produs* index;

    for(index = get(left, head),  i = 0; i < N1; index = index->next, i++)
    {
        leftPart[i] = *index;
    }
    for(index = get(middle + 1, head), j = 0; j < N2; index = index->next, j++)
    {
        rightPart[j] = *index;
    }

    index = get(left, head);
    i=0;
    j=0;

    while(i < N1 && j < N2 && index->next != NULL)
    {
        /// Se concateneaza numele si eticheta dupa care se compara lexicografic.
        char concat_1[60], concat_2[60];
        strcpy(concat_1, leftPart[i].nume);
        strcat(concat_1, leftPart[i].eticheta);
        strcpy(concat_2, rightPart[j].nume);
        strcat(concat_2, rightPart[j].eticheta);
        int result = strcmp(concat_1, concat_2);

        if(result < 0)
        {
            index->pret =  leftPart[i].pret;
            strcpy(index->nume, leftPart[i].nume);
            strcpy(index->eticheta, leftPart[i].eticheta);
            i++;
        }
        else if(result > 0)
        {
            index->pret = rightPart[j].pret;
            strcpy(index->nume, rightPart[j].nume);
            strcpy(index->eticheta, rightPart[j].eticheta);
            j++;
        }
        else if(result == 0)
        {
            /// Altfel se va compara dupa lungimea numelui.
            if(strlen(leftPart[i].nume) < strlen(rightPart[j].nume))
            {
                index->pret =  leftPart[i].pret;
                strcpy(index->nume, leftPart[i].nume);
                strcpy(index->eticheta, leftPart[i].eticheta);
                i++;
            }
            else
            {
                index->pret = rightPart[j].pret;
                strcpy(index->nume, rightPart[j].nume);
                strcpy(index->eticheta, rightPart[j].eticheta);
                j++;
            }
        }
        index = index->next;
    }

    while(i < N1)
    {
        index->pret =  leftPart[i].pret;
        strcpy(index->nume, leftPart[i].nume);
        strcpy(index->eticheta, leftPart[i].eticheta);
        index = index->next;
        i++;
    }
    while(j < N2)
    {
        index->pret = rightPart[j].pret;
        strcpy(index->nume, rightPart[j].nume);
        strcpy(index->eticheta, rightPart[j].eticheta);
        index = index->next;
        j++;
    }
    free(leftPart);
    free(rightPart);
}
void mergeSort(int left, int right, struct produs* head)
{
    if(left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(left, middle, head);
        mergeSort(middle + 1, right, head);

        innerSort(left, middle, right, head);
    }
}
void add(struct produs** head, struct produs** tail, float price, char nume[30], char eticheta[30])
{
    if(*head == NULL)
    {
        *head = (struct produs *)malloc(sizeof(struct produs));
        (*head)->pret = price;
        (*head)->next = NULL;
        (*tail) = *head;
        strcpy((*head)->nume, nume);
        strcpy((*head)->eticheta, eticheta);
    }
    else
    {
        struct produs* newProduct = (struct produs*)malloc(sizeof(struct produs));
        newProduct->pret = price;
        newProduct->next = NULL;
        strcpy(newProduct->nume, nume);
        strcpy(newProduct->eticheta, eticheta);
        (*tail)->next = newProduct;
        (*tail) = newProduct;
    }
}
void removeAtTail(struct produs**head, struct produs**tail, char ch, int *N)
{
    int elim  = 0;
    int count = 0;
    struct produs* elements[3];
    struct produs* currentElement;
    /// ELIMINAM produsele de la CAPUL listei cat timp incep cu ch.
    while(*head != NULL && (*head)->nume[0] == ch)
    {
        currentElement = *head;
        if(count < 3)
        {
            /// Se retin primele 3 produse eliminate
            elements[count] = (struct produs*)malloc(sizeof(struct produs));
            memcpy(elements[count], currentElement, sizeof(struct produs));
            count++;
        }
        *head = currentElement->next;
        free(currentElement);
        elim++;
    }
    /// Daca s-au eliminat toate elementele, lista nu mai exista.
    if(*head == NULL)
        *tail = NULL;
    else
    {
        /// ELIMINAM elementele din INTERIORUL listei.
        for(currentElement = *head; currentElement->next != NULL && currentElement->next->next != NULL; currentElement = currentElement->next)
        {
            /// Daca sunt elemente consecutive ce incep cu ch, atunci le eliminam pe toate!
            /// *Daca nu am face asta ar sari peste un nod care trebuie eliminat.
            while(currentElement->next->nume[0] == ch)
            {
                if(count < 3)
                {
                    /// Se retin primele 3 produse eliminate
                    elements[count] = (struct produs*)malloc(sizeof(struct produs));
                    memcpy(elements[count], currentElement->next, sizeof(struct produs));
                    count++;
                }
                struct produs* aux = currentElement->next;
                currentElement->next = aux->next;
                free(aux);
                elim++;

                /// Trebuie verificat daca se mai pot elimina din lista
                if(currentElement->next->next == NULL)
                    break;
            }

            /// In functie de unele cazuri, pot aparea diverse erori.
            if(currentElement->next->next == NULL)
                break;
        }

        /// ELIMINAM elementul de la COADA in cazul in care incepe cu ch.
        if((*tail)->nume[0] == ch)
        {
            struct produs* aux = *tail;
            *tail = currentElement;
            currentElement->next = NULL;
            free(aux);
        }
    }
    /// Verificam cate noduri ne-au mai ramas in lista.
    *N = *N - elim;
    if(*N < 3)
    {
        printf("%d ", *N);
        int index;
        for(index = 0; index < count; index++)
        {
            /// Daca au ramas mai putin de 3, le adaugam pe primele 3 salvate in urma eliminarii.
            add(head, tail, elements[index]->pret, elements[index]->nume, elements[index]->eticheta);
            free(elements[index]);
            *N = *N + 1;
        }
    }
}
void newData(FILE* fin, char newFileName[30])
{
    FILE *fo = fopen(newFileName, "w");
    struct produs* newProduct = (struct produs*)malloc(sizeof(struct produs));

    while(fread(newProduct, sizeof(struct produs), 1, fin))
    {
        if(newProduct->pret > 10)
        {
            fprintf(fo, "%s %.3f\n", newProduct->nume, newProduct->pret);
        }
    }

    free(newProduct);
    fclose(fin);
    fclose(fo);
}
void printList(struct produs* head, char *message)
{
    printf("%s\n", message);
    int index;
    struct produs *current;
    for(index = 0, current = head; current != NULL; current = current->next, index ++)
    {
        printf("%d. %s %s %f\n", index, current->nume, current->eticheta, current->pret);
    }
    printf("\n\n");
}
int* readIndexes(int *length)
{
    printf("Numar de produse ce urmeaza sa fie modificate: ");
    fscanf(stdin, "%d", length);
    int *arrayOfIndexes = (int *)malloc(sizeof(int) * (*length));
    int index;
    printf("Introduceti pozitiile produselor: ");
    for(index = 0; index < *length; index++)
    {
        fscanf(stdin, "%d", &arrayOfIndexes[index]);
    }
    return arrayOfIndexes;
}
int main()
{
    int N, index = 0;
    struct produs *head = NULL,
                       *tail = NULL;
    FILE* F = fopen("date.in", "r");
    fscanf(F, "%d", &N);

    while(index != N)
    {
        float price;
        char nume[30], eticheta[30];

        fscanf(F, "%s", nume);
        fscanf(F, "%s", eticheta);
        fscanf(F, "%f", &price);

        add(&head, &tail, price, nume, eticheta);
        index++;
    }
    fclose(F);

    int x = 0;
    do
    {
        printf("Options:\n1. Scumpire\n2. Ieftinire\n3. Schimbare eticheta");
        printf("\n4. Sortare\n5. Micsorare lista\n6. Reactualizare Fisier\n7. Afisare produse\n8. Exit\n");
        printf(":");
        fscanf(stdin, "%d", &x);
        system("cls");

        switch(x)
        {
        case 1:
        {
            ///ex 1: Scumpire, ieftinire, schimbare eticheta
            float value;
            int nOfProducts = 0;
            int *indexes = readIndexes(&nOfProducts);
            printf("Valoare de adaugat: ");
            fscanf(stdin, "%f", &value);

            changeProducts(indexes, nOfProducts, (void*)&value, scumpire, head);
        }
        break;
        case 2:
        {
            float value;
            int nOfProducts = 0;
            int *indexes = readIndexes(&nOfProducts);
            printf("Valoare de scazut: ");
            fscanf(stdin, "%f", &value);

            changeProducts(indexes, nOfProducts, (void*)&value, ieftinire, head);
        }
        break;
        case 3:
        {
            char eticheta[30];
            int nOfProducts = 0;
            int *indexes = readIndexes(&nOfProducts);
            printf("Eticheta noua: ");
            fscanf(stdin, "%s", eticheta);

            changeProducts(indexes, nOfProducts, (void*)eticheta, schimbEticheta, head);
        }
        break;
        case 4:
        {
            ///ex2: Sortare lexicografica crescatoarea dupa:
            ///     * name+eticheta
            ///      -> name length
            mergeSort(0, N - 1, head);
        }
        break;
        case 5:
        {

            ///ex3: Sterge toate produsele al caror nume incepe cu 'c'
            char ch;
            printf("Eliminati produsele care incep cu caracterul:");
            ch = getch();
            //fscanf(stdin, "%c", &ch);

            removeAtTail(&head, &tail, ch, &N);
        }
        break;
        case 6:
        {
            /// Reactualizare a fisierului binar cu produsele actuale.
            struct produs *current;
            FILE *Fb = fopen("binary", "w");
            for(current = head; current != NULL; current = current->next)
            {
                fwrite(current, sizeof(struct produs), 1, Fb);
            }
            fclose(Fb);

            ///ex4: Citeste produsele din fisierul binar si afiseaza produsele cu pret > 10, in alt fisier.
            newData(fopen("binary", "r"), "date.out");
        }
        break;
        case 7:
        {
            printList(head, "Lista afisata: ");
            printf("\n\n Apasa pe o tasta ca sa continui . . .");
            getch();
        }
        break;
        case 8:
        {
            printf("Program closed succesfully!");
            return 0;
        }
        break;
        default:
        {
            printf("Bad input received!");
            return 0;
        }
        break;
        }
        system("cls");
    }
    while(x != 0);

    return 0;
}
