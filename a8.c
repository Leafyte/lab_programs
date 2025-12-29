#include <stdio.h>
#include <stdlib.h>
 
struct dll {
   int info;
   struct dll *p, *n;
};
typedef struct dll *node;
 
node header = NULL;
node getnode()
{
   node x = (node)malloc(sizeof(struct dll));
   return x;
}
 
void ins()
{
   node temp;
   int x;
   printf("Enter element: ");
   scanf("%d", &x);
 
   temp = getnode();
   temp->info = x;
   temp->p = NULL;
   temp->n = header;
 
   if (header != NULL)
       header->p = temp;
   header = temp;
}
void disp()
{
   node temp;
   for (temp = header; temp != NULL; temp = temp->n)
       printf("%d ", temp->info);
   printf("\n");
}
 
node reverse()
{
   node curr = header, prev = NULL, next;
 
   while (curr != NULL)
   {
       next = curr->n;
 
       curr->n = prev;
       curr->p = next;
 
       prev = curr;
       curr = next;
   }
 
   header = prev;  // new head after reversing
   return header;
}
 
int main()
{
   int n, i, x;
   printf("Enter number of nodes: ");
   scanf("%d", &n);
   printf("Enter %d elements:\n", n);
   for (i = 0; i < n; i++)
       ins();  
 
   printf("\nOriginal list: ");
   disp();
 
   reverse();  
 
   printf("Reversed list: ");
   disp();
 
   return 0;
}