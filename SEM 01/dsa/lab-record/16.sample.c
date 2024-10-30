#include <stdio.h>

int visited[20], stack[20], top = -1;

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
    if (top >= 20)
        return;

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
        for (int j = 0; j < v; j++) {

            // unvisited edge
            if (!visited[j] && graph[i][j])
                push(j);
        }
        if (top == -1) break;
        i = pop();
    }

}

void main() {
    dfs();
}