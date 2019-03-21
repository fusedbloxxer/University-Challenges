#include <stdio.h>
#include <stdlib.h>

int main()
{
    int S; scanf("%d", &S);
    int value = S * S * S / 27;

    if (S % 3 == 0) {
        printf("S = %d + %d + %d, P = %d", S/3, S/3, S/3, value);
    } else if ((S - S / 3) % 2 ==0) {
        printf("S = %d + %d + %d, P = %d", S/3, (S - S/3) / 2, (S - S/3) / 2, S/3 * ((S - S/3) / 2) * ((S - S/3) / 2));
    } else {
        int x = (S - S/3) / 2;
        if (2 * x + 1 + S / 3 == S) {
            printf("S = %d + %d + %d, P = %d", S/3, x, x + 1, (S / 3) * x * (x + 1));
        } else {
            printf("S = %d + %d + %d, P = %d", S/3, x, x - 1, (S / 3) * x * (x - 1));
        }
    }

    return 0;
}
