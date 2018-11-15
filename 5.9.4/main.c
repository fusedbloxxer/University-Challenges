#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_bit( char bit_array[], unsigned bit_number )
{
    bit_array[strlen(bit_array)-bit_number-1]='1';
}
void clear_bit( char bit_array[], unsigned bit_number )
{
    bit_array[strlen(bit_array)-bit_number-1]='0';
}
void assign_bit( char bit_array[], unsigned bit_number, int value )
{
    if(value==0)
    clear_bit(bit_array,bit_number);
    else
        set_bit(bit_array,bit_number);
}
int test_bit( char bit_array[],unsigned bit_number )
{
    if(bit_array[strlen(bit_array)-bit_number-1]!='0')return 1;
    return 0;
}

int main()
{
    char Number[]="00000000000000011000101110010010";

    set_bit(Number,13);
    clear_bit(Number,15);
    clear_bit(Number,16);
    set_bit(Number,17);

    printf("%s",Number);
    return 0;
}
