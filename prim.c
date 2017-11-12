#include <stdio.h>
#include <limits.h>
#define V 5
 
int minKey(int key[], bool set[])
{
   int min = INT_MAX, pos;
 
   for (int v = 0; v < V; v++)
      if (set[v] == false && key[v] < min)
      {
          min = key[v];
          pos = v; 
      }
   return pos;
}
 
int printMST(int p[], int n, int g[V][V])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", p[i], i, g[i][p[i]]);
}
 
void primMST(int g[V][V])
{
    int p[V];
    int key[V];
    bool set[V];
 
    for (int i = 0; i < V; i++)
      key[i] = INT_MAX, set[i] = false;
 
    key[0] = 0;
    p[0] = -1;
 
    for (int count = 0; count < V-1; count++)
    {
        int u = minKey(key, set);
        set[u] = true;

        for (int v = 0; v < V; v++)
          if (g[u][v] && set[v] == false && g[u][v] <  key[v])
          {
              p[v]  = u;
              key[v] = graph[u][v];
          }
    }
    printMST(p, V, g);
}
 
int main()
{
   int g[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
 
    primMST(g); 
    return 0;
}