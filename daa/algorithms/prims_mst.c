#include <stdio.h>
#include <stdbool.h>

#define DIM 5


int main()
{
    int graph[DIM][DIM] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int visited[DIM] = { false };
    int visited_node_count = 0;
    int totalDistance = 0;

    const int start = 0;
    int current_node = start;

    printf("Visited: ");

    while (visited_node_count < DIM) {
        visited[current_node] = true;
        visited_node_count += 1;
        if (current_node != start) {
            printf(", ");
        }
        printf("%d", current_node);

        int distance = __INT_MAX__;
        for (unsigned int i = 0; i < DIM; i++) {
            if (graph[current_node][i] != 0 && !visited[i] && graph[current_node][i] < distance) {
                distance = graph[current_node][i];
                current_node = i;
            }
        }
        if (distance != __INT_MAX__) {
            totalDistance += distance;
        }
    }

    printf("\nTotal distance: %d\n", totalDistance);

    return 0;
}
