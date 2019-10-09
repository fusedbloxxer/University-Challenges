#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Sa se implemente quicksort, mergesort, bubblesort folosind programarea generica

int compareInt(void *a, void *b) {
    return *(int *)a - *(int *)b;
}

void merge_helper(void *a, int start, int middle, int nr_elem, int nr_oct, int (*cmp)(void *, void *)) {
    int length_1 = middle - start + 1;
    int length_2 = nr_elem - middle;
    void *subArray_1 = malloc(length_1 * nr_oct);
    void *subArray_2 = malloc(length_2 * nr_oct);

    memcpy(subArray_1, a + start * nr_oct, length_1 * nr_oct);
    memcpy(subArray_2, a + (middle + 1) * nr_oct, length_2 * nr_oct);

    int i = 0, j = 0, k = start;
    while(i < length_1 && j < length_2) {
        if(cmp(subArray_1 + i * nr_oct, subArray_2 + j * nr_oct) < 0) {
            memcpy(a + k * nr_oct, subArray_1 + i * nr_oct, nr_oct);
            k++;
            i++;
        } else {
            memcpy(a + k * nr_oct, subArray_2 + j * nr_oct, nr_oct);
            k++;
            j++;
        }
    }
    while(i < length_1) {
        memcpy(a + k * nr_oct, subArray_1 + i * nr_oct, nr_oct);
        k++;
        i++;
    }
    while(j < length_2) {
        memcpy(a + k * nr_oct, subArray_2 + j * nr_oct, nr_oct);
        k++;
        j++;
    }

    free(subArray_1);
    free(subArray_2);
}

void merge_sort(void *a, int start, int nr_elem, int nr_oct, int (*cmp)(void *, void *)) {
    if(start < nr_elem) {
        int middle = start + (nr_elem - start) / 2;
        merge_sort(a, start, middle, nr_oct, cmp);
        merge_sort(a, middle + 1, nr_elem,   nr_oct, cmp);
        merge_helper(a, start, middle, nr_elem,  nr_oct, cmp);
    }
}

void bubble_sort(void *a, int nr_elem, int nr_oct, int (*cmp)(void *, void *)) {
    for(int i = 0; i < nr_elem - 1; i++) {
        int index_1 = i * nr_oct;
        for(int j = i + 1; j < nr_elem; j++) {
            int index_2 = j * nr_oct;
            if(cmp(a + index_1 , a + index_2) > 0) {
                void *aux = malloc(nr_oct);
                memcpy(aux, a + index_1, nr_oct);
                memcpy(a + index_1, a + index_2, nr_oct);
                memcpy(a + index_2, aux, nr_oct);
                free(aux);
            }
        }
    }
}

int quick_helper(void *a, int start, void *element, int nr_elem, int nr_oct, int (*cmp)(void *, void *)) {
    while(start <= nr_elem) {
        while(cmp(a + start * nr_oct, element) < 0) {
            start++;
        }
        while(cmp(a + nr_elem * nr_oct, element) > 0) {
            nr_elem--;
        }
        if(start <= element) {
            void *aux = malloc(nr_oct);
            memcpy(aux, a + start * nr_oct, nr_oct);
            memcpy(a + start * nr_oct, a + nr_elem * nr_oct, nr_oct);
            memcpy(a + nr_elem * nr_oct, aux, nr_oct);
            start++;
            nr_elem--;
        }
    }
}

void quick_sort(void *a, int start, int nr_elem, int nr_oct, int (*cmp)(void *, void *)) {
    if(start < nr_elem) {
        void *element = malloc(nr_oct);
        memcpy(element, a + (start + (nr_elem - start) / 2) * nr_oct, nr_oct);

        int m = quick_helper(a, start, element, nr_elem, nr_oct, cmp);
        quick_sort(a, start, m - 1, nr_oct, cmp);
        quick_sort(a, m + 1, nr_elem, nr_oct, cmp);

        free(element);
    }
}

void printArray(int *array, int N) {
    for(int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void inverseOrder(int *array, int N) {
    for(int i = 0; i < N; i++) {
        array[i] = N - i;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int *array = malloc(sizeof(int) * N);

    inverseOrder(array, N);
    quick_sort(array, 0, N - 1, sizeof(int), compareInt);
    printf("QUICKSORT DONE\n");

    inverseOrder(array, N);
    merge_sort(array, 0, N - 1, sizeof(int), compareInt);
    printf("MERGESORT DONE\n");

    inverseOrder(array, N);
    bubble_sort(array, N, sizeof(int), compareInt);
    printf("BUBBLESORT DONE\n");
    printArray(array, N);

    free(array);
    return 0;
}
