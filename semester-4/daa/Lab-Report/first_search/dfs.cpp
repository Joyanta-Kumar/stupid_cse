#include <stdio.h>
#include <stack>
using namespace std;
#define DIM 5
#define start 0

int graph[DIM][DIM] = {
    { 0, 1, 1, 0, 0 },  // 0
    { 1, 0, 0, 1, 1 },  // 1
    { 0, 0, 0, 1, 1 },  // 2
    { 0, 0, 1, 0, 0 },  // 3
    { 1, 1, 0, 1, 0 },  // 4
};

int visited[DIM];
stack<int> nodeStack;

int main() {
    for (int i = 0; i < DIM; i++) { visited[i] = false; }
    nodeStack.push(start);

    while (!nodeStack.empty()) {
        int current = nodeStack.top();
        nodeStack.pop();
        visited[current] = true;
        printf("%d ", current);

        for (int i = 0; i < DIM; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                nodeStack.push(i); break;
            }
        }
    }
}
