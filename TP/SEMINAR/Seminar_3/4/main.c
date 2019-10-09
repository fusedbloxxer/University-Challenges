#include <stdio.h>
#include <stdlib.h>

void puzzle(int lg, int cg, int l1, int l2, int c1, int c2, FILE *output) {
    if (l2 - l1 == 1) {
        if (l1 != lg || c1 != cg) fprintf(output,"(%d, %d)", l1, c1); 
        if (l1 != lg || c2 != cg) fprintf(output,"(%d, %d)", l1, c2); 
        if (l2 != lg || c1 != cg) fprintf(output,"(%d, %d)", l2, c1); 
        if (l2 != lg || c2 != cg) fprintf(output,"(%d, %d)", l2, c2); 
	fprintf(output,"\n");
    } else {
	int lg1, cg1, lg2, cg2, lg3, cg3, lg4, cg4;
        int lm = (l2 + l1) / 2;
	int cm = (c2 + c1) / 2;

	lg1 = lm; cg1 = cm; 
	lg2 = lm; cg2 = cm + 1;
	lg3 = lm + 1; cg3 = cm;
	lg4 = lm + 1; cg4 = cm + 1;

        if (lg <= lm) {	
	    if (cg <= cm) {
		lg1 = lg;	
		cg1 = cg;
	    } else {
		lg2 = lg;
		cg2 = cg;
	    }
	} else {
	    if(cg <= cm) {
		lg3 = lg;
		cg3 = cg;
	    } else {
		lg4 = lg;
		cg4 = cg;
	    }
	}

        if (lg1 != lg || cg1 != cg) fprintf(output,"(%d, %d)", lg1, cg1); 
        if (lg2 != lg || cg2 != cg) fprintf(output,"(%d, %d)", lg2, cg2); 
        if (lg3 != lg || cg3 != cg) fprintf(output,"(%d, %d)", lg3, cg3); 
        if (lg4 != lg || cg4 != cg) fprintf(output,"(%d, %d)", lg4, cg4); 

        fprintf(output, "\n");

	puzzle(lg1, cg1, l1, lm, c1, cm, output);
	puzzle(lg2, cg2, l1, lm, cm + 1, c2, output);
	puzzle(lg3, cg3, lm + 1, l2, c1, cm, output);
	puzzle(lg4, cg4, lm + 1, l2, cm + 1, c2, output);
    }
}

int mpow(int n, int power) {
    if (power != 0) {
	return n * mpow(n, power - 1); 
    } else return 1;
}

int main(int argc, char **args) {
    FILE *input = fopen(args[1], "r");
    FILE *output = fopen(args[2], "w");

    int n, lg, cg;
    fscanf(input, "%d%d%d", &n, &lg, &cg);

    n = mpow(2, n);

    puzzle(lg, cg, 1, n, 1, n, output); 

    fclose(input);
    fclose(output);
    return 0;
}
