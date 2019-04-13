#include <stdio.h>
#include <stdlib.h>

void readMatrix(int ***biarr, int *m, int *n, FILE *input) {
	fscanf(input, "%d %d", m, n);
	*biarr = (int **)malloc(sizeof(int *) * *m);

	for (int i = 0; i < *m; i++) {
		(*biarr)[i] = (int *)malloc(sizeof(int) * *n);
		for (int j = 0; j < *n; j++) {
			fscanf(input, "%d", &(*biarr)[i][j]);
		}
	}

}

void printBiArr(int **biarr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", biarr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void FILL(int **biarr, int i, int j) {
	if (biarr[i][j] == 0) {
		biarr[i][j] = 1;

		FILL(biarr, i - 1, j);
		FILL(biarr, i, j + 1);
		FILL(biarr, i + 1, j);
		FILL(biarr, i, j - 1);
	}
}

int main(int argc, char **args) {
	FILE *input = fopen(args[1], "r");
	FILE *output = fopen(args[2], "w");

	int m, n, lg, cg;
	int **biarr = NULL;

	readMatrix(&biarr, &m, &n, input);
	printBiArr(biarr, m, n);
	fscanf(input, "%d %d", &lg, &cg);

	FILL(biarr, lg, cg);
	printBiArr(biarr, m, n);

	for (int i = 0; i < m; i++) {
		free(biarr[i]);
	}
	free(biarr);

	fclose(input);
	fclose(output);
	return 0;
}
