#include <stdio.h>
#include <stdlib.h>

int oglindit(int x, int y) {
    if(x != 0)
        return
            oglindit(x / 10, y * 10 + x % 10);
    return y;
}

char * palindrom(int x) {
    return
        (x - oglindit(x, 0) == 0)
        ?"true"
        :"false";
}

int main()
{
    printf("%s", palindrom(25252));

    return 0;
}
