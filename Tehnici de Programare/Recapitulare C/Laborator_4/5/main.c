#include <stdio.h>
#include <stdlib.h>

int app(char *sequence, char c) {
    if(sequence[0] != '\0') {
        if(sequence[0] == c) {
            return 1 + app(sequence + 1, c);
        } else return app(sequence + 1, c);
    } else return 0;
}

int main()
{
    printf("%d", app("Hello world!\n", 'l'));
    return 0;
}
