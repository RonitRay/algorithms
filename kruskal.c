#include < stdio.h > 
#define V 8
int find(int * visited, int n, int v) 
{
    int i, j;
    for (i = 0; i < n; i++) 
    {
        if (visited[i] == v)
            return 0;
    }
    return 1;
}
void kruskal(int graph[V][V], int edge[100], int n) 
{
    int visited[V - 1];
    int i, j, temp, count = 0, c = 0, min = 0, r = 0, flag = 0;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (edge[j] > edge[j + 1]) 
            {
                temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }
    while (r < V - 1) 
    {
        for (i = 0; i < V; i++) 
        {
            for (j = 0; j < V; j++) 
            {
                if (graph[i][j] == edge[count]) 
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        flag = 0;
        if (find(visited, c, i) == 1 || find(visited, c, j) == 1) 
        {
            if (find(visited, c, i) == 1)
                visited[c++] = i;
            if (find(visited, c, j) == 1)
                visited[c++] = j;
            printf("%d-->%d=%d\n", (i + 1), (j + 1), graph[i][j]);
            min += graph[i][j];
            r++;
        }
        count++;
        graph[i][j] = 0;
        graph[j][i] = 0;
    }
    printf("The total weight of the minimum spanning tree is %d", min);
}
int main() {
    int i, j, n = 0;
    int edge[100], p[V][V];
    int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
                     
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            p[i][j] = graph[i][j];
        }
    }
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (p[i][j] != 0) {
                edge[n++] = p[i][j];
                p[j][i] = 0;
            }
        }
    }
    kruskal(graph, edge, n);
    return 0;
}