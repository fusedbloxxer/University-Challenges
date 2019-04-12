#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    FILE *input = fopen("date.in", "r");
    int N, M, *sequence = NULL, currentSum = 0, maxSum = INT_MIN, nOfElements = 0;
    int mLeftIndex = 0, mRightIndex = 0, leftIndex = 0;

    scanf("%d", &M);
    fscanf(input, "%d", &N);
    sequence = (int *)malloc(sizeof(int) * N);


    for (int i = 0; i < N; i++) {
        fscanf(input, "%d", &sequence[i]);

        currentSum += sequence[i];

        if (maxSum < currentSum && currentSum <= M) {
            maxSum = currentSum;
            mLeftIndex = leftIndex;
            mRightIndex = i;
        }

        if (currentSum < 0) {

        }
    }



    /// TO DO : Afisare

    free(sequence);
    fclose(input);
    return 0;
}
