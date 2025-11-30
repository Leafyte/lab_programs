//postfix evaluation
#include <stdio.h>
#include <ctype.h>
#include <math.h>

float stack[50];
int top = -1;

float operation(char op, float op1, float op2) {
    switch (op) {
        case '+': return (op1 + op2);
        case '-': return (op1 - op2);
        case '*': return (op1 * op2);
        case '/': return (op1 / op2);
        case '^': return pow(op1, op2);
        case '%': return ((int)op1 % (int)op2);
        default : return 0;
    }
}

void push(float value) {
    stack[++top] = value;
}

float pop() {
    return stack[top--];
}

int main() {
    char postfix[50], symbol;
    float op1, op2, res;

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++) {
        symbol = postfix[i];

        if (isdigit(symbol)) {
            push(symbol - '0');  // convert char to number
        } 
        else {
            op2 = pop();
            op1 = pop();
            res = operation(symbol, op1, op2);
            push(res);
        }
    }

    res = pop();
    printf("Result = %.2f\n", res);

    return 0;
}
