#include <iostream>
#include <cmath>
#define DIM 5
#define G INFINITY
using namespace std;

double graph[DIM][DIM] = {
    {G, 2, 1, 7, 1}, // 0
    {2, G, G, 1, 1}, // 1
    {1, G, G, 6, 2}, // 2
    {7, 1, 6, G, 5}, // 3
    {1, 1, 2, 5, G}, /* 4 */
    };
void bellman(int start) {
    double dp[DIM];
    for (int i = 0; i < DIM; i++) { dp[i] = G; }
    dp[start] = 0;

    for (int k = 1; k < DIM; k++) {
        for (int u = 0; u < DIM; u++) {
            for (int v = 0; v < DIM; v++) {
                    dp[v] = min(dp[v], dp[u] + graph[u][v]);
            }
        }
    }

    for (int u = 0; u < DIM; u++) {
        for (int v = 0; v < DIM; v++) {
            if (dp[u] + graph[u][v] < dp[v]) {
                cout << "Graph contains a negative weight cycle!" << endl;
                return;
            }
        }
    }

    for (int i = 0; i < DIM; i++) {
        cout << "Distance from " << start << " to " << i << " = " << dp[i] << endl;
    }
}


int main()
{
    bellman(0);
}