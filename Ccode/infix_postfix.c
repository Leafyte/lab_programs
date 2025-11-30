//infix to postfix conversion
#include <stdio.h>
#include <string.h>

int F(char symbol) {   // Input precedence
    switch (symbol) {
        case '+': return 1;
        case '-': return 2;
        case '*': return 3;
        case '/': return 4;
        case '^': return 5;
        case '$': return 6;
        case '(': return 0;
        case '#': return -1;
        default: return 8;
    }
}

int G(char symbol) {   // Stack precedence
    switch (symbol) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '^': return 4;
        case '$': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;
    }
}

void infix_postfix(char infix[], char postfix[]) {
    char stack[50];
    int top = -1, j = 0;
    char symbol;

    stack[++top] = '#';

    for (int i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        while (F(stack[top]) > G(symbol)) {
            postfix[j++] = stack[top--];
        }

        if (F(stack[top]) != G(symbol)) {
            stack[++top] = symbol;
        } else {
            top--; // pop '('
        }
    }

    while (stack[top] != '#') {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

int main() {
    char infix[50], postfix[50];

    printf("Enter a valid infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infix_postfix(infix, postfix);

    printf("\nInfix Expression : %s", infix);
    printf("\nPostfix Expression : %s\n", postfix);

    return 0;
}
