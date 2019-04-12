#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b)?a:b;
}

int minArr(int *array, int l, int r) {
    if (l < r) {
	    int middle = l + (r - l) / 2;
	    return min(minArr(array, l, middle), 
			    minArr(array, middle + 1, r));
    } else return array[r];
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

    fprintf(output, "%d", minArr(array, 0, n - 1));

    fclose(input);
    fclose(output);
	
    return 0;
}
