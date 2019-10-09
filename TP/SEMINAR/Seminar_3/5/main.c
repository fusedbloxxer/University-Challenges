#include <stdio.h>
#include <stdlib.h>

int partition(int *array, int start, int end) {
    int middle = start + (end - start) / 2;

    while (start <= end) {
        while (array[start] < array[middle]) start++;
	while (array[end] > array[middle]) end--;

	if (start <= end) {
	    int x = array[start];
 	    array[start] = array[end];
	    array[end] = x;

	    start++;
	    end--;
        }	
    }

    return start;
}

void quickSort(int *array, int start, int end) {
    int index = partition(array, start, end);
    if (start < index - 1)
	    quickSort(array, start, index - 1);
    if (index < end)
	    quickSort(array, index, end);
}

int main(int argc, char **args) {
    FILE *input = fopen(args[1], "r");
    FILE *output = fopen(args[2], "w");

    int *array = NULL, n = 0, x;
    while(fscanf(input, "%d", &x) != -1)  {
	array = (int *)realloc(array, sizeof(int) * ++n);
	array[n - 1] = x;
    }

    quickSort(array, 0, n - 1);

    for (int i = 0; i < n; i++) {
	printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    fclose(input);
    fclose(output);
    return 0;
}
