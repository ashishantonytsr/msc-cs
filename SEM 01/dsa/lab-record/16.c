#include <stdio.h>

int visited[20];
int graph[20][20] = {
    {0, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0},
}, v = 7;


void dfs(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < v; i++) {
        if (!visited[i] && graph[vertex][i])
            dfs(i);
    }
}

void main() {
    // initializing visited[] 
    for (int i = 0; i < v; i++)
        visited[i] = 0;

    // calling dfs from vertex 0
    dfs(0);
}