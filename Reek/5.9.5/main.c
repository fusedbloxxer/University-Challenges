#include <stdio.h>
#include <stdlib.h>

int store_bit_field( int original_value, int value_to_stor, unsigned starting_bit, unsigned ending_bit )
{
    if(starting_bit>=ending_bit)
    {
        int Mask=~(((1<<(starting_bit-ending_bit+1))-1)<<(ending_bit-1));
        original_value=original_value&Mask;
        original_value=original_value|(value_to_stor<<(ending_bit-1));

        printf("%d",original_value);
        return 0;
    }
    else return -1;
}

int main()
{
    int x,y;

    printf("Original value=");
    scanf("%x",&x);

    printf("Value to store=");
    scanf("%x",&y);

    store_bit_field(x,y,5,3);

    return 0;
}
