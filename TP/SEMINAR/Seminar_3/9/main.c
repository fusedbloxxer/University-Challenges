#include <stdio.h>
#include <stdlib.h>

int mpow(int n, int power) {
	if (power != 0) {
		return n * mpow(n, power - 1);
	} else return 1;
}

void square(int** biarr, int l1, int l2, int c1, int c2) {
	if (l2 - l1 > 3) {
		int lm1 = l1 + (l2 - l1) / 3;
		int lm2 = l1+  2 * (l2 - l1) / 3;
		int cm1 = c1 + (c2 - c1) / 3;
		int cm2 = c1 + 2 * (c2 - c1) / 3;

		for (int i = lm1; i < lm2; i++) {
			for (int j = cm1; j < cm2; j++) {
				biarr[i][j] = 1;
			}
		}

		square(biarr, l1, lm1, c1, cm1); 
		square(biarr, l1, lm1, cm1, cm2); 
	 	square(biarr, l1, lm1, cm2, c2); 

		square(biarr, lm1, lm2, c1, cm1); 
		square(biarr, lm1, lm2, cm2, c2); 

		square(biarr, lm2, l2, c1, cm1); 
		square(biarr, lm2, l2, cm1, cm2); 
		square(biarr, lm2, l2, cm2, c2); 
	} else {
		biarr[l1 + 1][c1 + 1] = 1;
	}
}

void printBiArr(int **biarr, int n, FILE *output) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fprintf(output, "%d", biarr[i][j]);
		}
		fprintf(output, "\n");
	}	
	fprintf(output, "\n");
}

int main(int argc, char **args) {
	FILE *input = fopen(args[1], "r");
	FILE *output = fopen(args[2], "w");

	int n, **biarr;
	fscanf(input, "%d", &n);
	n = mpow(3, n);

	biarr = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++) {
		biarr[i] = (int *)calloc(n, sizeof(int));
	}
	square(biarr, 0, n, 0, n);
	printBiArr(biarr, n, output);

	for (int i = 0; i < n; i++) {
		free(biarr[i]);
	}
	free(biarr);

	fclose(input);
	fclose(output);
	return 0;
}
