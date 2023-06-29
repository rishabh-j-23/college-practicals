
#include <stdio.h>
int main()
{
	int i, j, alloc[100], avail[100], min;
	int blockSize[4] = {100, 200, 150, 300}, nb = 4;
	int jobSize[5] = {100, 90, 200, 50, 400}, n = 5;

	for (i = 0; i < n; i++)
	{
		alloc[i] = -1;
	}
	for (i = 0; i < nb; i++)
	{
		avail[i] = 9999;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < nb; j++)
		{
			if (blockSize[j] > jobSize[i])
			{
				avail[j] = blockSize[j] - jobSize[i];
			}
		}
		min = 0;
		for (j = 0; j < nb; j++)
		{
			if (avail[min] > avail[j])
			{
				min = j;
			}
		}
		alloc[i] = min;
		if (avail[min] >= 9999)
		{
			alloc[i] = -1;
		}
		blockSize[min] = -1;

		for (j = 0; j < n; j++)
		{
			avail[j] = 9999;
		}
	}

	printf("Process P of {size} is allocated to block \n");
	for (i = 0; i < n; i++)
	{
		if (alloc[i] != -1)
			printf("Process %d of %d --> Block %d\n", i + 1, jobSize[i], alloc[i] + 1);
		else
			printf("Process %d of %d --> is not allocated \n", i + 1, jobSize[i]);
	}
}