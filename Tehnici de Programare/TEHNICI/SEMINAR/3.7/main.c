#include <stdio.h>
#include <stdlib.h>

void printBits(void *array, int byte_size, int num_elem)
{
    for (int i = 0; i < num_elem; i++)
    {
        unsigned char *p = (unsigned char *)array + i * byte_size;
        for (int k = byte_size - 1; k >= 0; k--)
        {
            for (int j = 7; j >= 0; j--)
            {
                printf("%d", ((*(p + k) & (1 << j)) != 0)?1:0);
            }
            printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    FILE *input = fopen("date.in", "r");
    FILE *output = fopen("date.out", "w");

    int n, k;
    unsigned char * bits;
    unsigned short int *array = NULL, length = 0;
    fscanf(input, "%d %d", &n, &k);
    bits = calloc(n / 8 + 1, sizeof(unsigned char));


    for (int i = 0; i <= n - k; i++)
    {
        int currentElement;
        fscanf(input, "%d", &currentElement);
        if (currentElement < 0 || (bits[i / 8] & (1 << (i % 8))) != 0)
        {
            if (currentElement < 0)
                bits[i / 8] = bits[i / 8] ^ (1 << (i % 8));

            if ((bits[i / 8] & (1 << (i % 8))) != 0)
            {
                array = realloc(array, sizeof(unsigned short int) * ++length);
                array[length - 1] = i;

                for (int j = i; j < i + k; j++)
                {
                    bits[j / 8] = bits[j / 8] ^ (1 << (j % 8));
                }
            }
        }
    }


    for (int i = n - k + 1; i < n; i++)
    {
        int currentElement;
        fscanf(input, "%d", &currentElement);

        if (currentElement < 0)
        {
            bits[i / 8] = bits[i / 8] ^ (1 << (i % 8));
        }

        if ((bits[i / 8] & (1 << (i % 8))) != 0)
        {
            fprintf(output, "Nu se poate !");
            return ;
        }

    }

    for (int i = 0; i < length; i++)
    {
        fprintf(output, "%d ", array[i]);
    }

    free(bits);
    fclose(input);
    fclose(output);
    return 0;
}
