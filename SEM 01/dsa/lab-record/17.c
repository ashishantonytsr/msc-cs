#include <stdio.h>

#define max 20
int visited[max], queue[max], front = -1, rear = -1;

int graph[20][20] = {
    {0, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0},
}, v = 7;


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
    bfs();
}