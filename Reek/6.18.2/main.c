#include <stdio.h>
#include <stdlib.h>

//Functioneaza
int del_substr(char *str, char const *substr)
{
    if(substr == NULL)
        return 0;
    else
    {
        int index;
        for(index = 0; str[index] != '\0'; index++)
        {
            int index_2, currentPosition = index, check = 0;

            for(index_2 = 0; substr[index_2] != '\0' && check == 0; index_2++)
            {
                if(str[currentPosition] != substr[index_2])
                {
                    check = 1;
                }
                else
                    currentPosition++;
            }

            if(check == 0)
            {
                check = currentPosition - index;
                while(check-- != 0)
                {
                    for(index_2 = index; str[index_2] != '\0'; index_2++)
                    {
                        str[index_2] = str[index_2 + 1];
                    }
                    //str[index_2]
                }
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    char string[] = "AAABBBaBaCCBacCC";
    del_substr(string, "BBa");
    del_substr(string, "AAA");
    del_substr(string, "CC");
    del_substr(string, "CC");
    del_substr(string, "BBa");
    del_substr(string, "a");
    del_substr(string, "c");

    printf("%s", string);

    return 0;
}
