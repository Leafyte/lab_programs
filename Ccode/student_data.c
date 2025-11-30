#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char usn[20];
    char name[50];
    char dept[20];
    int sem;
    char phno[15];
    struct Student *next;
};

struct Student *top = NULL;

struct Student *createNode() {
    struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));

    printf("\nEnter Student USN: ");
    scanf("%s", newNode->usn);

    printf("Enter Name: ");
    scanf("%s", newNode->name);

    printf("Enter Department: ");
    scanf("%s", newNode->dept);

    printf("Enter Semester: ");
    scanf("%d", &newNode->sem);

    printf("Enter Phone Number: ");
    scanf("%s", newNode->phno);

    newNode->next = NULL;
    return newNode;
}

void push() {
    struct Student *newNode = createNode();
    newNode->next = top;
    top = newNode;
    printf("\nStudent data pushed onto the stack.\n");
}

void pop() {
    if (top == NULL) {
        printf("\nStack Underflow! No data to pop.\n");
        return;
    }

    struct Student *temp = top;
    top = top->next;

    printf("\nPopped Student Data:\n");
    printf("USN: %s\nName: %s\nDept: %s\nSem: %d\nPhNo: %s\n",
           temp->usn, temp->name, temp->dept, temp->sem, temp->phno);

    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("\nStack is empty!\n");
        return;
    }

    printf("\nTop Student Data:\n");
    printf("USN: %s\nName: %s\nDept: %s\nSem: %d\nPhNo: %s\n",
           top->usn, top->name, top->dept, top->sem, top->phno);
}

void display() {
    if (top == NULL) {
        printf("\nStack is empty!\n");
        return;
    }

    struct Student *temp = top;
    printf("\nStack contents (Top to Bottom):\n");

    while (temp != NULL) {
        printf("USN: %s | Name: %s | Dept: %s | Sem: %d | PhNo: %s\n",
               temp->usn, temp->name, temp->dept, temp->sem, temp->phno);
        temp = temp->next;
    }
}

int main() {
    int choice;

    printf("----- STACK USING SINGLY LINKED LIST -----\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. PUSH (Insert)\n");
        printf("2. POP (Delete)\n");
        printf("3. PEEK (Top Element)\n");
        printf("4. DISPLAY Stack\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
