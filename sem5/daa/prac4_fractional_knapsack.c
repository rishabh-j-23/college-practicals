#include <stdio.h>
#include <time.h>

int n = 4;
double ms;

double run_time(clock_t start, clock_t end)
{

    double ms = (double)(end - start);
    printf("%d %d\n", end, start);
    ms = ms / (double)CLK_TCK;

    return ms;
}

void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(double *p, double *w, double *ratio)
{

    int i, j;
    int n = 4;

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {

                swap(&p[j], &p[j + 1]);

                swap(&w[j], &w[j + 1]);
                swap(&ratio[j], &ratio[j + 1]);
            }
        }
    }
}

double fractional_knapsack(double *p, double *w, double *ratio)
{
    bubblesort(p, w, ratio);
    int n = 4;
    double wt = 0, profit = 0;
    int i;
    double capacity = 120;

    for (i = 0; i < n; i++)
    {
        if (wt + w[i] <= capacity)
        {
            wt = w[i] + wt;
            profit = profit + p[i];
        }
        else
        {

            double remaining = capacity - wt;
            profit = profit + remaining * ratio[i];
            break;
        }
    }

    return profit;
}

void main()
{
    double profit[4] = {40, 20, 35, 50};
    double weight[4] = {25, 30, 40, 45};

    double profitToWeight[4] = {1.6, 0.66, 0.875, 1.11};

    clock_t start, end;
    
    start = clock();
    double p = fractional_knapsack(profit, weight, profitToWeight);
    end = clock();
    ms = run_time(start, end);

    printf("\nMax profit : %.3f \n", p);
    printf("start time : %d \nend time : %d", start, end);
    printf("\ntime : %f", ms);
}