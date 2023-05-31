// Expt. no. 10
// Banker's  safety algorithm.

#include <stdio.h>
#define n 5 // number of processess
#define m 3 // number of resource types
#define true 1
#define false 0
typedef int boolean;

int main(){

    int i, j, k, l;

    boolean temp;
    int safe_seq[n] = {-1, -1, -1, -1, -1};
    boolean finish[5] = {false, false, false, false, false}; // initially no process is finished
    int total[m] = {10, 5, 7};                               // total number of system resource types are three
    int max[n][m] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int alloc[n][m] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int available[m];
    int need[n][m];
    int work[m];
    int nf = 0; // number of finished processes
    int s[3];   // summation of allocation
    s[0] = s[1] = s[2] = 0;

    // calculations for available vector
    for (j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
            s[j] = s[j] + alloc[i][j];
        available[j] = total[j] - s[j];
    }
    // print available vector
    printf("\nThe available vector is :");
    for (j = 0; j < m; j++)
    {
        printf("%d\t", available[j]);
    }
    // calculations for need matrix
    for (i = 0; i < n; i++) // first find a process that can finish
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    // initialise work vector with available vector
    for (j = 0; j < m; j++)
        work[j] = available[j];
    boolean statechange = false;
    do
    {
        // Apply the Banker's Avoidance core logic
        for (i = 0; i < n; i++) // first find a process that can finish
        {
            temp = true; // assume that process can finish
            if (finish[i] == false)
            {
                for (j = 0; j < m; j++) // for each resource type
                {
                    if (need[i][j] > work[j])
                    {
                        statechange = false;
                        temp = false; // process can not finish
                        break;
                    }
                }
                if (temp) // if this process can finish
                {
                    statechange = true;
                    finish[i] = true;
                    printf("\nProcess finished =P%d", i);
                    safe_seq[nf++] = i;
                    for (l = 0; l < m; l++)
                        work[l] += alloc[i][l];
                }
            }
        } // end of core logic
        if (nf == n)
            statechange = false;
    } while (statechange); // if there is no process finished in the last cyle, stop

    // if all processes are finished, print the safe sequence safe_seq
    if (nf < n)
    {
        printf("\nNo process can finish safely further...");
        printf("\nNo safe sequence exist, hence the system is in unsafe state");
    }
    else // print the safe sequence
    {
        printf("\n\n The safe sequence is:\n");
        for (i = 0; i < n; i++)
            printf("\tP%d ", safe_seq[i]);
    }
}
