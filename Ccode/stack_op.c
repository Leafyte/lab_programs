//stack operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 5

int s[STACK_SIZE], top = -1;

void push(int item) {
    if (top == STACK_SIZE - 1) {
        printf("\nStack Overflow\n");
        return;
    }
    s[++top] = item;
}


int pop() {
    if (top == -1) {
        printf("\nStack Underflow\n");
        return -9999;
    }
    return s[top--];
}

void display() {
    if (top == -1) {
        printf("\nStack is empty\n");
        return;
    }

    printf("\nContents of the stack:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", s[i]);
    }
}

int is_palindrome(char str[]) {
    int len = strlen(str);
    char stk[50];
    int t = -1;

    
    for (int i = 0; i < len; i++) {
        stk[++t] = str[i];
    }

    
    for (int i = 0; i < len; i++) {
        if (str[i] != stk[t--])
            return 0;   
    }
    return 1; 
}

int main() {
    int item, item_deleted, choice, flag;
    char str[50];

    while (1) {
        printf("\n----- STACK OPERATIONS -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Palindrome Check\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                item_deleted = pop();
                if (item_deleted != -9999)
                    printf("Item deleted: %d\n", item_deleted);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Enter the string: ");
                scanf("%s", str);
                flag = is_palindrome(str);
                if (flag)
                    printf("The string is a palindrome\n");
                else
                    printf("The string is not a palindrome\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice, Try again.\n");
        }
    }

    return 0;
}

