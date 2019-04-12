#include <stdio.h>
#include <stdlib.h>

int countApparitions(char * sequence, char index, char letter)
{
    if(sequence[index] != '\0')
    {
        if(letter == sequence[index])
            return 1 + countApparitions(sequence, index + 1, letter);
        return countApparitions(sequence, index + 1, letter);
    }
    else
        return 0;
}

int main()
{
    printf("Count = %d", countApparitions("abecedarcefrumoasaesteviatafaradragan", 0, 'a'));

    return 0;
}
