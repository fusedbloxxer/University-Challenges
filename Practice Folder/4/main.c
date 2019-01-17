#include <stdio.h>
#include <stdlib.h>
struct rar
{
    int l, c, x;
};
void readRare(const char *file_name, int *N, int *M, int *len, struct rar **head)
{
    FILE* input = fopen(file_name, "r");
    int l, x, c;
    fscanf(input, "%d", N);
    fscanf(input, "%d", M);
    fscanf(input, "%d %d %d", &l, &c, &x);
    *head = (struct rar*)malloc(sizeof(struct rar));
    *len = 1;
    (*head)->c = c;
    (*head)->x = x;
    (*head)->l = l;
    while(fscanf(input, "%d %d %d", &l, &c, &x) != -1)
    {
        *len += 1;
        *head = realloc(*head, *len * sizeof(struct rar));
        (*head + *len - 1)->c = c;
        (*head + *len - 1)->x = x;
        (*head + *len - 1)->l = l;
    }
    fclose(input);
}
void printRare(struct rar *head, int len, int N, int M){
    int i, j, index = 0;
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            if(head[index].c == j && head[index].l == i) {
                printf("%d ", head[index].x);
                index++;
            } else printf("0 ");
        }
        printf("\n");
    }
}
void sumRare(struct rar *m1, struct rar* m2, int len1, int len2, int N, int M) {
    int i = 0, j = 0;
    struct rar *result = (struct rar *)calloc((len1>len2)?len1:len2, sizeof(struct rar));
    while(i < len1 && j < len2) {
        if(m1[i].l < m2[j].l) {
            if(m1[i].c < m2[i].c) {

            }
        }
    }
}
int main()
{
    int N, M, len;
    struct rar *head;
    readRare("date.in", &N, &M, &len, &head);
    printRare(head, len, N, M);
    return 0;
}
