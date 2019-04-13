#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *array, int length) {
    for (int i = 0; i < length; i++) {
	printf("%d ", array[i]);
    }
    printf("\n");
}


void merge(int *array, int start, int middle, int end) {
    int n1 = middle - start + 1;
    int n2 = end - middle;

    int *left = (int *)malloc(sizeof(int) * n1);
    int *right = (int *)malloc(sizeof(int) * n2);

    memcpy(left, array + start, sizeof(int) * n1);
    memcpy(right, array + middle + 1, sizeof(int) * n2);

//    printArray(left, n1);
//    printArray(right, n2);

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
	    array[k] = left[i];
	    k++;
	    i++;
	} else {
	    array[k] = right[j];
	    k++;
	    j++;
	}
    }

    while (i < n1) {
	    array[k] = left[i];
	    k++;
	    i++;
    }

    while (j < n2) {
    	array[k] = right[j];
	k++;
	j++;
    }

    free(left);
    free(right);
}

void mergeSort(int *array, int start, int end) {
    if (start < end) {
	int middle = start + (end - start) / 2;

        mergeSort(array, start, middle);
	mergeSort(array, middle + 1, end);
	merge(array, start, middle, end);
    }
}

int main(int argc, char **args) {
    FILE *input = fopen(args[1], "r");
    FILE *output = fopen(args[2], "w");

    int *array = NULL, n = 0, x;
    while(fscanf(input, "%d", &x) != -1)  {
	array = (int *)realloc(array, sizeof(int) * ++n);
	array[n - 1] = x;
    }

    mergeSort(array, 0, n - 1);

    for (int i = 0; i < n; i++) {
	printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    fclose(input);
    fclose(output);
    return 0;
}
