#include <stdio.h>
#include <stdlib.h>

void fourNumbers(int n) {
    if (n != 4) {
        if (n % 10 == 0 || n % 10 == 4) fourNumbers(n / 10);
        else fourNumbers(n * 2);
        printf("%d ", n);
    } else printf("4 ");
}

int main()
{
    fourNumbers(133);
    return 0;
}
