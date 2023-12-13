#include <stdio.h>

// Structure to represent a stack
typedef struct
{
    int top;
    char array[100];
} Stack;

// Function to initialize the stack
void initialize(Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to push a character to the stack
void push(Stack *stack, char item)
{
    stack->array[++stack->top] = item;
}

// Function to pop a character from the stack
char pop(Stack *stack)
{
    return isEmpty(stack) ? '\0' : stack->array[stack->top--];
}

// Function to check if parentheses are balanced
int areParenthesesBalanced(char exp[])
{
    Stack stack;
    initialize(&stack);

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(&stack, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            char topChar = pop(&stack);

            if ((exp[i] == ')' && topChar != '(') ||
                (exp[i] == '}' && topChar != '{') ||
                (exp[i] == ']' && topChar != '['))
                return 0;
        }
    }

    return isEmpty(&stack) ? 1 : 0;
}

// Driver program with hard-coded input to test the Parenthesis Checker
int main()
{
    char expression[] = "{[()]}"; // Change the expression as needed

    if (areParenthesesBalanced(expression))
        printf("Parentheses are balanced.\n");
    else
        printf("Parentheses are not balanced.\n");

    return 0;
}
