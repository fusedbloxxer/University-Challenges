#include <stdio.h>
#include <stdlib.h>

//Functioneaza
void reverse_string(char *string)
{
    int N = -1, index;
    while(string[++N] != 0);
    for(index = 0; index < N/2; index++)
    {
        char x = string[index];
        char y = string[N - 1 - index];

        string[index] = y;
        string [N - 1 - index] = x;
    }
}
int main()
{
    char string[] = "AAABRBRBCCC";
    reverse_string(string);

    printf("%s", string);

    return 0;
}
