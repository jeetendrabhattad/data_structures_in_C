#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

void InDegree(int **graph, int noOfVertices)
{
    int i;

    for( i = 0 ; i < noOfVertices ; i++)
    {
        int in_degree = 0,j;
        for( j = 0 ; j < noOfVertices ; j++)
        {
            if(graph[j][i])
                in_degree++;
        }
        printf("\nIn-Degree of v%d is %d", i, in_degree);
    }
}

void OutDegree(int **graph, int noOfVertices)
{
    int i;

    for( i = 0 ; i < noOfVertices ; i++)
    {
        int out_degree = 0,j;
        for( j = 0 ; j < noOfVertices ; j++)
        {
            if(graph[i][j])
                out_degree++;
        }
        printf("\nOut-Degree of v%d is %d", i, out_degree);
    }
}

void BFS(int **graph, int noOfVertices)
{
    Queue q;
    InitQueue(&q, noOfVertices);
    int *visited = malloc(sizeof(int)*noOfVertices);
    memset(visited, 0, noOfVertices*sizeof(int));
    int startingVertex;
    
    printf("\n****************BFS***************\n");
    printf("\n Enter starting vertex:-");
    scanf("%d", &startingVertex);

    printf("\nVertex visited: %d", startingVertex);
    visited[startingVertex-1] = 1;
    EnQueue(&q, startingVertex-1);

    while(!IsQueueEmpty(&q))
    {
        int vertex = DeQueue(&q);
        for(int i = 0 ; i < noOfVertices ; i++)
        {
            if(graph[vertex][i] && visited[i] == 0)
            {
                printf("\nVertex visited: %d", i+1);           
                visited[i] = 1;
                EnQueue(&q, i);
            }
        }
    }
    free(visited);
    DeInitQueue(&q);
}

void DFS(int **graph, int noOfVertices)
{
    printf("\n****************DFS***************\n");
    STACK_T st;
    InitStack(&st, noOfVertices);
    int *visited = malloc(sizeof(int)*noOfVertices);
    memset(visited, 0, noOfVertices*sizeof(int));
    int startingVertex;

    printf("\n Enter starting vertex:-");
    scanf("%d", &startingVertex);

    visited[startingVertex-1] = 1;
    Push(&st, startingVertex-1);
    printf("\nVertex visited: %d", startingVertex);

    while(!IsEmpty(&st))
    {
        int vertex = Pop(&st);
        for(int i = 0 ; i < noOfVertices ; i++)
        {
            if(graph[vertex][i] && visited[i] == 0)
            {
                visited[i] = 1;
                Push(&st, i);
                printf("\nVertex visited: %d", i+1);        
                break;
            }
        }
    }
    free(visited);
    DeInitStack(&st);
}

void SimulateGraph()
{
    int **graph;
    int noOfVertices;
    int i, j;
    printf("Enter Number of Vertices graph has:-");
    scanf("%d", &noOfVertices);

    graph = (int **)malloc(noOfVertices*sizeof(int*));
    for(i = 0 ; i < noOfVertices ; i++)
        graph[i] = (int *)malloc(noOfVertices*sizeof(int));

    // accept graph
    for( i = 1 ; i <= noOfVertices ; i++)
        for( j = 1 ; j <= noOfVertices ; j++)
        {
            if(i != j)
            {
                printf("\nEnter 1 if there is an edge between (v%d,v%d) o.w 0:-",i,j);
                scanf("%d", &graph[i-1][j-1]);
            }
        }

    // calculate in-degree of all vertices
    InDegree(graph, noOfVertices);
    // calculate out-degree of all vertices
    OutDegree(graph, noOfVertices);
    // BFS
    BFS(graph, noOfVertices);
    // DFS
    DFS(graph, noOfVertices);
    for(i = 0 ; i < noOfVertices ; i++)
        free(graph[i]);
    free(graph);
}

int main()
{
    SimulateGraph();
}
