#include <stdio.h>
#define CAPACITY 12
#define OBJ_COUNT 5

int max(int a, int b)
{
    return a > b ? a : b;
}


int main() {
    int profits[OBJ_COUNT] = {12, 16, 19, 11, 24};
    int weights[OBJ_COUNT] = {3, 2, 5, 6, 1};

    int dp[OBJ_COUNT+1][CAPACITY+1];

    for (unsigned int obj = 0; obj <= OBJ_COUNT; obj++) {
        dp[obj][0] = 0;
    }
    for (unsigned int weight = 0; weight <= CAPACITY; weight++) {
        dp[0][weight] = 0;
    }

    for (unsigned int obj = 1; obj <= OBJ_COUNT; obj++) {
        for (unsigned int weight = 1; weight <= CAPACITY; weight++) {
            if (weight < weights[obj-1]) {
                dp[obj][weight] = dp[obj-1][weight];
            }
            else {
                dp[obj][weight] = max(dp[obj-1][weight], profits[obj-1] + dp[obj-1][weight-weights[obj-1]]);
            }
        }
    }

    int cap = CAPACITY;
    int profit = 0;
    for (int obj = OBJ_COUNT; obj > 0; obj--) {
        if (dp[obj][cap] != dp[obj-1][cap]) {
            // obj taken.
            printf("item-%d (profit=%d, weight=%d)\n", obj, profits[obj-1], weights[obj-1]);
            profit += profits[obj-1];
            cap -= weights[obj-1];
        }
    }

    printf("\nUsed capacity: %d\n", CAPACITY - cap);
    printf("Gained profits: %d\n", profit);
}
