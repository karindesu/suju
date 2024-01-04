#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Graph {
    int numNodes;
    Node** adjacencyList;
} Graph;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numNodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    graph->adjacencyList = (Node**)malloc(numNodes * sizeof(Node*));

    int i;
    for (i = 0; i < numNodes; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int from, int to) {
    Node* newNode = createNode(to);
    newNode->next = graph->adjacencyList[from];
    graph->adjacencyList[from] = newNode;
}

void dfs(Graph* graph, int node, bool* visited) {
    visited[node] = true;
    Node* adjNode = graph->adjacencyList[node];
    while (adjNode != NULL) {
        if (!visited[adjNode->value]) {
            dfs(graph, adjNode->value, visited);
        }
        adjNode = adjNode->next;
    }
}

bool isStronglyConnected(Graph* graph) {
    bool* visited = (bool*)malloc(graph->numNodes * sizeof(bool));
    int i;
    for (i = 0; i < graph->numNodes; i++) {
        visited[i] = false;
    }

    dfs(graph, 0, visited);
    for (i = 0; i < graph->numNodes; i++) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }

    Graph* transposeGraph = createGraph(graph->numNodes);
    for (i = 0; i < graph->numNodes; i++) {
        Node* adjNode = graph->adjacencyList[i];
        while (adjNode != NULL) {
            addEdge(transposeGraph, adjNode->value, i);
            adjNode = adjNode->next;
        }
    }

    for (i = 0; i < graph->numNodes; i++) {
        visited[i] = false;
    }
    dfs(transposeGraph, 0, visited);
    for (i = 0; i < graph->numNodes; i++) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }

    free(visited);
    return true;
}

void freeGraph(Graph* graph) {
    int i;
    for (i = 0; i < graph->numNodes; i++) {
        Node* adjNode = graph->adjacencyList[i];
        while (adjNode != NULL) {
            Node* temp = adjNode;
            adjNode = adjNode->next;
            free(temp);
        }
    }
    free(graph->adjacencyList);
    free(graph);
}
int main(void)
{
    int numVertices, numEdges;
    printf("请输入顶点的数量：");
    scanf("%d", &numVertices);
    printf("请输入边的数量：");
    scanf("%d", &numEdges);

    Graph* graph = createGraph(numVertices);

    printf("请输入边(起点 终点)，每行一条：\n");
    for (int i = 0; i < numEdges; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        addEdge(graph, from, to);
    }
    if (isStronglyConnected(graph))
	{
        printf("Yes\n");
    }
	else
	{
        printf("No\n");
    }

    freeGraph(graph);

    return 0;
}
