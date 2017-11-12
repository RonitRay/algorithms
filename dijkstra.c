#include <stdio.h>
#include <limits.h>
#define V 9
int minDistance(int d[], bool set[])
{
   int min = INT_MAX, pos;
  
   for (int v = 0; v < V; v++)
     if (set[v] == false && d[v] <= min)
         min = d[v], pos = v;
  
   return pos;
}
  
int printSolution(int d[], int n)
{
   printf("Vertex\tDistance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d\t%d\n", i, d[i]);
}

void dijkstra(int g[V][V], int src)
{
    int d[V];
    bool set[V]; 
    for (int i = 0; i < V; i++)
      d[i] = INT_MAX, set[i] = false;
     
    d[src] = 0;

    for (int count = 0; count < V-1; count++)
    {
     int u = minDistance(d, set);

     set[u] = true;

     for (int v = 0; v < V; v++)

       if (!set[v] && g[u][v] && d[u] != INT_MAX  && d[u]+g[u][v] < d[v])
          d[v] = d[u] + g[u][v];
    }
    printSolution(d, V);
}
  
int main()
{
   int g[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(g, 0);  
    return 0;
}