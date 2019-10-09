#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return (a < b)? a : b;
}

char* pref(char *word_1, char *word_2) {
    int i;
    int len_1 = strlen(word_1);
    int len_2 = strlen(word_2);

    for (i = 0; i < min(len_1, len_2); i++) {
        if (word_1[i] != word_2[i]) {
            break;
        }
    }
    if (i == -1)
        return NULL;
    char *result = (char *)malloc(sizeof(i + 1));
    strncpy(result, word_1, i);
    result[i] = '\0';
    return result;
}

char* prefix(char **words, int start, int end) {
    if (start == end) {
        return words[start];
    } else if (start < end) {
        int middle = start + (end - start) / 2;
        return pref(prefix(words, start, middle),
                    prefix(words, middle + 1, end));
    }
}

int main()
{
    FILE *input = fopen("date.in", "r");
    int n;
    char **words, *buffer;

    fscanf(input, "%d", &n);fgetc(input);
    buffer = (char *)malloc(sizeof(char) * 1000);
    words = (char **)malloc(sizeof(char *) * n);

    for (int i = 0; i < n; i++) {
        fscanf(input, "%s", buffer);
        words[i] = (char *)malloc(strlen(buffer) + 1);
        strcpy(words[i], buffer);
    }

    printf("The longest common prefix is: %s", prefix(words, 0, n - 1));

    for (int i = 0; i < n; i++) {
        free(words[i]);
    }

    free(words);
    free(buffer);
    fclose(input);
    return 0;
}
