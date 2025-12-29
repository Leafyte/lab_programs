 #include <stdio.h>
#include <stdlib.h>
 
struct Node {
   int data;
   struct Node* next;
};
 
struct Node* createNode(int data) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   if (newNode == NULL) {
       printf("Memory allocation failed!\n");
       exit(1);
   }
 
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}
 
void printList(struct Node* head) {
   struct Node* temp = head;
   while (temp != NULL) {
       printf("%d -> ", temp->data);
       temp = temp->next;
   }
   printf("NULL\n");
}
 
struct Node* concat(struct Node* head1, struct Node* head2) {
   if (head1 == NULL)
       return head2;
   if (head2 == NULL)
       return head1;
   struct Node* temp = head1;
   while (temp->next != NULL) {
       temp = temp->next;
   }
   temp->next = head2;
   return head1;
}
 
int main() {
   struct Node *head1 = NULL, *head2 = NULL, *temp, *newNode;
   int n1, n2, value;
 
   printf("Enter number of elements for first list: ");
   scanf("%d", &n1);
   for (int i = 0; i < n1; i++) {
       scanf("%d", &value);
 
       newNode = createNode(value);
       if (head1 == NULL)
           head1 = newNode;
       else {
           temp = head1;
           while (temp->next != NULL)
               temp = temp->next;
           temp->next = newNode;
       }
   }
 
   printf("First list: ");
   printList(head1);
 
   printf("Enter number of elements for second list: ");
   scanf("%d", &n2);
 
   for (int i = 0; i < n2; i++) {
       scanf("%d", &value);
       newNode = createNode(value);
       if (head2 == NULL)
           head2 = newNode;
       else {
           temp = head2;
           while (temp->next != NULL)
               temp = temp->next;
           temp->next = newNode;
       }
   }
 
   printf("Second list: ");
   printList(head2);
 
   struct Node* concat_result = concat(head1, head2);
 
   printf("Concatenated list: ");
   printList(concat_result);
 
   while (concat_result != NULL) {
       temp = concat_result;
       concat_result = concat_result->next;
       free(temp);
   }
 
   return 0;
}