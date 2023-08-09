#include <stdio.h>

int min(int a, int b)
{
    return (a > b) ? b : a;
}

void print_result(int* timeslot, char* seq){
    
    int sum = 0;
    printf("\norder of jobs in which they are stored :-  ");
    for (int i = 0; i < 4; i++)
    {
        sum = sum + timeslot[i];

        printf("%c -->", seq[i]);
    }

    printf("\nmax profit = %d \n", sum);
}

void job_sequence(int *profit, int *deadline, char *job)
{
    int dmax = 0;
    for (int i = 0; i < 7; i++)
    {
        if (dmax < deadline[i])
        {
            dmax = deadline[i];
        }
    }

    char seq[4];
    int timeslot[4] = {-1, -1, -1, -1};
    for (int i = 0; i < 7; i++)
    {
        int k = min(deadline[i], dmax);
        while (k > 0)
        {
            if (timeslot[k - 1] == -1)
            {
                timeslot[k - 1] = profit[i];
                seq[k - 1] = job[i];
                break;
            }
            k = k - 1;
        }
    }
    print_result(timeslot, seq);
}

int main()
{

    int profit[] = {50, 40, 30, 25, 21, 18, 15};
    int deadline[] = {3, 4, 4, 2, 3, 1, 2};
    char jobs[] = {'1', '2', '3', '4', '5', '6', '7'};
    job_sequence(profit, deadline, jobs);

    return 0;
}
