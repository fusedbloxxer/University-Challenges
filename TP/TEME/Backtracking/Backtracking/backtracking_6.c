#include <stdio.h>
#include <stdlib.h>

int n;

void bk(int k, int num) {
    for (int i = 0; i < 9; i += 2) {
	if (k == 1) {
		if (i == 0) {	
			continue;
		}
	}

	num = (num / 10) * 10 + i;

	if (k == n && num % 3 == 0) {
		printf("%d\n", num);
	} else if (k < n) {
		bk(k + 1, num * 10);
	}
    }
}

int main()
{
    printf("N = ");
    scanf("%d", &n);

    if (n == 0) {
        printf("0");
    } else {
        bk(1, 0);
    }

    return 0;
}
