#include <stdlib.h>
#include <string.h>

void mergeAlg(void *array, int start, int middle, int nElem, int sizeElem, int (*cmp)(void *, void *)) {
    int n1 = middle - start + 1;
    int n2 = nElem - middle;

    char *leftArray = (char *)malloc(n1 * sizeElem);
    char *rightArray = (char *)malloc(n2 * sizeElem);

    memcpy(leftArray, (char *)array + start * sizeElem, n1 * sizeElem);
    memcpy(rightArray, (char *)array + (middle + 1) * sizeElem, n2 * sizeElem);

    int k = start;
    int i1 = 0, i2 = 0;

    while (i1 < n1 && i2 < n2) {
        if (cmp(leftArray + i1 * sizeElem, rightArray + i2 * sizeElem) < 0) {
            memcpy((char *)array + k * sizeElem, leftArray + i1 * sizeElem, sizeElem);
            i1++;
        } else {
            memcpy((char *)array + k * sizeElem, rightArray + i2 *sizeElem, sizeElem);
            i2++;
        }
        k++;
    }

    while (i1 < n1) {
        memcpy((char *)array + k * sizeElem, leftArray + i1 * sizeElem, sizeElem);
        i1++;
        k++;
    }

    while (i2 < n2) {
        memcpy((char *)array + k * sizeElem, rightArray + i2 *sizeElem, sizeElem);
        i2++;
        k++;
    }

    free(leftArray);
    free(rightArray);
}

void divideEtImpera(void *array, int start, int nElem, int sizeElem, int (*cmp)(void *, void *)) {
    if (start < nElem) {
        int middle = start + (nElem - start) / 2;

        divideEtImpera(array, start, middle, sizeElem, cmp);
        divideEtImpera(array, middle + 1, nElem, sizeElem, cmp);
        mergeAlg(array, start, middle, nElem, sizeElem, cmp);
    }
}

void mergeSort(void *array, int nElem, int sizeElem, int (*cmp)(void *, void *)) {
    divideEtImpera(array, 0, nElem - 1, sizeElem, cmp);
}
