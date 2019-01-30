#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int izomorfe(char* X, char* Y)
{
    int N1 = strlen(X), N2 = strlen(Y);

    if(N1 != N2)
        return 0;
    else
    {
        int Positions[1000] = {0};
        int index_1, index_2;

        for(index_1 = 0; index_1 < N2; index_1++)
        {
            char currentX = '/', currentY;
            for(index_2 = 0; index_2 < N1; index_2++)
            {
                // Check if the letter has already been changed
                if(Positions[index_2] == 0)
                {
                    // Initialize Y letter and get the X letter that will be changed.
                    if(currentX == '/')
                    {
                        currentX = X[index_2];
                        currentY = Y[index_2];

                        X[index_2] = currentY;
                        Positions[index_2] = 1;
                    }
                    else if(X[index_2] == currentX)
                    {
                        X[index_2] = currentY;
                        Positions[index_2] = 1;
                    }
                }
            }
        }
        if(strcmp(X,Y) == 0)
            return 1;
        else
            return 0;
    }
}

int main()
{
    char *X = (char*)malloc(1000);
    char *Y = (char*)malloc(1000);

    scanf("%s", X);
    scanf("%s", Y);
    printf("%s", (izomorfe(X,Y) == 1)?"true":"false", X);

    return 0;
}
