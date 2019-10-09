#include <stdio.h>
#include <stdlib.h>
unsigned char* The_Sieve_of_Eratosthenes_BITS(unsigned long sup)
{
    unsigned char* array = (unsigned char *)malloc(sup / 16 * sizeof(unsigned char*));
    printf("%d bytes allocated for %d elements.", sup / 16, sup);
    memset(array, 255, sup / 16); // set each byte to 11111111

    unsigned long byteIndex, bitIndex;
    if(sup >= 2)
        printf("\n2 ");
    for(byteIndex = 0; byteIndex < sup / 16; byteIndex++)
    {
        for(bitIndex = 0; bitIndex < 8; bitIndex++)
        {
            if((array[byteIndex] & 1 << bitIndex) != 0)
            {
                int currentPosition   = 8 * byteIndex + bitIndex;
                unsigned long index_2 = 3 * (currentPosition + 1);
                while(index_2 <= sup)
                {
                    if((array[index_2 / 8] & (1 << (index_2 % 8))) != 0)
                    {
                        array[index_2 / 8] = array[index_2 / 8] ^ (1 << (index_2 % 8));
                    }
                    index_2 += currentPosition * 2 + 3;
                }

                printf("%d ", currentPosition * 2 + 3);
            }
        }

    }
    return array;
}
int main()
{
    unsigned long byteIndex, N = 10100, bitIndex, count = 0, interval = 1000;
    unsigned char *array = The_Sieve_of_Eratosthenes_BITS(N);

    if(N >= 2) count++;
    for(byteIndex = 0; byteIndex < N; byteIndex++)
    {
        for(bitIndex = 0; bitIndex < 8; bitIndex++)
        {
            unsigned long currentPosition = (8 * byteIndex + bitIndex) * 2 + 3;
            if((array[byteIndex] & (1 << bitIndex)) != 0)
            {
                if(currentPosition<= N)
                {
                    if(currentPosition > interval)
                    {
                        printf("\n%d-%d: %d", interval - 1000, interval, count);
                        interval += 1000;
                        count = 0;
                    }
                    count++;
                }
                else
                    goto end;
            }
        }
    }
    end:
    return 0;
}
