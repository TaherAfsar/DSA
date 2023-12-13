#include <stdio.h>
#include <string.h>
struct Stack
{
    int top;
    char items[100];
};

void push(struct Stack *stack, char item)
{
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack)
{
    return stack->items[stack->top--];
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    struct Stack stack;
    stack.top = -1;

    int i, j = 0;
    char c, popped;

    for (i = 0; (c = infix[i]) != '\0'; i++)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            postfix[j++] = c;
        else if (c == '(')
            push(&stack, c);
        else if (c == ')')
        {
            while ((popped = pop(&stack)) != '(')
                postfix[j++] = popped;
        }
        else if (isOperator(c))
        {
            while (stack.top != -1 && precedence(stack.items[stack.top]) >= precedence(c))
                postfix[j++] = pop(&stack);
            push(&stack, c);
        }
    }

    while (stack.top != -1)
        postfix[j++] = pop(&stack);

    postfix[j] = '\0';
}

int main()
{
    char infix[100];
    char postfix[100];

    printf("Hardcoded infix expression: (a+b)*c-(d/e)\n");
    strcpy(infix, "(a+b)*c-(d/e)");

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
