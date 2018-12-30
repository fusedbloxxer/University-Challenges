#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dollars(char *dest, char const *src)
{
    int N  = strlen(src);
    strcpy(dest, "$");

    switch(N)
    {
    case 0:
    {
        strcat(dest, "0.00");
    }
    break;
    case 1:
    {
        strcat(dest, "0.0");
        strcat(dest, src);
    }
    break;
    case 2:
    {
        strcat(dest, "0.");
        strcat(dest, src);
    }
    break;
    default:
    {
        int index = 0;
        while(index < N)
        {
            int rest = (N - index  - 3) % 3;
            int U = strlen(dest);
            dest[U] = src[index];
            dest[U + 1] = '\0';

            if(rest == 0 && (N - index - 3) != 0)
            {
                strcat(dest, ",");
            }
            else if(N - index -1 == 2)
            {
                strcat(dest, ".");
            }

            index++;
        }
    }
    break;
    }
}
int main()
{
    char *string = (char *)malloc(1000 * sizeof(char));

    while(string[0] != "")
    {
        char *dest;
        printf("ENTER PRICE: ");
        scanf("%s", string);
        dest = (char *)malloc(strlen(string) * sizeof(char) + 1 + strlen(string) / 2);
        dollars(dest, string);

        printf("%s\n", dest);
        free(dest);
    }
    return 0;
}
