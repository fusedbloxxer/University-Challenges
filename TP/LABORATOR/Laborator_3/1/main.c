#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int maxValue(int n, ...) {
    va_list list;
    va_start(list, n);

    int max;
    if(n == 0) return 0;
    else max = va_arg(list, int);

    for(int i = 1; i < n; i++) {
        int x = va_arg(list, int);
        if(max < x) max = x;
    }

    va_end(list);
    return max;
}

int test(int a, int b, int c, int d) {
    if(maxValue(4, a, b, c, d) == d && maxValue(3, a, b, c) == c && maxValue(2, a, b) == b)
        return 1;
    return 0;
}

int main()
{
    printf("%s\n", (test(-7,-5,0,5) == 1)?"true":"false");
    printf("%s\n", (test(5, 5, 5, 5) == 1)?"true":"false");

    return 0;
}
