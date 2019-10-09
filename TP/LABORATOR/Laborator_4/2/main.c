#include <stdio.h>
#include <stdlib.h>

int diff(int *arr, int n) {
    if(n - 1 >= 0) {
        if((n - 1) % 2 == 0)
            return arr[n - 1] + diff(arr, n - 1);
        else return diff(arr, n - 1) - arr[n - 1];
    } else return 0;
}

int main()
{
    int arr[] = {4, 5, 6, 3, 2, 0};
    printf("%d", diff(arr, 6));

    return 0;
}
