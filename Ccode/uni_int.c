#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data);
bool isPresent(struct Node* head, int data);

struct Node* getUnion(struct Node* head1, struct Node* head2)
{
    struct Node* result = NULL;
    struct Node *t1 = head1, *t2 = head2;

    while (t1 != NULL) {
        push(&result, t1->data);
        t1 = t1->next;
    }

    while (t2 != NULL) {
        if (!isPresent(result, t2->data))
            push(&result, t2->data);
        t2 = t2->next;
    }
    return result;
}

struct Node* getIntersection(struct Node* head1, struct Node* head2)
{
    struct Node* result = NULL;
    struct Node* t1 = head1;

    while (t1 != NULL) {
        if (isPresent(head2, t1->data))
            push(&result, t1->data);
        t1 = t1->next;
    }

    return result;
}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

bool isPresent(struct Node* head, int data)
{
    struct Node* t = head;
    while (t != NULL) {
        if (t->data == data)
            return true;
        t = t->next;
    }
    return false;
}

int main()
{
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* intersecn = NULL;
    struct Node* unin = NULL;

    int n, x;

    printf("Enter number of elements for List A: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(&head1, x);
    }

    printf("Enter number of elements for List B: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(&head2, x);
    }

    intersecn = getIntersection(head1, head2);
    unin = getUnion(head1, head2);

    printf("\nFirst List:\n");
    printList(head1);

    printf("\nSecond List:\n");
    printList(head2);

    printf("\nIntersection List:\n");
    printList(intersecn);

    printf("\nUnion List:\n");
    printList(unin);

    return 0;
}

