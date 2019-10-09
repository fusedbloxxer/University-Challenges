#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int nrApp(int n, ...) {
    va_list list;
    va_start(list, n);
    int count = 0, x = va_arg(list, int);

    while(x != 0) {
        if(n == x) {
            count ++;
        }
        x = va_arg(list, int);
    }
    va_end(list);
    return count;
}

int test(int a, int b, int c, int d) {
    if(nrApp(a, b, c, d, 0) != 0 || nrApp(b, c, d, 0) !=0 || nrApp(c, d, 0) !=0) {
        return 0;
    }
    return 1;
}

int main()
{
    printf("%d", test(4, 5, 7, 7));
    return 0;
}
