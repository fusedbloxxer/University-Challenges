#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b) {
    if(a * b == 0) return a + b;
    if(a % b == 0) return b;
    return cmmdc(b, a % b);
}

void getCMMDC(int *array, int n, int *c) {
    if(n != 0) {
        *c = cmmdc(array[n], *c);
        getCMMDC(array, n - 1, c);
    }
    else printf("%d", *c);
}

int main()
{
    int c = 0;
    int arr[] = {8, 8, 4, 24, 36, 12};
    getCMMDC(arr, 6 - 1, &c);

    return 0;
}
