//circular queue
#include <stdio.h>

#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue() {
    int x;
    printf("Enter the element to be inserted: ");
    scanf(" %d", &x);

    if ((rear + 1) % N == front) {
        printf("Queue is Full!\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    }
    else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty!\n");
    }
    else if (front == rear) {
        printf("Dequeued element: %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Dequeued element: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    int i = front;

    if (front == -1 && rear == -1) {
        printf("Queue is Empty!\n");
    }
    else {
        printf("Queue elements are: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n----- Circular Queue Menu -----\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("--------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}