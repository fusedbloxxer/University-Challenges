#include <stdio.h>
#include <stdlib.h>

int **graph, v1, v2, nodes;
int  *path;

void printPath(int length) {
    for (int i = 0; i <= length; i++) {
        if (i != length) {
            printf("%d->", path[i]);
        } else {
            printf("%d", path[i]);
        }
    }
    printf("\n");
}

void depth_first(int v, int length) {
    path[length] = v;
    if (v == v2) {
        printPath(length);
        return;
    }
    for (int i = 1; i < graph[v][0]; i++) {
        int check = 0;
        for (int j = 0; j <= length; j++) {
            if (path[j] == graph[v][i]) {
                check = 1;
                break;
            }
        }

        if (check == 0) {
            depth_first(graph[v][i], length + 1);
        }
    }
}

void showGraph() {
    for(int i = 0; i < nodes; i++) {
        printf("%d: ", i);
        for (int j = 1; j < graph[i][0]; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    FILE *input = fopen("graf.txt", "r");
    fscanf(input, "%d", &nodes);
    fscanf(input, "%d %d", &v1, &v2);

    path  = (int *)malloc(sizeof(int) * (nodes - 1));
    graph = (int **)calloc(nodes, sizeof(int *));
    for (int i = 0; i < nodes; i++) {
        graph[i] = (int *)malloc(sizeof(int));
        graph[i][0] = 1;
    }

    int x, y;
    while (fscanf(input, "%d %d", &x, &y) != -1) {
        graph[x] = (int *)realloc(graph[x], sizeof(int) * ++graph[x][0]);
        graph[y] = (int *)realloc(graph[y], sizeof(int) * ++graph[y][0]);

        graph[x][graph[x][0] - 1] = y;
        graph[y][graph[y][0] - 1] = x;
    }

    showGraph();
    depth_first(v1, 0);

    for (int i = 0; i < nodes; i++) {
        free(graph[i]);
    }
    free(path);
    free(graph);
    fclose(input);
    return 0;
}
