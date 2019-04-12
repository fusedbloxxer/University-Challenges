#include <stdio.h>
#include <stdlib.h>

void repeat(int *array, int n) {
    int freq[2][] = calloc(1, sizeof(int));
    int upperBound = (int)(n/2) + 1;

    for(int i = 0; i < n; i++) {
        if(++freq[i] == upperBound)
            return i;
    }

}

int main()
{

    return 0;
}
