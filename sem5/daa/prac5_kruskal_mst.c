#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int);
int uni(int, int);

double run_time(clock_t start, clock_t end)
{

    double ms = (double)(end - start);
    ms = ms / (double)CLK_TCK;

    return ms;
}

int main() {
    clock_t start, end;

    printf("Kruskal's algorithm in C\n");
    printf("========================\n");

    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    start = clock();
    printf("The edges of Minimum Cost Spanning Tree are:\n");
    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("%d edge(%d, %d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    end = clock();
    double ms = run_time(start, end);

    printf("\nMinimum cost = %d\n", mincost);
    printf("\ntime : %f", ms);
    return 0;
}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }

    return 0;
}
