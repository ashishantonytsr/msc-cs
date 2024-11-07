#include <stdio.h>
#include <stdlib.h>

#define max 20
int graph[20][20], v;
int visited[max], stack[max], top = -1;



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
    int choice, s, t;

    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    // initialize every element in graph as 0
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            graph[i][j] = 0;

    while (1) {
        printf("\n\t1. Add edge\t2. Remove edge\t3. View Graph\t4. DFS\t5. Exit\n-> ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter two vertices to create an edge: ");
            scanf("%d %d", &s, &t);
            graph[s][t] = graph[t][s] = 1;
            break;
        case 2:
            printf("Enter two vertices to remove an edge: ");
            scanf("%d %d", &s, &t);
            graph[s][t] = graph[t][s] = 0;
            break;
        case 3:
            printf("The adjacency matrix:\n");
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++)
                    printf("%d ", graph[i][j]);
                printf("\n");
            }
            break;
        case 4:
            printf("The DFS Sequence: ");
            dfs(0);
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
}



/* DFS using Recursion
---

void dfs(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    // check all neighbors of `vertex`
    for (int i = v-1; i >=0; i--) {

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