#include <iostream>
#include <cmath>
#define DIM 5
#define G INFINITY
using namespace std;

double graph[DIM][DIM] = {
    {G, 2, 1, 7, 3}, // 0
    {2, G, G, 1, 1}, // 1
    {1, G, G, 6, 2}, // 2
    {7, 1, 6, G, 5}, // 3
    {3, 1, 2, 5, G}, /* 4 */ };

double dp[DIM];

void dijkstra(int start) {
    int visited[DIM];
    int source = start;
    for (int i = 0; i < DIM; i++) { dp[i] = G; visited[i] = 0; }
    dp[source] = 0;

    cout << source << "\t";
    for (int i = 0; i < DIM; i++) cout << dp[i] << "\t";
    cout << endl;

    for (int i = 0; i < DIM; i++) {   
        cout << source << "\t";
        for (int j = 0; j < DIM; j++) {
            dp[j] = min(dp[j], dp[source] + graph[source][j]);
            if (!visited[j]) cout << dp[j] << "\t";
            else cout << "\t"; }
        
        visited[source] = 1; double minDist = G;

        for (int j = 0; j < DIM; j++) {
            if (dp[j] < minDist && !visited[j]) {
                minDist = dp[j];
                source = j; } }
        cout << endl;
    }
}

int main()
{
    dijkstra(0);
}