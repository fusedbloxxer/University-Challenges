#include <stdio.h>
#include <stdlib.h>

int roundP(char *sequence) {
    int left = 0, right = 0;
    for (int i = 0; sequence[i] != '\0'; i++) {
        if (sequence[i] == '(') {
            left++;
        } else if (sequence[i] == ')') {
            right++;
        }
    }

    if (left != right) return 0;
    return 1;
}

int srP(char *sequence) {
    int sleft = 0, sright = 0, rleft = 0, rright = 0;
    for (int i = 0; sequence[i] != '\0'; i++) {
        if (sequence[i] == '(') {
            rleft++;
        } else if (sequence[i] == ')') {
            rright++;
        } else if (sequence[i] == '[') {
            sleft++;
        } else if (sequence[i] == ']') {
            sright++;
        }
    }

    if ((sleft != sright) || (rleft != rright)) return 0;
    return 1;
}

int main()
{
    printf("%d", srP("(([)[()]))]"));

    return 0;
}
