#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(void *a, void *b) {
    return *(int *)a - *(int *)b;
}

int cmpStr(void *a, void *b) {
    return strcmp((char *)a, (char *)b);
}

int isEqual(void *array_1, void *array_2, int n_1, int n_2, int dim, int (*cmp)(void *, void *)) {
    if(n_1 != n_2) return 0;
    char *index;
    for(int i = 0; i < n_1; i++) {
        if(cmp((char *)array_1 + i * dim, (char *)array_2 + i * dim) != 0) return 0;
    }
    return 1;
}

int main()
{
    int arr_1[] = {1, 2, 3, 4, 5};
    int arr_2[] = {1, 2, 3, 4, 5};
    int arr_3[] = {1, 2, 3, 5, 6};

    char string_1[][10] = {"Alex", "Ana", "Maria"};
    char string_2[][10] = {"", "Ana", "Alex"};
    char string_3[][10] = {"Alex", "Ana", "Maria"};


    printf("%s\n", (isEqual(arr_1, arr_3, 5, 5, sizeof(int), cmp) == 1)?"true":"false");
    printf("%s\n", (isEqual(arr_1, arr_2, 5, 5, sizeof(int), cmp) == 1)?"true":"false");


    printf("%s\n", (isEqual(string_1, string_2, 3, 3, 11, cmpStr) == 1)?"true":"false");
    printf("%s\n", (isEqual(string_1, string_3, 3, 3, 11, cmpStr) == 1)?"true":"false");
    printf("%s\n", (isEqual(string_3, string_2, 3, 3, 11, cmpStr) == 1)?"true":"false");

    return 0;
}
