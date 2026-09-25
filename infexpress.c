#include <stdio.h>
#include <ctype.h>

#define MAX 100

// Stack for evaluation
int stack[MAX];
int top = -1;

// Array to store variable values
int variables[26];

// Push value
void push(int value)
{
    stack[++top] = value;
}

// Pop value
int pop()
{
    return stack[top--];
}

// Check whether character is operand
int isOperand(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'));
}

// Check whether character is operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/' ||
            ch == '^');
}

// Power function
int power(int base, int exp)
{
    int result = 1;

    while(exp > 0)
    {
        result *= base;
        exp--;
    }

    return result;
}

// Get value of operand
int getValue(char ch)
{
    if(ch >= 'A' && ch <= 'Z')
        return variables[ch - 'A'];

    if(ch >= 'a' && ch <= 'z')
        return variables[ch - 'a'];

    return ch - '0';
}

// Evaluate Postfix Expression
int evaluatePostfix(char postfix[])
{
    int i;
    char ch;

    top = -1;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if(isOperand(ch))
        {
            push(getValue(ch));
        }
        else if(isOperator(ch))
        {
            int a = pop();
            int b = pop();

            switch(ch)
            {
                case '+':
                    push(b + a);
                    break;

                case '-':
                    push(b - a);
                    break;

                case '*':
                    push(b * a);
                    break;

                case '/':
                    push(b / a);
                    break;

                case '^':
                    push(power(b, a));
                    break;
            }
        }
    }

    return pop();
}

int main()
{
    char postfix[MAX];
    int n, i, value;
    char var;

    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    printf("Enter number of variables: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter variable and value (Example A 10): ");
        scanf(" %c %d", &var, &value);

        if(var >= 'A' && var <= 'Z')
            variables[var - 'A'] = value;
        else if(var >= 'a' && var <= 'z')
            variables[var - 'a'] = value;
    }

    printf("\nResult = %d\n", evaluatePostfix(postfix));

    return 0;
}

