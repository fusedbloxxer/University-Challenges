#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(int argc, char **args) {
    FILE *input = fopen(args[1], "r");
    FILE *output = fopen(args[2], "w");

    int n, *array;
    fscanf(input, "%d", &n);
    array = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
	fscanf(input, "%d", &array[i]);
    }

    int potential = 1, candidat = array[0];

    for (int i = 1; i < n; i++) {
	if (array[i] == candidat) {	
	    potential++;
	} else {
	    potential--;
	    if (potential == 0) {
                candidat = array[i];
		potential++;
	    }
	}
    }

    potential = 0;
    for (int i = 0; i < n; i++) {
	if (array[i] == candidat) {
	    if(++potential >= n/2 + 1) {
		    fprintf(output, "Winner is %d", candidat);
		    potential = -1;
		    break;
	    }
	}
    }

    if (potential != -1) {
	    fprintf(output, "No winner");
    }

    printArray(array, n);

    fclose(input);
    fclose(output);
    return 0;
}
