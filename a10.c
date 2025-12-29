 #include <stdio.h>
int a[10][10], visited[10], recStack[10], n;
void read_AM(int a[10][10], int n)
{
   int i, j;
   printf("Enter adjacency matrix:\n");
   for(i = 0; i < n; i++)
       for(j = 0; j < n; j++)
           scanf("%d", &a[i][j]);
}
 
int dfs(int u)
{
   int v;
   visited[u] = 1;
   recStack[u] = 1;
 
   for(v = 0; v < n; v++)
   {
       if(a[u][v] == 1)
       {
           if(!visited[v] && dfs(v))
               return 1;          
           else if(recStack[v])
               return 1;          
       }
   }
   recStack[u] = 0;              
   return 0;
}
 
int main()
{
   int i;
 
   printf("Enter number of vertices: ");
   scanf("%d", &n);
 
   read_AM(a, n);
 
   for(i = 0; i < n; i++)
   {
       visited[i] = 0;
       recStack[i] = 0;
   }
 
   for(i = 0; i < n; i++)
   {
       if(!visited[i])
       {
           if(dfs(i))
           {
               printf("Graph contains a cycle\n");
               return 0;
           }
       }
   }
 
   printf("Graph does not contain a cycle\n");
   return 0;
}