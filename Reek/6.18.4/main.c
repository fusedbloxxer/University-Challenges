#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Functioneaza
unsigned char* The_Sieve_of_Eratosthenes(unsigned long sup) {
    unsigned char* array = (unsigned char *)malloc((sup) * sizeof(unsigned char*));
    memset(array, 1, sup);
    unsigned long index;
    for(index = 0; index < sup; index++) {
        if(array[index] == 1) {
            unsigned long index_2 = 2 + index * 2;
            while(index_2 < sup) {
                array[index_2] =  0;
                index_2 += 2 + index;
            }
        }
    }
    return array;
}
// Functioneaza - Retine doar numerele impare si poate memora de doua ori mai multe numere prime comparativ cu prima functie.
unsigned char* The_Sieve_of_Eratosthenes2(unsigned long sup) {
    unsigned char* array = (unsigned char *)malloc((sup) * sizeof(unsigned char*));
    memset(array, 1, sup);
    unsigned long index;
    for(index = 0; index < sup; index++) {
        if(array[index] == 1) {
            unsigned long index_2 = index + index * 2 + 3;
            while(index_2 < sup) {
                array[index_2] =  0;
                index_2 += index * 2 + 3;
            }
        }
    }
    return array;
}
int main()
{
    unsigned long index, N = 1000;
    unsigned char *myArray1 = The_Sieve_of_Eratosthenes(N);
    unsigned char *myArray = The_Sieve_of_Eratosthenes2(N);

    printf("(Metoda 1)Numerele prime de la 2 la %d: \n", N);
    for(index = 0; index < N; index++) {
        if(myArray1[index] == 1) {
            printf("%d ", index + 2);
        }
    }
    printf("\n");

    printf("(Metoda 2)Numerele prime de la 2 la %d: \n2 ", N);
    for(index = 0; index < N; index++) {
        if(myArray[index] == 1) {
            printf("%d ", index * 2 + 3);
        }
    }
    printf("\n");
    return 0;
}
