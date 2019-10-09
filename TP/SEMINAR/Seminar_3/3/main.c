#include <stdio.h>
#include <stdlib.h>

#define pi 3.1415
int k = 0;


float calcArea(float cx, float cy, float r, float sx, float sy, float jx, float jy) {
    if (cx + r < jx && cx - r > sx && cy + r < sy && cy - r > jy) {
	// printf("Aria cercului");
        // printf("ADDED(%f)", (pi * r * r));
        return pi * r * r;
    } else if (sx > cx + r || jx < cx - r || sy < cy - r || jy > cy + r) {
	return 0;
    } else if (sx > cx - r && jx < cx + r && sy < cy + r && jy > cy - r) {
	// printf("Aria patratului.");
	// printf("ADDED(%f)", (jx - sx) * (jx - sx));
	return (float) (jx - sx) * (jx - sx);
    } else if (jx - sx > 0.0001) {
	float xm = (jx + sx) / (float) 2, ym = (sy + jy) / (float) 2;
	k++;
	return
		calcArea(cx, cy, r, sx, sy, xm, ym) + 
		calcArea(cx, cy, r, xm, sy, jx, ym) +
		calcArea(cx, cy, r, sx, ym, xm, jy) +
		calcArea(cx, cy, r, xm, ym, jx, jy);
    }
}

int main(int argc, char **args) {
    FILE *input = fopen(args[1], "r");
    FILE *output = fopen(args[2], "w");

    float cx, cy, r, sx, sy, jx, jy;
    fscanf(input, "%f%f%f", &cx, &cy, &r);
    fscanf(input, "%f%f%f%f", &sx, &sy, &jx, &jy);

    // printf("%f / 2 + %f / 2 = %f", jx, sx, (jx + sx) / (float) 2);
    fprintf(output, "%f", calcArea(cx, cy, r, sx, sy, jx, jy));

    fclose(input);
    fclose(output);
    return 0;
}
