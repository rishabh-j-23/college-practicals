#include <stdio.h>
#include <time.h>
static int m = 5, n = 5;
static int c = 0;
static int count = 0;

int graph[5][5] = {
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };
int x[50];

void nextValue(int k);
void GraphColoring(int k);

double run_time(clock_t start, clock_t end){
    double ms = (double)(end - start);
    ms = ms / (double)CLK_TCK;
    return ms;
}

void main()
{
    int i, j;
    int temp;

    // printf("\nEnter the number of nodes : ");
    // scanf(" % d ", &n);

    // printf("\nIf edge exists then enter 1 else enter 0 \n");
    // for (i = 1; i <= n; i++)
    // {
    //     x[i] = 0;
    //     for (j = 1; j <= n; j++)
    //     {
    //         if (i == j)
    //             graph[i][j] = 0;
    //         else
    //         {
    //             printf("%d -> %d: ", i, j);
    //             scanf("%d", &temp);
    //             graph[i][j] = graph[j][i] = temp;

    //         }
    //     }
    // }

    // printf("\nEnter Adjacency Matrix : \n ");
    // for (i = 1;i <= n;i++)
    // {
    //     for (j = 1;j <= n;j++)
    //     {
    //         scanf(" % d ", &graph[i][j]);
    //     }
    // }

    clock_t start, end;

    printf("\nPossible Solutions are\n ");
    start = clock();
    for (m = 1;m <= n;m++)
    {
        if (c == 1)
        {
            break;
        }
        GraphColoring(1);
    }
    end = clock();

    printf("\nThe chromatic number is % d ", m - 1);
    printf("\nThe total number of solutions is % d ", count);
    printf("\ntime: %f", run_time(start, end));

}
void GraphColoring(int k)
{
    int i;
    while (1)
    {
        nextValue(k);
        if (x[k] == 0)
        {
            return;
        }
        if (k == n)
        {
            c = 1;
            for (i = 1;i <= n;i++)
            {
                printf(" % d ", x[i]);
            }
            count++;
            printf("\n ");
        }
        else

            GraphColoring(k + 1);
    }
}

void nextValue(int k)
{
    int j;
    while (1)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
        {
            return;
        }
        for (j = 1;j <= n;j++)
        {
            if (graph[k][j] == 1 && x[k] == x[j])
                break;
        }
        if (j == (n + 1))
        {
            return;
        }
    }
}