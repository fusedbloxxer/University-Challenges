#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b) {
    if (a * b == 0) return a + b;
    else {
       while (a % b != 0) { 
           int c = b;
	   b = a % b;
	   a = c;
       }
       return b;
    }
}

int cmmdcArr(int *array, int l, int r) {
    if (l == r) {
        return array[l];
    } else {
	int middle = l + (r - l) / 2;
        return cmmdc(cmmdcArr(array, l, middle),
			cmmdcArr(array, middle + 1, r));
    }
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

    fprintf(output, "%d", cmmdcArr(array, 0, n - 1));

    free(array);

    fclose(input);
    fclose(output);
	
    return 0;
}
