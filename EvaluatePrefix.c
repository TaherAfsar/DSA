#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
// Function to check if the character is an operand
bool isOperand(char c)
{
    // If the character is a digit then it must be an operand
    return isdigit(c);
}

// Function to evaluate a prefix expression
double evaluatePrefix(char exprsn[])
{
    int j = 0;
    // Create a stack to store operands
    double Stack[100];
    int top = -1;

    // Traverse the expression from right to left
    for (j = strlen(exprsn) - 1; j >= 0; j--)
    {
        // Push operand to Stack
        // To convert exprsn[j] to digit subtract '0' from exprsn[j]
        if (isOperand(exprsn[j]))
            Stack[++top] = exprsn[j] - '0';
        else
        {
            // Operator encountered
            // Pop two elements from Stack
            double o1 = Stack[top--];
            double o2 = Stack[top--];

            // Use switch case to operate on o1 and o2 and perform o1 Or o2
            switch (exprsn[j])
            {
            case '+':
                Stack[++top] = o1 + o2;
                break;
            case '-':
                Stack[++top] = o1 - o2;
                break;
            case '*':
                Stack[++top] = o1 * o2;
                break;
            case '/':
                Stack[++top] = o1 / o2;
                break;
            }
        }
    }

    // The final result will be at the top of the stack
    return Stack[top];
}

// Driver code
int main()
{
    char exprsn[] = "+9*26";
    printf("%lf\n", evaluatePrefix(exprsn));
    return 0;
}
