#include <stdio.h>
#include <limits.h>
#define N 7  
char nodes[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
int cost[N][N] = {
    {0, 1, 3, 0, 0, 0, 0},
    {0, 0, 0, 4, 2, 0, 0},
    {0, 0, 0, 0, 6, 0, 0},
    {0, 0, 0, 0, 0, 5, 1},
    {0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0}
};

// Estimated heuristic values 
int heuristic[N] = {6, 4, 7, 2, 3, 1, 0};
void branchBoundEH(int start, int goal) {
    int visited[N] = {0};
    int path[N], pathIndex = 0;
    int totalCost = 0;
    int current = start;
    printf("Branch and Bound + Estimated Heuristics Search:\n");
    while (current != goal) {
        visited[current] = 1;
        path[pathIndex++] = current;
        int bestNode = -1;
        int bestValue = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (cost[current][i] > 0 && !visited[i]) {
                int value = cost[current][i] + heuristic[i];
                if (value < bestValue) {
                    bestValue = value;
                    bestNode = i;
                }
            }
        }

        if (bestNode == -1) {
            printf("No path found!\n");
            return;
        }
        totalCost += cost[current][bestNode];
        current = bestNode;
    }
    path[pathIndex++] = goal;
    printf("Path: ");
    for (int i = 0; i < pathIndex; i++) {
        printf("%c", nodes[path[i]]);
        if (i != pathIndex - 1) printf(" -> ");
    }
    printf("\nTotal Cost: %d\n", totalCost);
}
int main() {
    int start = 0; // A
    int goal = 6;  // G
    branchBoundEH(start, goal);
    return 0;
}
