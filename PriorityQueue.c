#include <stdio.h>
#include <stdlib.h>

// Node structure for the priority queue
typedef struct Node
{
    int data;
    int priority;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data, int priority)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the priority queue based on priority
void enqueue(Node **front, int data, int priority)
{
    Node *newNode = createNode(data, priority);
    if (*front == NULL || priority < (*front)->priority)
    {
        newNode->next = *front;
        *front = newNode;
    }
    else
    {
        Node *temp = *front;
        while (temp->next != NULL && temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to remove and return the highest priority element from the queue
int dequeue(Node **front)
{
    if (*front == NULL)
    {
        printf("Priority Queue is empty\n");
        exit(1);
    }
    int data = (*front)->data;
    Node *temp = *front;
    *front = (*front)->next;
    free(temp);
    return data;
}

// Function to check if the priority queue is empty
int isEmpty(Node *front)
{
    return (front == NULL);
}

// Function to display the elements of the priority queue
void display(Node *front)
{
    if (front == NULL)
    {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Priority Queue: ");
    while (front != NULL)
    {
        printf("(%d, %d) ", front->data, front->priority);
        front = front->next;
    }
    printf("\n");
}

// Main function
int main()
{
    Node *front = NULL;

    // Example usage
    enqueue(&front, 10, 2);
    enqueue(&front, 20, 1);
    enqueue(&front, 30, 3);

    display(front);

    printf("Dequeued element: %d\n", dequeue(&front));

    display(front);

    return 0;
}
