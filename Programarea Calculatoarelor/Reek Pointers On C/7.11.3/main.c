#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascii_to_integer(char *string) {
    int newInt = 0; char *p;
    unsigned char check = 0;
    for(p = string; *p != '\0'; p++) {
        if(strchr("0123456789", *p) != NULL) {
            newInt = newInt * 10 + *p - '0';
        }
    }
    return newInt;
}

int main()
{
    char string[100];
    fgets(string, 100, stdin);
    printf("%d", ascii_to_integer(string));
    return 0;
}
