//84. Write a program to create a graph & implement the adjacency list representation of the graph
//    -- Apply DFS and BFS on the given graph.

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // Adjust as needed

struct Node
{
    int info;
    struct Node *link;
};

// Function to add an edge to the graph
void addEdge(struct Node **adjList, int src, int dest)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = dest;
    newNode->link = NULL;
    newNode->link = adjList[src];
    adjList[src] = newNode;

    // As undirected graph
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = src;
    newNode->link = NULL;
    newNode->link = adjList[dest];
    adjList[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Node **adjList, int V)
{
    for (int i = 0; i < V; i++)
    {
        struct Node *save = adjList[i];
        printf("Vertex %d: ", i);
        while (save != NULL)
        {
            printf("-> %d ", save->info);
            save = save->link;
        }
        printf("\n");
    }
}

// Breadth-First Search
void bfs(struct Node **adjList, int startVertex, int V)
{
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("\nBFS Traversal starting from vertex %d: ", startVertex);

    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node *save = adjList[currentVertex];
        while (save != NULL)
        {
            int adjVertex = save->info;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            save = save->link;
        }
    }
    printf("\n");
}

// Depth-First Search (Recursive)
void dfsUtil(struct Node **adjList, int vertex, int visited[])
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node *save = adjList[vertex];
    while (save != NULL)
    {
        if (!visited[save->info])
        {
            dfsUtil(adjList, save->info, visited);
        }
        save = save->link;
    }
}

void dfs(struct Node **adjList, int startVertex, int V)
{
    int visited[MAX_VERTICES] = {0};
    printf("\nDFS Traversal starting from vertex %d: ", startVertex);
    dfsUtil(adjList, startVertex, visited);
    printf("\n");
}

int main()
{
    // Create a graph with 4 vertices
    int V = 4;

    // Allocate memory for adjacency list
    struct Node **adjList = malloc(V * sizeof(*adjList));

    // Initialize each list as empty
    for (int i = 0; i < V; i++)
        adjList[i] = NULL;

    // Add some edges
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 3);

    // Print adjacency list
    printGraph(adjList, V);

    // Perform BFS and DFS traversals
    bfs(adjList, 0, V);
    dfs(adjList, 0, V);

    return 0;
}