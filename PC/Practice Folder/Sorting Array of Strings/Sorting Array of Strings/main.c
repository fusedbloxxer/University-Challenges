#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(a, b) * -1;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int common = strspn(a, b);
    int len_1 = strlen(a) - common,
        len_2 = strlen(b) - common;
    if(len_1 == len_2) {
        return lexicographic_sort(a, b);
    }

    return len_1 - len_2;

}

int sort_by_length(const char* a, const char* b) {
    int len_1 = strlen(a),
        len_2 = strlen(b);
    if(len_1 == len_2) {
        return lexicographic_sort(a, b);
    }

    return len_1 - len_2;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 0; i < len - 1; i++) {
        for(int j = i + 1; j < len; j++) {
            if(cmp_func(arr[i], arr[j]) > 0) {
                char *string = (char *)malloc(1024 * sizeof(char));
                strcpy(string, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], string);
                free(string);
            }
        }
    }
}


int main()
{
    FILE *file = fopen("date.txt", "r");
    FILE *output = fopen("output.txt", "w");
    int n;
    fscanf(file, "%d", &n);

    char** arr;
	arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        fscanf(file, "%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        fprintf(output, "%s\n", arr[i]);
    fprintf(output, "\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        fprintf(output, "%s\n", arr[i]);
    fprintf(output, "\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        fprintf(output, "%s\n", arr[i]);
    fprintf(output, "\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        fprintf(output, "%s\n", arr[i]);
    fprintf(output, "\n");

    fclose(file);
    fclose(output);
}
