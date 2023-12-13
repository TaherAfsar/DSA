#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent a queue
struct Queue
{
    int front, rear;
    int array[MAX_SIZE];
};

// Function to initialize a queue
void initializeQueue(struct Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(struct Queue *queue)
{
    return (queue->rear == MAX_SIZE - 1);
}

// Function to add an element to the queue
void enqueue(struct Queue *queue, int data)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue))
    {
        queue->front = 0;
    }

    queue->rear++;
    queue->array[queue->rear] = data;
    printf("%d enqueued to the queue.\n", data);
}

// Function to remove an element from the queue
void dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("%d dequeued from the queue.\n", queue->array[queue->front]);

    if (queue->front == queue->rear)
    {
        // Last element is dequeued, reset front and rear
        initializeQueue(queue);
    }
    else
    {
        // Move front to the next element
        queue->front++;
    }
}

// Function to display the elements of the queue
void displayQueue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the queue: ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    displayQueue(&queue);

    dequeue(&queue);
    displayQueue(&queue);

    return 0;
}
