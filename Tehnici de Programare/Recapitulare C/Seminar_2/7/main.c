#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Fara comparator

void * search(void * t, int n, int x, int dim) {
    char *index;
    for(int i = 0; i < n; i++) {
        index = (char *)t + i * dim;
        if(memcmp(index, &x, dim) == 0) {
            return index;
        }
    }
    return NULL;
}

void searchIndex(void *t, int n, int x, int dim) {
    int check = 0;
    char *index, u = 0;
    while((index = search((char *)t + u * dim, n, x, dim)) != NULL) {
        check = 1;
        u = (index - (char *)t) / dim;
        printf("%d ", u);
        u++;
    }
    if(check == 0) {
        printf("Valoare inexistenta!");
    }
}

int main()
{
    int arr_3[] = {3, 1, 2, 4, 3, 6, 3};
    searchIndex(arr_3, 7, 3,sizeof(int));

    return 0;
}
