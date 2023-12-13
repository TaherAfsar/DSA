#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue
{
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initializeQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q)
{
    return q->rear == -1;
}

void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX_SIZE - 1)
    {
        printf("Queue is full!\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue *q)
{
    int item = -1;
    if (!isEmpty(q))
    {
        item = q->items[q->front++];
        if (q->front > q->rear)
        {
            initializeQueue(q);
        }
    }
    return item;
}

void bfs(int adjMatrix[MAX_SIZE][MAX_SIZE], int n, int startVertex)
{
    int visited[MAX_SIZE] = {0};
    struct Queue q;
    initializeQueue(&q);

    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    printf("BFS traversal starting from vertex %d: ", startVertex);

    while (!isEmpty(&q))
    {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }

    printf("\n");
}
int main()
{
    int n = 6; // Number of vertices
    int adjMatrix[MAX_SIZE][MAX_SIZE] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 1, 0, 1, 0}};

    int startVertex = 0; // Starting vertex for BFS

    bfs(adjMatrix, n, startVertex);

    return 0;
}
