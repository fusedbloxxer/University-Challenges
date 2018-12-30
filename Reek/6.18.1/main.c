#include <stdio.h>
#include <stdlib.h>

//Functioneaza
char *find_char( char const *source, char const *chars )
{
    char *in, *in2;
    for(in = source; *in != '\0'; in = in + 1)
        for(in2 = chars; *in2 != '\0'; in2 = in2 + 1)
        {
            if(*in == *in2)
                return in;
        }
    return NULL;
}
int main()
{
    char string[] = "AAABBBCCCd";
    printf("%s", find_char(string, "zdrC"));

    return 0;
}
