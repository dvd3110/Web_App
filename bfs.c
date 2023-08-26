#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int n;
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);

    int i, j;
    int adjMatrix[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the adjacency matrix put 0 for no edge and 1 for edge:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    int src;
    printf("Enter the starting vertex: ");
    scanf("%d", &src);

    printf("BFS is starting from vertex %d\n", src);

    bool visited[n];
    for (i = 0; i < n; i++) {
        visited[i] = false;
    }

    int queue[n];
    int front = 0, rear = 0;

    visited[src] = true;
    queue[rear++] = src;

    while (front != rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int adjacent = 0; adjacent < n; adjacent++) {
            if (adjMatrix[currentVertex][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }

    return 0;
}
