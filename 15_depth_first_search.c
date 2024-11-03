#include <stdio.h>
#define MAX 100  

void dfs(int graph[MAX][MAX], int visited[MAX], int vertex, int n) {
    printf("%d ", vertex);   
    visited[vertex] = 1;     


    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) { 
            dfs(graph, visited, i, n);
        }
    }
}

int main() {
    int n, start;
    int graph[MAX][MAX];
    int visited[MAX] = {0}; 

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal starting from vertex %d: ", start);
    dfs(graph, visited, start, n);
    printf("\n");

    return 0;
}
