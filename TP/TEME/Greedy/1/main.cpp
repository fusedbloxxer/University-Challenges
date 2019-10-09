#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "D:\GIT\University-Challenges\Tehnici de Programare\TEHNICI\TEME\Useful_Resources\utils.cpp"

using namespace std;

class activity {
private:
    int id, t, dl, freeTime;
public:
    int getTime() {
        return t;
    }
    int getDeadline() {
        return dl;
    }
    int getFreeTime() {
        return freeTime;
    }
    int getID() {
        return id;
    }
    void setProperties(int id, int t, int dl, int freeTime) {
        this->id = id;
        this->t = t;
        this->dl = dl;
        this->freeTime = freeTime;
    }
    void setProperties(int id, int t, int dl) {
        this->id = id;
        this->t = t;
        this->dl = dl;
        this->freeTime = freeTime;
    }
    activity(int id, int t, int dl, int freeTime) {
        this->id = id;
        this->t = t;
        this->dl = dl;
        this->freeTime = freeTime;
    }
    void printToScreen() {
        printf("ID:%d TI:%d DL:%d//", id, t, dl);
    }
};

int cmpDeadLine(void *a, void *b) {
    activity *al = (activity *)a;
    activity *bl = (activity *)b;

   if (al->getDeadline() - bl->getDeadline() < 0) {
        return -1;
   } else if (al->getDeadline() - bl->getDeadline() == 0) {
        return bl->getTime() - al->getTime();
   } else return 1;
}

int cmpFreeTime(void *a, void *b) {
    activity *al = (activity *)a;
    activity *bl = (activity *)b;

   return al->getFreeTime() - bl->getFreeTime();
}

int main()
{
    FILE *input = fopen("date.in", "r");
    FILE *output = fopen("date.out", "w");
    int nActivities, finishTime = 0, Pn = INT_MIN, previousTime = 0;

    fscanf(input, "%d", &nActivities);
    activity *array = (activity *)malloc(sizeof(activity) * nActivities);

    for (int i = 0; i < nActivities; i++) {
        int t, dl;
        fscanf(input, "%d %d", &t, &dl);
        array[i].setProperties(i, t, dl);
        finishTime += t;
    }

    /// Sortare crescatoare dupa deadline si descrescatoare(cand deadline-urile coincid) dupa timpul necesar efectuarii.
    mergeSort(array, nActivities, sizeof(activity), cmpDeadLine);

    for (int i = 0; i < nActivities; i++) {
        previousTime += array[i].getTime();
        int x = previousTime - array[i].getDeadline();
        if (x < 0) x = 0;
        if (Pn < x) {
            Pn = x;
        }
        array[i].printToScreen();
    }

    fprintf(output, "%d", Pn);

    free(array);
    fclose(input);
    fclose(output);
    return 0;
}
