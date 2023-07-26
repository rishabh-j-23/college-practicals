#include <stdio.h>
#define MAXTRACE 20 // Expt. 9 Program for FIFO page replacement algorithm int
int main()
{
    int page_faults = 0, m, n, s, pages, frames, pf, k = 0;
    pages = 10;
    int reference_string[10] = {20, 10, 30, 50, 40, 70, 90, 34, 89, 93};
    frames = 4;
    int temp[frames];
    for (m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }
    for (pf = 0; pf < frames; pf++)
        printf("PF#%-2d\t", pf + 1);
    for (m = 0; m < pages; m++)
    {
        s = 0;
        for (n = 0; n < frames; n++)
        {
            if (reference_string[m] == temp[n])
            {
                s++;
                page_faults--;
            }
        }
        page_faults++;
        if ((page_faults <= frames) && (s == 0))
        {
            temp[k++] = reference_string[m];
        }
        else if (s == 0)
        {
            temp[(page_faults - 1) % frames] = reference_string[m];
        }
        printf("\n");
        for (n = 0; n < frames; n++)
        {
            printf("%d\t", temp[n]);
        }
    }
    printf("\nTotal Page Faults:\t%d\n", page_faults);
    return 0;
}