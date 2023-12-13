#include <stdio.h>
#define MAX_SIZE 100

// Structure to represent the stack
struct Stack
{
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack->arr[++stack->top] = value;
        printf("%d pushed to the stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1; // Return a sentinel value to indicate underflow
    }
    else
    {
        return stack->arr[stack->top--];
    }
}

// Function to peek at the top element of the stack without popping
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1; // Return a sentinel value to indicate empty stack
    }
    else
    {
        return stack->arr[stack->top];
    }
}

// Function to display the elements of the stack
void display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; ++i)
        {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

// Main function to demonstrate the stack operations
int main()
{
    struct Stack myStack;
    initialize(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    display(&myStack);

    printf("Top element: %d\n", peek(&myStack));

    printf("Popped element: %d\n", pop(&myStack));

    display(&myStack);

    return 0;
}
