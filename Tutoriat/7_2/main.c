#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rotire(char* X, char* Y)
{
    int N1 = strlen(X), N2 = strlen(Y);
    if(N1 != N2)
        return 0;
    else
    {
        N2 = N1;
        char c;
        while(N2-- != 0)
        {
            c = X[0];
            strcpy(X, X + 1);
            X[N1 - 1] = c;
            X[N1] ='\0';
            if(strcmp(X, Y) == 0)
                return 1;
        }
        return 0;
    }
}

int main()
{
    char *X, *Y;
    X = (char *)malloc(1000);
    Y = (char *)malloc(1000);

    fscanf(stdin, "%s", X);
    fscanf(stdin, "%s", Y);
    printf("%s", (rotire(X, Y)==1)?"true":"false");

    return 0;
}
