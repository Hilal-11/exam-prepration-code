#include<stdio.h>
#include<stdlib.h>

#define V 4

void addEdge(int adjMatrix[V][V] , int i , int j) {
    adjMatrix[i][j] = 1;
    adjMatrix[j][i] = 1;
}

void displayMatrix(int adjMatrix[V][V]) {
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            printf("%d  ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int adjMatrix[V][V] = {0};

    addEdge(adjMatrix , 0 , 1);
    addEdge(adjMatrix , 0 , 2);
    addEdge(adjMatrix , 1 , 2);
    addEdge(adjMatrix , 2 , 3);

    printf("Adjacency Matrix Representation\n");
    displayMatrix(adjMatrix);

    return 0;
}