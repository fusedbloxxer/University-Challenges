#include <stdio.h>
#include <stdlib.h>
void decrypt(char *data, char const *key) {

    int index, index_2;
    int N1, N2;

    N1 = strlen(data);
    N2 = strlen(key);

    for(index = 0; index < N1; index++)
    {
        for(index_2 = 0; index_2 < N2; index_2++)
        {
            if(data[index] == key[index_2])
            {
                data[index] = 'A' + index_2;
                break;
            } else if(data[index] == (key[index_2] + 32)) {
                data[index] = 'a' + index_2;
                break;
            }
        }
    }
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
