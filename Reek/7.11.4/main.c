#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void written_amount(unsigned int amount, char *buffer)
{
    strcpy(buffer, "");
    if(amount == 0)
    {
        // printf("ZERO");
        strcpy(buffer, "ZERO");
        return ;
    }
    char string[20], length, index = 0, diff, rest, finalCheck;
    char words[50][20] =
    {
        "ONE", "TWO", "THREE", "FOUR",
        "FIVE", "SIX", "SEVEN", "EIGHT",
        "NINE", "TEN", "ELEVEN", "TWELVE",
        "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN",
        "SEVENTEEN", "EIGHTEEN", "NINETEEN", "TWENTY",
        "THIRTY", "FOURTY", "FIFTY", "SIXTY",
        "SEVENTY", "EIGHTY", "NINETY", "HUNDRED",
        "THOUSAND", "MILLION", "BILLION"
    };
    sprintf(string, "%d", amount);
    length = strlen(string);
    while(index < length)
    {
        finalCheck = 0;
        rest = (length - index - 1) % 3;
        diff = (length - index - 1) / 3;

        while(rest >= 0)
        {
            switch(rest)
            {
            case 0:
            {
                if(string[index] != '0')
                {
                    // printf("%s ", words[string[index] - '0' - 1]);
                    strcat(buffer, words[string[index] - '0' - 1]);
                    strcat(buffer, " ");
                    finalCheck = 1;
                }
                rest--;
                index++;
            }
            break;
            case 1:
            {
                if(string[index] == '1')
                {
                    // printf("%s ", words[(string[index] - '0') * 10 + string[index + 1] - '0' - 1]);
                    strcat(buffer, words[(string[index] - '0') * 10 + string[index + 1] - '0' - 1]);
                    strcat(buffer, " ");
                    index += 2;
                    rest  -= 2;
                    finalCheck = 1;
                }
                else
                {
                    if(string[index] != '0')
                    {
                        // printf("%s ", words[17 + string[index] - '0']);
                        strcat(buffer, words[17 + string[index] - '0']);
                        strcat(buffer, " ");
                        finalCheck = 1;
                    }
                    index++;
                    rest--;
                }
            }
            break;
            case 2:
            {
                if(string[index] != '0')
                {
                    // printf("%s HUNDRED ", words[string[index] - '0' - 1]);
                    strcat(buffer, words[string[index] - '0' - 1]);
                    strcat(buffer, " HUNDRED ");
                    finalCheck = 1;
                }
                index++;
                rest--;
            }
            break;
            default:
                rest = -1;
                break;
            }
        }

        switch(diff)
        {
        case 1:
        {
            if(finalCheck == 1)
            {
                // printf("THOUSAND ");
                strcat(buffer, "THOUSAND ");
            }

        }
        break;
        case 2:
        {
            if(finalCheck == 1)
            {
                // printf("THOUSAND ");
                strcat(buffer, "MILLION ");
            }
        }
        break;
        case 3:
        {
            if(finalCheck == 1)
            {
                // printf("THOUSAND ");
                strcat(buffer, "BILLION ");
            }
        }
        break;
        case 4:
        {
            if(finalCheck == 1)
            {
                // printf("THOUSAND ");
                strcat(buffer, "TRILLION ");
            }
        }
        break;
        }
    }
}
int main()
{
    char *buffer = (char *)malloc(1000 * sizeof(char));
    int x = 1;
    while(x != 0)
    {
        printf("Enter number: ");
        fscanf(stdin, "%d", &x);
        int index;
        for(index = 0; index <= x; index++)
        {
            written_amount(index, buffer);
            printf("%s\n", buffer);
        }
    }
    return 0;
}
