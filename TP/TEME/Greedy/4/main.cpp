#include <iostream>
#include <fstream>
#include "D:\GIT\University-Challenges\Tehnici de Programare\TEHNICI\TEME\Useful_Resources\utils.cpp"

using namespace std;

class interval
{
private:
    int a, b;
public:
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    void setAB(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void setA(int a)
    {
        this->a = a;
    }
    void setB(int b)
    {
        this->b = b;
    }
    void printToString()
    {
        printf("[%d, %d] ", a, b);
    }
    void printToString(FILE *output) {
        fprintf(output, "[%d, %d] ", a, b);
    }
    int getDuration()
    {
        return b - a;
    }
    interval()
    {
    }
    interval(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
};

int cmpDuration(void *a, void *b)
{
    interval *al = (interval *)a;
    interval *bl = (interval *)b;

    return -al->getDuration()+bl->getDuration();
}

int cmpA(void *a, void *b)
{
    interval *al = (interval *)a;
    interval *bl = (interval *)b;

    /// Sort ascending by A
    if (al->getA() - bl->getA() < 0)
    {
        return -1;
    }
    else if (al->getA() - bl->getA() == 0)
    {
        /// Sort descending by B
        return bl->getB() - al->getB();
    }
    else
        return 1;
}

int sortByEnd(void *a, void *b)
{
    interval *al = (interval *)a;
    interval *bl = (interval *)b;

    return al->getB() - bl->getB();
}

int main()
{
    FILE *input = fopen("acoperire.in", "r");
    FILE *output = fopen("acoperire.out", "w");
    int a, b, nIntervals, length = 0, comparator;
    interval *bigInterval, *array, *result = NULL;

    fscanf(input, "%d%d%d", &a, &b, &nIntervals);
    bigInterval = new interval(a, b);
    array = new interval[nIntervals];

    for (int i = 0; i < nIntervals; i++)
    {
        fscanf(input, "%d%d", &a, &b);
        array[i].setAB(a, b);
    }

    mergeSort(array, nIntervals, sizeof(interval), cmpA);

    printf("The intervals in sorted order are: \n");
    for (int i = 0; i < nIntervals; i++)
    {
        array[i].printToString();
    }
    printf("\n");

    for (int i = 0; i < nIntervals; i++)
    {
        if (array[i].getA() > bigInterval->getB()) {
            break;
        }
        if (array[i].getA() <= bigInterval->getA() && array[i].getB() >= bigInterval->getA())
        {
            if (length >= 1)
            {
                if (array[i].getB() > result[0].getB())
                {
                    result[0] = array[i];
                    comparator = 0;
                }
            }
            else
            {
                result = (interval *)realloc(result, sizeof(interval) * 1);
                result[length = 0] = array[i];
                comparator = 0;
                length++;
            }

        }
        else if (array[i].getA() >= bigInterval->getA() && array[i].getA() <= bigInterval->getB())
        {
            if (length == 0) {
                goto FAIL;
            }
            /// Am pus un >= aici in loc de >
            if (array[i].getB() >= result[length - 1].getB())
            {
                if (array[i].getA() <= result[comparator].getB())
                {
                    result = (interval *)realloc(result, sizeof(interval) * (comparator + 2));
                    length = comparator + 2;
                    result[length - 1] = array[i];
                }
                else
                {
                    comparator++;
                    if (array[i].getA() <= result[comparator].getB())
                    {
                        result = (interval *)realloc(result, sizeof(interval) * ++length);
                        result[length - 1] = array[i];
                    }
                    else
                    {
                        goto FAIL;
                    }
                }

            }
        }
        if (length >0 && result[length - 1].getB() >= bigInterval->getB()) {
            break;
        }
    }

    if (length == 0)
    {
        goto FAIL;
    }
    else
    {
        if (result[length - 1].getB() < bigInterval->getB())
        {
            goto FAIL;
        }
        else
        {

            printf("\nCardinal %d, the intervals are : \n", length);
            for (int i = 0; i < length; i++)
            {
                result[i].printToString(output);
            }
        }
    }

    delete[] array;
    delete bigInterval;
    fclose(input);
    fclose(output);
    return 0;

FAIL:
    delete[] array;
    delete bigInterval;
    fclose(input);
    fclose(output);
    return -1;
}
