#include <stdio.h>
#include <stdlib.h>
#include "../utils.c"

void printArray(int *arr, int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int cmpInt(void *a, void *b) {
    return
        -*(int *)a + *(int *)b;
}

int main(int argc, char **args)
{
    int na, nb, *a_arr, *b_arr;
    FILE *input = fopen(args[1], "r");
    FILE *output = fopen(args[2], "w");

    fscanf(input, "%d %d", &na, &nb);
    a_arr = malloc(sizeof(int) * na);
    b_arr = malloc(sizeof(int) * nb);
    for (int i = 0; i < na; i++) { 
	    fscanf(input, "%d", &a_arr[i]);
    }

    for (int i = 0; i < nb; i++) {
	    fscanf(input, "%d", &b_arr[i]);
    }

    mergeSort(a_arr, na, sizeof(int), cmpInt);
    mergeSort(b_arr, nb, sizeof(int), cmpInt);

    int sum = 0, bst = 0, bdr = nb - 1, ast = 0, adr = na - 1;
    while (bst <= bdr) {
        if (b_arr[bst] >= 0) {
		sum += b_arr[bst] * a_arr[ast]; 
		bst++;
		ast++;
	} else {
		sum += b_arr[bdr] * a_arr[adr];
		bdr--;
		adr--;
	}
    }


    printf("sum = %d", sum);
    fprintf(output, "sum = %d", sum);

    // printArray(a_arr, na);
    // printArray(b_arr, nb);

    fclose(input);
    fclose(output);
    return 0;
}
