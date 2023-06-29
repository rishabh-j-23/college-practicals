


#include <stdio.h>
#define n 5 
#define m 3 
#define true 1
#define false 0
typedef int boolean;

int main(){

    int i, j, k, l;

    boolean temp;
    int safe_seq[n] = {-1, -1, -1, -1, -1};
    boolean finish[5] = {false, false, false, false, false}; 
    int total[m] = {10, 5, 7};                               
    int max[n][m] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int alloc[n][m] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int available[m];
    int need[n][m];
    int work[m];
    int nf = 0; 
    int s[3];   
    s[0] = s[1] = s[2] = 0;

    
    for (j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
            s[j] = s[j] + alloc[i][j];
        available[j] = total[j] - s[j];
    }
    
    printf("\nThe available vector is :");
    for (j = 0; j < m; j++)
    {
        printf("%d\t", available[j]);
    }
    
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    
    for (j = 0; j < m; j++)
        work[j] = available[j];
    boolean statechange = false;
    do
    {
        
        for (i = 0; i < n; i++) 
        {
            temp = true; 
            if (finish[i] == false)
            {
                for (j = 0; j < m; j++) 
                {
                    if (need[i][j] > work[j])
                    {
                        statechange = false;
                        temp = false; 
                        break;
                    }
                }
                if (temp) 
                {
                    statechange = true;
                    finish[i] = true;
                    printf("\nProcess finished =P%d", i);
                    safe_seq[nf++] = i;
                    for (l = 0; l < m; l++)
                        work[l] += alloc[i][l];
                }
            }
        } 
        if (nf == n)
            statechange = false;
    } while (statechange); 

    
    if (nf < n)
    {
        printf("\nNo process can finish safely further...");
        printf("\nNo safe sequence exist, hence the system is in unsafe state");
    }
    else 
    {
        printf("\n\n The safe sequence is:\n");
        for (i = 0; i < n; i++)
            printf("\tP%d ", safe_seq[i]);
    }
}
