#include <stdio.h>
#include <stdlib.h>

int tenPower(int pow) {
    int ten = 1;
    while(pow != 0) {
        ten = ten * 10;
        pow--;
    }
    return ten;
}

void elim(int *x, int c) {
    int copy = *x;
    int result = 0;
    int i =0;

    while(copy != 0) {
        if(copy % 10 != c) {
            result = result + (copy % 10) * tenPower(i);
            i++;
        }
        copy = copy / 10;
    }
    *x = result;
}

int main()
{
    int x = 255003495;
    elim(&x, 2);
    printf("%d", x);

    return 0;
}
