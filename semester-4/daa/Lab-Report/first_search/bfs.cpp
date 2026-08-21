#include <stdio.h>
#include <queue>
using namespace std;

#define DIM 5

int graph[DIM][DIM] = {
    { 0, 1, 1, 0, 0 },  // 0
    { 1, 0, 0, 1, 1 },  // 1
    { 0, 0, 0, 1, 1 },  // 2
    { 0, 0, 1, 0, 0 },  // 3
    { 1, 1, 0, 1, 0 },  // 4
};


void bfs (int start) {
    int visited[DIM] = { 0 };
    queue<int> nodeQueue;

    nodeQueue.push(start);
    visited[start] = 1;

    while (!nodeQueue.empty()) {
        int current = nodeQueue.front();
        nodeQueue.pop();
        
        for (int i = 0; i < DIM; i++) {
            if (!visited[i] && graph[current][i] == 1) {
                nodeQueue.push(i);
                visited[i] = 1;
            }
        }
        
        printf("%d ", current);
    }
}


int main() {
    bfs(0);
}
