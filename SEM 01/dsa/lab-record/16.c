#include <stdio.h>

#define max 20
int visited[max], stack[max], top = -1;

int graph[20][20] = {
    {0, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0},
}, v = 7;


void push(int value) {
    if (top >= max) return;

    // check whether the value already exists
    for (int i = top; i >= 0; i--) {
        if (stack[i] == value)
            return;
    }
    stack[++top] = value;
}

int pop() {
    if (top > -1)
        return stack[top--];
}

void dfs() {
    // initializing visited[]
    for (int i = 0; i < v; i++)
        visited[i] = 0;

    for (int i = 0; i < v;) {
        printf("%d ", i);

        visited[i] = 1;
        for (int j = v - 1; j >= 0; j--) {

            // unvisited edge
            if (!visited[j] && graph[i][j])
                push(j);
        }

        // exit if stack is empty
        if (top == -1) break;
        i = pop();
    }

}

void main() {
    dfs();
}



/* DFS using Recursion
---

void dfs(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    // check all neighbors of `vertex`
    for (int i = 0; i < v; i++) {

        // unvisited edge
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
*/