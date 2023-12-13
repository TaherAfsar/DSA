#include <stdio.h>

#define MAX_NODES 100

int visited[MAX_NODES];
int adjacencyMatrix[MAX_NODES][MAX_NODES];
int numNodes;

void initialize()
{
    int i, j;
    for (i = 0; i < MAX_NODES; i++)
    {
        visited[i] = 0;
        for (j = 0; j < MAX_NODES; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(int start, int end)
{
    adjacencyMatrix[start][end] = 1;
    adjacencyMatrix[end][start] = 1;
}

void dfs(int node)
{
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < numNodes; i++)
    {
        if (adjacencyMatrix[node][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int startNode;

    // Hardcoded inputs
    numNodes = 5;
    initialize();

    // Assuming the graph is connected
    int hardcodedAdjacencyMatrix[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}};

    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            adjacencyMatrix[i][j] = hardcodedAdjacencyMatrix[i][j];
        }
    }

    startNode = 0; // Starting node for DFS

    printf("Depth-First Search starting from node %d: ", startNode);
    dfs(startNode);
    printf("\n");

    return 0;
}
