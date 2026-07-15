#include <stdio.h>
#include <stack>
using namespace std;

#define DIM 5

int graph[DIM][DIM] = {
    { 0, 1, 1, 0, 0 },  // 0
    { 1, 0, 0, 1, 1 },  // 1
    { 0, 0, 0, 1, 1 },  // 2
    { 0, 0, 1, 0, 0 },  // 3
    { 1, 1, 0, 1, 0 },  // 4
};


void dfs (int start) {
    int visited[DIM] = { 0 };
    stack<int> nodeStack;

    nodeStack.push(start);
    visited[start] = 1;

    while (!nodeStack.empty()) {
        int current = nodeStack.top();
        nodeStack.pop();
        
        for (int i = 0; i < DIM; i++) {
            if (!visited[i] && graph[current][i] == 1) {
                nodeStack.push(i);
                visited[current] = 1;
                break;
            }
        }
        
        printf("%d ", current);
    }
}


int main() {
    dfs(0);
}
