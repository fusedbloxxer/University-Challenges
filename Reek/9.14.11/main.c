#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[100]; unsigned int count = 0;
    while(fgets(buffer, 100, stdin) != -1) {

        char *p = strtok(buffer, " ");
        while(p) {
            if(strcmp(p, "the") == 0 || strcmp(p, "the\n") == 0)
            count++;
            p = strtok(NULL, " ");
        }
        printf("Numer of apparitions: %d\n", count);
    }
    printf("The number of time \"the\" appeared: %d", count);
    return 0;
}
