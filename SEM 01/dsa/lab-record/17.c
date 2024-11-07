#include <stdio.h>
#include <stdlib.h>

#define max 20
int graph[20][20], v;
int visited[max], queue[max], front = -1, rear = -1;


void enqueue(int value) {
    if (rear == max - 1) return;

    // check whether the value already exists
    for (int i = front; i <= rear; i++)
        if (queue[i] == value)
            return;

    if (rear == -1)
        front++;
    queue[++rear] = value;
}

int dequeue() {
    int value = queue[front++];
    if (front > rear)
        front = rear = -1;
    return value;
}

void bfs() {
    // initializing visited[]
    for (int i = 0; i < v; i++)
        visited[i] = 0;

    for (int i = 0; i < v;) {
        printf("%d ", i);

        visited[i] = 1;
        for (int j = 0; j < v; j++)

            // unvisited edge
            if (!visited[j] && graph[i][j])
                enqueue(j);

        // exit if queue is empty
        if (front == -1 || front > rear) break;

        i = dequeue();
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
        printf("\n\t1. Add edge\t2. Remove edge\t3. View Graph\t4. BFS\t5. Exit\n-> ");
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
            printf("The BFS Sequence: ");
                bfs();
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
}