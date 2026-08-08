## Table of Contents


| S.No | Algorithm |
|:----:|:----|
| 1 | [Depth First Search](#depth-first-search) |
| 2 | [Breadth First Search](#breadth-first-search) |
| 3 | [Dijkstra's Shortest Path Algorithm](#dijkstras-shortest-path-algorithm) |
| 4 | [Bellman-Ford Algorithm](#bellman-ford-algorithm) |
| 5 | [Floyd-Warshall Algorithm](#floyd-warshall-algorithm) |
| 6 | [Counting Inversions using Merge Sort](#counting-inversions-using-merge-sort) |
| 7 | [Fractional Knapsack Algorithm](#fractional-knapsack-algorithm) |
| 8 | [Job Scheduling with Deadlines](#job-scheduling-with-deadlines) |
| 9 | [0/1 Knapsack Algorithm](#01-knapsack-algorithm) |
| 10 | [Kruskal's Minimum Spanning Tree Algorithm](#kruskals-minimum-spanning-tree-algorithm) |
| 11 | [Prim's Minimum Spanning Tree Algorithm](#prims-minimum-spanning-tree-algorithm) |
| 12 | [Longest Common Subsequence Algorithm](#longest-common-subsequence-algorithm) |
| 13 | [Coin Related Problems](#coin-related-problems) |
| 14 | [Maximum and Minimum using Divide and Conquer](#maximum-and-minimum-using-divide-and-conquer) |



# Depth First Search

## Objective

To implement and analyze the Depth First Search (DFS) algorithm for graph traversal using an adjacency matrix representation.

## Theory

Depth First Search (DFS) is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It uses a stack (explicit or implicit via recursion) to keep track of vertices.

## Time and Space Complexity

- Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
- Space Complexity: O(V), due to the stack used in recursion or iteration.

## Algorithm

```py
def DFS(G, start):
    mark start as visited
    push start onto stack 

    while stack is not empty:
        current = pop from stack
        for each neighbor of current:
            if neighbor is not visited:
                mark neighbor as visited
                push neighbor onto stack
        print current
```

## Implementation

```cpp
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
```

## Output

```sh
0 1 3 2 4
```

# Breadth First Search

## Objective
To implement and analyze the Breadth First Search (BFS) algorithm for graph traversal.

## Theory
Breadth First Search (BFS) explores vertices level by level using a queue.

## Time and Space Complexity
- Time Complexity: O(V + E)
- Space Complexity: O(V)

## Algorithm
```py
def BFS(G, start):
    mark start as visited
    enqueue start
    while queue is not empty:
        current = dequeue
        for each neighbor of current:
            if neighbor not visited:
                mark neighbor visited
                enqueue neighbor
        print current
```

## Implementation

```cpp
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
```

## Output

```sh
0 1 3 2 4
```

# Dijkstra’s Shortest Path Algorithm

## Objective

To implement Dijkstra’s algorithm for finding shortest paths from a source vertex.

## Theory

Dijkstra’s algorithm uses a priority queue to repeatedly select the vertex with minimum distance.

## Time and Space Complexity

- Time Complexity: O((V + E) log V) with priority queue
- Space Complexity: O(V)

## Algorithm

```py
def Dijkstra(G, source):
    initialize dist[source] = 0, others = ∞
    use priority queue
    while queue not empty:
        u = extract-min
        for each neighbor v of u:
            if dist[v] > dist[u] + weight(u,v):
                dist[v] = dist[u] + weight(u,v)
```


## Implementation

```cpp
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
```

## Output
```sh
0       0       inf     inf     inf     inf
0       0       2       1       7       3
2               2       1       7       3
1               2               3       3
3                               3       3
4                                       3
```

# Bellman-Ford Algorithm

## Objective

To implement and analyze the Bellman-Ford algorithm for finding shortest paths from a source vertex in a weighted graph, even when negative edge weights are present.

## Theory

The Bellman-Ford algorithm computes shortest paths by relaxing all edges repeatedly. Unlike Dijkstra’s algorithm, it can handle graphs with negative edge weights. If after \(V-1\) iterations a further relaxation is possible, the graph contains a negative weight cycle.

## Time and Space Complexity

- Time Complexity: O(V · E), where V is the number of vertices and E is the number of edges.
- Space Complexity: O(V)

## Algorithm

```py
def BellmanFord(G, source):
    initialize dist[v] = ∞ for all vertices v
    dist[source] = 0

    for i in range(1, V):
        for each edge (u, v) with weight w:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    # check for negative weight cycles
    for each edge (u, v) with weight w:
        if dist[u] + w < dist[v]:
            report "Negative weight cycle detected"
```




## Implementation

```cpp
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
```

## Output
```sh
Distance from 0 to 0 = 0
Distance from 0 to 1 = 2
Distance from 0 to 2 = 1
Distance from 0 to 3 = 3
Distance from 0 to 4 = 1
```

# Floyd-Warshall Algorithm

## Objective

To implement and analyze the Floyd-Warshall algorithm for finding shortest paths between all pairs of vertices in a weighted graph using an adjacency matrix.

## Theory

The Floyd-Warshall algorithm is a dynamic programming technique that computes shortest paths between all pairs of vertices. It works by iteratively updating the adjacency matrix, considering each vertex as an intermediate point. It can handle negative edge weights but not negative cycles.

## Time and Space Complexity

- Time Complexity: O(V³), where V is the number of vertices.
- Space Complexity: O(V²), due to the distance matrix.

## Algorithm

```py
def FloydWarshall(G):
    dist = adjacency matrix of G
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist
```

<!--  -->

## Implementation

```cpp
#include <iostream>
#include <climits>
using namespace std;
#define V 4

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX
                    && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) cout << "INF" << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    floydWarshall(graph);
    return 0;
}
```

## Output

```sh
Shortest distances between every pair of vertices:
0 5 8 9 
INF 0 3 4 
INF INF 0 1 
INF INF INF 0 
```

# Counting Inversions using Merge Sort

## Objective

To implement an algorithm that counts the number of inversions in an array using the merge sort technique.

## Theory

An inversion is a pair of indices (i, j) where i < j but arr[i] > arr[j]. The merge sort approach efficiently counts inversions by dividing the array and counting inversions during the merge process.

## Time and Space Complexity

- Time Complexity: O(n log n), where n is the number of elements.
- Space Complexity: O(n), for the temporary arrays used in merge.

## Algorithm

```py
def mergeAndCount(arr, left, mid, right):
    count = 0
    i = left, j = mid + 1, k = left
    temp = new array
    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            temp[k++] = arr[i++]
        else:
            temp[k++] = arr[j++]
            count += (mid - i + 1)
    copy remaining elements
    return count

def mergeSortAndCount(arr, left, right):
    if left < right:
        mid = (left + right) / 2
        count = mergeSortAndCount(arr, left, mid)
        count += mergeSortAndCount(arr, mid + 1, right)
        count += mergeAndCount(arr, left, mid, right)
    return count
```



## Implementation

```cpp
#include <iostream>
using namespace std;

long long mergeAndCount(int arr[], int left, int mid, int right) {
    int leftArr[mid - left + 1];
    int rightArr[right - mid];
    
    for (int i = 0; i <= mid - left; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < right - mid; i++)
        rightArr[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    long long invCount = 0;
    
    while (i <= mid - left && j < right - mid) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            invCount += (mid - left - i + 1);
        }
    }
    
    while (i <= mid - left)
        arr[k++] = leftArr[i++];
    while (j < right - mid)
        arr[k++] = rightArr[j++];
    
    return invCount;
}

long long mergeSortAndCount(int arr[], int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        invCount += mergeSortAndCount(arr, left, mid);
        invCount += mergeSortAndCount(arr, mid + 1, right);
        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
}

int main() {
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Number of inversions: " << mergeSortAndCount(arr, 0, n - 1) << endl;
    return 0;
}
```

## Output

```sh
Number of inversions: 5
```

# Fractional Knapsack Algorithm

## Objective

To implement the fractional knapsack algorithm where items can be partially included to maximize the total value without exceeding the knapsack capacity.

## Theory

In fractional knapsack, items are sorted by their value-to-weight ratio in descending order. Items are then greedily selected starting with the highest ratio. If an item doesn't fit completely, a fraction of it is included.

## Time and Space Complexity

- Time Complexity: O(n log n), where n is the number of items (due to sorting).
- Space Complexity: O(n), for storing items.

## Algorithm

```py
def fractionalKnapsack(items, capacity):
    sort items by value/weight ratio in descending order
    totalValue = 0
    for each item in sorted order:
        if item.weight <= capacity:
            capacity -= item.weight
            totalValue += item.value
        else:
            totalValue += (capacity / item.weight) * item.value
            break
    return totalValue
```



## Implementation

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

bool compareRatio(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(Item items[], int n, int capacity) {
    sort(items, items + n, compareRatio);
    
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += (double)capacity / items[i].weight * items[i].value;
            break;
        }
    }
    return totalValue;
}

int main() {
    Item items[] = {
        {10, 60, 6.0},
        {20, 100, 5.0},
        {30, 120, 4.0}
    };
    int n = 3;
    int capacity = 50;
    
    cout << "Maximum value: " << fractionalKnapsack(items, n, capacity) << endl;
    return 0;
}
```

## Output

```sh
Maximum value: 240
```

# Job Scheduling with Deadlines

## Objective

To implement the job scheduling algorithm where jobs with deadlines must be scheduled to maximize profit.

## Theory

Jobs are sorted by profit in descending order. Each job is scheduled in the latest available slot before its deadline. A greedy approach ensures maximum profit.

## Time and Space Complexity

- Time Complexity: O(n²) in worst case, where n is the number of jobs.
- Space Complexity: O(n), for storing jobs and schedule.

## Algorithm

```py
def jobScheduling(jobs, n):
    sort jobs by profit in descending order
    schedule = array of size n+1
    totalProfit = 0
    
    for each job:
        for t = job.deadline down to 1:
            if schedule[t] is empty:
                schedule[t] = job
                totalProfit += job.profit
                break
    return totalProfit
```



## Implementation

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compareProfit(Job a, Job b) {
    return a.profit > b.profit;
}

int jobScheduling(Job jobs[], int n) {
    sort(jobs, jobs + n, compareProfit);
    
    bool schedule[n + 1] = {false};
    int totalProfit = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (!schedule[j]) {
                schedule[j] = true;
                totalProfit += jobs[i].profit;
                cout << "Job " << jobs[i].id << " scheduled at slot " << j << endl;
                break;
            }
        }
    }
    return totalProfit;
}

int main() {
    Job jobs[] = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 2, 40},
        {4, 2, 30}
    };
    int n = 4;
    
    cout << "Maximum profit: " << jobScheduling(jobs, n) << endl;
    return 0;
}
```

## Output

```sh
Job 3 scheduled at slot 2
Job 4 scheduled at slot 2
Job 1 scheduled at slot 1
Maximum profit: 90
```

# 0/1 Knapsack Algorithm

## Objective

To implement the 0/1 knapsack problem using dynamic programming where items can either be fully included or excluded.

## Theory

The 0/1 knapsack uses dynamic programming with a table where dp[i][w] represents the maximum value achievable using the first i items with weight limit w. Each item is either taken or not taken based on which gives the maximum value.

## Time and Space Complexity

- Time Complexity: O(n × W), where n is the number of items and W is the knapsack capacity.
- Space Complexity: O(n × W), for the DP table.

## Algorithm

```py
def knapsack01(items, n, capacity):
    dp = 2D array of size (n+1) x (capacity+1)
    
    for i in range(1, n+1):
        for w in range(1, capacity+1):
            if items[i-1].weight <= w:
                dp[i][w] = max(items[i-1].value + dp[i-1][w-items[i-1].weight], dp[i-1][w])
            else:
                dp[i][w] = dp[i-1][w]
    
    return dp[n][capacity]
```



## Implementation

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

int knapsack01(Item items[], int n, int capacity) {
    int dp[n + 1][capacity + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i - 1].weight <= w)
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], 
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][capacity];
}

int main() {
    Item items[] = {
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 6}
    };
    int n = 4;
    int capacity = 8;
    
    cout << "Maximum value: " << knapsack01(items, n, capacity) << endl;
    return 0;
}
```

## Output

```sh
Maximum value: 13
```

# Kruskal's Minimum Spanning Tree Algorithm

## Objective

To implement Kruskal's algorithm for finding the minimum spanning tree using a greedy approach with union-find data structure.

## Theory

Kruskal's algorithm sorts edges by weight in ascending order and adds edges to the MST if they don't create a cycle. A union-find (disjoint set) data structure efficiently detects cycles.

## Time and Space Complexity

- Time Complexity: O(E log E + E α(V)), where E is the number of edges and α is the inverse Ackermann function.
- Space Complexity: O(V + E), for the graph and union-find structure.

## Algorithm

```py
def kruskal(edges, n):
    sort edges by weight
    parent = array where parent[i] = i
    mst = empty list
    totalWeight = 0
    
    for each edge (u, v, weight):
        if find(u) != find(v):
            union(u, v)
            mst.add(edge)
            totalWeight += weight
    
    return mst, totalWeight
```



## Implementation

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compareEdge(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[100];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py)
        parent[px] = py;
}

int kruskal(Edge edges[], int n, int v) {
    sort(edges, edges + n, compareEdge);
    
    for (int i = 0; i < v; i++)
        parent[i] = i;
    
    int totalWeight = 0;
    cout << "Edges in MST:" << endl;
    
    for (int i = 0; i < n; i++) {
        int pu = find(edges[i].u);
        int pv = find(edges[i].v);
        
        if (pu != pv) {
            unite(edges[i].u, edges[i].v);
            totalWeight += edges[i].weight;
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].weight << endl;
        }
    }
    return totalWeight;
}

int main() {
    Edge edges[] = {
        {0, 1, 4},
        {0, 2, 2},
        {1, 2, 1},
        {1, 3, 2},
        {2, 3, 3}
    };
    int n = 5;
    int v = 4;
    
    cout << "Total weight: " << kruskal(edges, n, v) << endl;
    return 0;
}
```

## Output

```sh
Edges in MST:
1 - 2 : 1
0 - 2 : 2
1 - 3 : 2
Total weight: 5
```

# Prim's Minimum Spanning Tree Algorithm

## Objective

To implement Prim's algorithm for finding the minimum spanning tree by starting from an arbitrary vertex and growing the tree.

## Theory

Prim's algorithm starts from a vertex and repeatedly adds the minimum weight edge that connects a vertex in the MST to a vertex outside it, without creating cycles.

## Time and Space Complexity

- Time Complexity: O(V²) with adjacency matrix, O((V + E) log V) with priority queue.
- Space Complexity: O(V²), for the adjacency matrix.

## Algorithm

```py
def prim(graph, n):
    inMST = array of false values
    key = array of infinity
    parent = array to track MST
    
    key[0] = 0
    for count = 0 to n-1:
        u = vertex with minimum key not in MST
        inMST[u] = true
        
        for each neighbor v of u:
            if not inMST[v] and weight(u,v) < key[v]:
                key[v] = weight(u,v)
                parent[v] = u
```



## Implementation

```cpp
#include <iostream>
#include <climits>
using namespace std;

#define V 5

int findMinKey(int key[], bool inMST[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void prim(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool inMST[V] = {false};
    
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX;
    
    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < V - 1; count++) {
        int u = findMinKey(key, inMST);
        inMST[u] = true;
        
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    cout << "Edge   Weight" << endl;
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "   " << graph[i][parent[i]] << endl;
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    prim(graph);
    return 0;
}
```

## Output

```sh
Edge   Weight
0 - 1   2
1 - 2   3
0 - 3   6
1 - 4   5
```

# Longest Common Subsequence Algorithm

## Objective

To implement the longest common subsequence (LCS) algorithm using dynamic programming to find the longest subsequence common to two sequences.

## Theory

LCS is solved using dynamic programming where dp[i][j] represents the length of LCS of the first i characters of string A and first j characters of string B.

## Time and Space Complexity

- Time Complexity: O(m × n), where m and n are lengths of the two strings.
- Space Complexity: O(m × n), for the DP table.

## Algorithm

```py
def lcs(str1, str2, m, n):
    dp = 2D array of size (m+1) x (n+1)
    
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            else if str1[i-1] == str2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    return dp[m][n]
```



## Implementation

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    
    int dp[m + 1][n + 1];
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    
    cout << "Length of LCS: " << lcs(str1, str2) << endl;
    return 0;
}
```

## Output

```sh
Length of LCS: 5
```

# Coin Related Problems

## Objective

To implement algorithms for coin change problems: minimum coins needed for a given amount and counting the number of ways to make a given amount.

## Theory

Both variants use dynamic programming. For minimum coins: dp[i] represents the minimum coins needed for amount i. For counting ways: dp[i] represents the number of ways to make amount i.

## Time and Space Complexity

- Time Complexity: O(n·m), where n is the number of coin denominations and m is the amount.
- Space Complexity: O(m), for the DP array.

## Algorithm

```py
def minCoins(coins, amount):
    dp = array of size amount+1, initialized to infinity
    dp[0] = 0
    
    for i in range(1, amount+1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i-coin] + 1)
    
    return dp[amount]

def countWays(coins, amount):
    dp = array of size amount+1, initialized to 0
    dp[0] = 1
    
    for coin in coins:
        for i in range(coin, amount+1):
            dp[i] += dp[i-coin]
    
    return dp[amount]
```



## Implementation

```cpp
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int minCoins(int coins[], int n, int amount) {
    int dp[amount + 1];
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++)
        dp[i] = INT_MAX;
    
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int countWays(int coins[], int n, int amount) {
    int dp[amount + 1] = {0};
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    
    return dp[amount];
}

int main() {
    int coins[] = {1, 2, 5};
    int n = 3;
    int amount = 5;
    
    cout << "Minimum coins needed: " << minCoins(coins, n, amount) << endl;
    cout << "Number of ways: " << countWays(coins, n, amount) << endl;
    return 0;
}
```

## Output

```sh
Minimum coins needed: 1
Number of ways: 5
```

# Maximum and Minimum using Divide and Conquer

## Objective

To implement an algorithm that finds both the maximum and minimum elements in an array using the divide and conquer approach.

## Theory

The divide and conquer approach recursively divides the array into halves, finds max/min in each half, and then compares the results. This is more efficient than linear search in terms of comparisons.

## Time and Space Complexity

- Time Complexity: O(n), but with fewer comparisons than linear search.
- Space Complexity: O(log n), due to recursion stack.

## Algorithm

```py
def findMinMax(arr, low, high):
    if low == high:
        return (arr[low], arr[low])
    
    if high == low + 1:
        if arr[low] < arr[high]:
            return (arr[low], arr[high])
        else:
            return (arr[high], arr[low])
    
    mid = (low + high) / 2
    leftMin, leftMax = findMinMax(arr, low, mid)
    rightMin, rightMax = findMinMax(arr, mid+1, high)
    
    return (min(leftMin, rightMin), max(leftMax, rightMax))
```



## Implementation

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

struct MinMax {
    int min;
    int max;
};

MinMax findMinMax(int arr[], int low, int high) {
    MinMax result;
    
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }
    
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }
    
    int mid = (low + high) / 2;
    MinMax left = findMinMax(arr, low, mid);
    MinMax right = findMinMax(arr, mid + 1, high);
    
    result.min = min(left.min, right.min);
    result.max = max(left.max, right.max);
    
    return result;
}

int main() {
    int arr[] = {12, 4, 8, 2, 9, 15, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    MinMax result = findMinMax(arr, 0, n - 1);
    
    cout << "Minimum: " << result.min << endl;
    cout << "Maximum: " << result.max << endl;
    return 0;
}
```

## Output

```sh
Minimum: 2
Maximum: 15
```
