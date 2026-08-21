#include <iostream>
#include <cmath>
#define DIM 5
#define I INFINITY
using namespace std;

double graph[DIM][DIM] = {
    {I, 2, 1, 7, 3}, // 0
    {2, I, I, 1, 1}, // 1
    {1, I, I, 6, 2}, // 2
    {7, 1, 6, I, 5}, // 3
    {3, 1, 2, 5, I}, // 4
};

double dp[DIM];
bool visited[DIM];

int chooseSource(void) {
    double minNumber = I;
    int source;
    for (int index = 0; index < DIM; index++) {
        if (!visited[index] && dp[index] < minNumber) {
            minNumber = dp[index];
            source = index;
        }
    }
    visited[source] = true;
    return source;
}

double getCost(int u, int v) { return graph[u][v]; }

int main()
{
    int start = 0;
    for (int i = 0; i < DIM; i++) {
        dp[i] = I;
        visited[i] = false;
    }
    dp[start] = 0;

    for (int i = 0; i < DIM; i++) {
        for (int v = 0, u = chooseSource(); v < DIM; v++) {
            dp[v] = min(dp[v], dp[u] + getCost(u, v));
        }
    }

    return 0;
}