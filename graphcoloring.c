#include<stdio.h>
#define V 4
 
void printSolution(int c[])
{
    printf("Solution Exists: \n");
    for (int i = 0; i < V; i++)
      printf(" %d ", c[i]);
    printf("\n");
}

int isSafe (int v, int g[V][V], int col[], int c)
{
    for (int i = 0; i < V; i++)
        if (g[v][i] && c == col[i])
            return 0;
    return 1;
}
 
int util(int g[V][V], int m, int col[], int v)
{
    if (v == V)
        return 1;
 
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, g, col, c))
        {
           col[v] = c;
 
           if (util (g, m, col, v+1) == 1)
             return 1;
 
           col[v] = 0;
        }
    }
     return 0;
}
 
int graphColoring(int g[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
       color[i] = 0;
 
    if (!util(g, m, color, 0))
    {
      printf("Solution does not exist");
      return 0;
    }
     printSolution(color);
    return 1;
}

int main()
{
    int graph[V][V] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3;
    graphColoring (graph, m);
    return 0;
}