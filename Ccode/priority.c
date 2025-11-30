#include <stdio.h>
#include <stdlib.h> 

#define MAX 3

struct PQ {
    int pid;
    int pr;
    int bt;
};

struct PQ queue[MAX];
int front = -1, rear = -1;

void insert() {
    int pid, pr, bt;

    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }
    
    printf("Enter Process ID, Priority and Burst Time:\n");
    scanf(" %d %d %d", &pid, &pr, &bt);   

    if (front == -1)
        front = 0;
        rear++;

    queue[rear].pid = pid;
    queue[rear].pr = pr;
    queue[rear].bt = bt;
    
    printf("Item inserted successfully!\n");
}

void deleteItem() {
    int i, pos, max;
    
    if (front == -1) {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }
    
    max = queue[front].pr;
    pos = front;
    
    
    for (i = front + 1; i <= rear; i++) {
        if (queue[i].pr > max) {
            max = queue[i].pr;
            pos = i;
        }
    }
    
    printf("Deleted Element:\n");
    printf("PID = %d | Priority = %d | Burst Time = %d\n", 
           queue[pos].pid, queue[pos].pr, queue[pos].bt);
           
    for (i = pos; i < rear; i++) {
        queue[i] = queue[i + 1];
    }
    rear--;
    
    if (rear < front) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty.\n");
        return;
    }
    
    printf("\nPID\tPriority\tBurst Time\n");
    printf("- - - - - - - - - - - - - - \n");
    
    for (int i = front; i <= rear; i++) {
        printf("%d\t%d\t\t%d\n", queue[i].pid, queue[i].pr, queue[i].bt);
    }
    
    printf("- - - - - - - - - - - - - - \n");
    printf("Total number of items in queue: %d\n", rear - front + 1);
}

int main() {
    int ch;
    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &ch);  
        
        switch (ch) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: deleteItem(); break;
            case 4: printf("exiting...\n");exit(0);
            default: printf("Invalid Choice! Try again.\n");
        }
    }
    return 0;
}
