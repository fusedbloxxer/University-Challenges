#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if(a < b) return a;
    return b;
}

int maxArray(int *arr, int n, int m) {
    if((n - 1) >= 0) {
        if (m < arr[n - 1])
            return maxArray(arr, n - 1, arr[n - 1]);
        return maxArray(arr, n - 1, m);
    } return m;
}

int main()
{
    int arr[] = {4, 5, 6, 3, 2, 8};
    printf("%d", maxArray(arr, 6, arr[5]));
    return 0;
}
