#include <stdio.h>
#include <stdlib.h>

void maxValue(int *array, int n, int *max)
{
    if(n != -1)
    {
        if(*max < array[n])
            *max = array[n];

        maxValue(array, n - 1, max);
    } else {
        printf("max = %d", *max);
    }
}

int main()
{
    int arr_3[] = {5, 1, 2, 4, 3, 1, 8};
    int max = arr_3[6];
    maxValue(arr_3, 5, &max);


    return 0;
}
