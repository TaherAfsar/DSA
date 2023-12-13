#include <stdio.h>

struct CircularQueue
{
    int arr[5];
    int front, rear;
};

void initializeQueue(struct CircularQueue *cq)
{
    cq->front = cq->rear = -1;
}

int isEmpty(struct CircularQueue *cq)
{
    return cq->front == -1;
}

int isFull(struct CircularQueue *cq)
{
    return (cq->rear + 1) % 5 == cq->front;
}

void enqueue(struct CircularQueue *cq, int data)
{
    if (isFull(cq))
    {
        printf("Queue is full. Cannot enqueue.\n");
    }
    else
    {
        cq->rear = (cq->rear + 1) % 5;
        cq->arr[cq->rear] = data;
        if (isEmpty(cq))
        {
            cq->front = cq->rear;
        }
        printf("%d enqueued to the queue.\n", data);
    }
}

void dequeue(struct CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else
    {
        printf("%d dequeued from the queue.\n", cq->arr[cq->front]);
        if (cq->front == cq->rear)
        {
            initializeQueue(cq);
        }
        else
        {
            cq->front = (cq->front + 1) % 5;
        }
    }
}

void display(struct CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        int i = cq->front;
        printf("Elements in the queue: ");
        do
        {
            printf("%d ", cq->arr[i]);
            i = (i + 1) % 5;
        } while (i != (cq->rear + 1) % 5);
        printf("\n");
    }
}

int main()
{
    struct CircularQueue cq;
    initializeQueue(&cq);

    enqueue(&cq, 1);
    enqueue(&cq, 2);
    enqueue(&cq, 3);

    display(&cq);

    dequeue(&cq);

    display(&cq);

    enqueue(&cq, 4);
    enqueue(&cq, 5);

    display(&cq);

    return 0;
}
