 #include <stdio.h>
#include <stdlib.h>
 
struct emp
{
   char ssn[20], name[20], dept[20], desg[20];
   int sal;
   int ph;
   struct emp *prev, *next;
};
 
typedef struct emp *node;
 
node head = NULL;
 
node getnode()
{
   node x = (node)malloc(sizeof(struct emp));
   return x;
}
 
void readEmployee(node temp)
{
   printf("Enter SSN: ");
   scanf("%s", temp->ssn);
   printf("Enter Name: ");
   scanf("%s", temp->name);
   printf("Enter Dept: ");
   scanf("%s", temp->dept);
   printf("Enter Designation: ");
   scanf("%s", temp->desg);
   printf("Enter Salary: ");
   scanf("%d", &temp->sal);
   printf("Enter Phone: ");
   scanf("%d", &temp->ph);
}
 
void insertRear()
{
   node temp = getnode();
   readEmployee(temp);
   temp->prev = temp->next = NULL;
 
   if (head == NULL)
   {
       head = temp;
   }
   else
   {
       node cur = head;
       while (cur->next != NULL)
           cur = cur->next;
       cur->next = temp;
       temp->prev = cur;
   }
}
 
void insertFront()
{
   node temp = getnode();
   readEmployee(temp);
   temp->prev = temp->next = NULL;
 
   if (head == NULL)
       head = temp;
   else
   {
       temp->next = head;
       head->prev = temp;
       head = temp;
   }
}
 
void deleteFront()
{
   if (head == NULL)
   {
       printf("List is empty.\n");
       return;
   }
 
   node temp = head;
   head = head->next;
 
   if (head != NULL)
       head->prev = NULL;
 
   free(temp);
   printf("Deleted from front.\n");
}
 
void deleteRear()
{
   if (head == NULL)
   {
       printf("List is empty.\n");
       return;
   }
 
   node cur = head;
 
   if (cur->next == NULL) // Only one node
   {
       head = NULL;
       free(cur);
       printf("Deleted last node.\n");
       return;
   }
 
   while (cur->next != NULL)
       cur = cur->next;
 
   (cur->prev)->next = NULL;
   free(cur);
   printf("Deleted from rear.\n");
}
 
void display()
{
   if (head == NULL)
   {
       printf("List is empty.\n");
       return;
   }
 
   node temp = head;
   int count = 0;
 
   printf("\nEMPLOYEE LIST:\n");
   while (temp != NULL)
   {
       printf("SSN: %s | Name: %s | Dept: %s | Desg: %s | Salary: %d | Phone: %d\n",
              temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->ph);
 
       count++;
       temp = temp->next;
   }
 
   printf("\nTotal Employees: %d\n", count);
}
 
int main()
{
   int ch, n, i;
 
   while (1)
   {
       printf("\nMENU:\n");
       printf("1. Create DLL by inserting from rear\n");
       printf("2. Display and count\n");
       printf("3. Insert from front\n");
       printf("4. Insert from rear\n");
       printf("5. Delete from front\n");
       printf("6. Delete from rear\n");
       printf("7. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &ch);
 
       switch (ch)
       {
       case 1:
           printf("Enter th number of employees: ");
           scanf("%d", &n);
           for (i = 0; i < n; i++)
               insertRear();
           break;
 
       case 2:
           display();
           break;
 
       case 3:
           insertFront();
           break;
 
       case 4:
           insertRear();
           break;
 
       case 5:
           deleteFront();
           break;
 
       case 6:
           deleteRear();
           break;
 
       case 7:
           return 0;
 
       default:
           printf("Invalid choice.\n");
       }
   }
}
 