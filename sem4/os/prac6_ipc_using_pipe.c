#include <unistd.h>
#include <string.h>
#include <stdio.h>
#define BUFSIZE 100
#define READ_END 0
#define WRITE_END 1

int main()
{
    int pd[2]; // two pipe descriptors:pd[0] for reading and pd[1] for writing
    char buffer[BUFSIZE + 1];
    int returnstatus;
    returnstatus = pipe(pd);

    if (returnstatus == -1)
    {
        printf("Unable to create pipe\n");
        return 1;
    }

    pid_t fork_result;
    fork_result = fork();

    if (fork_result == 0)
    { // child process receives data from parent
        read(pd[READ_END], buffer, BUFSIZE);
        printf("\nChild Received: %s from the parent.\n", buffer);
        close(pd[READ_END]);
    }

    else
    { // parent process pass string to child
        char some_data[10];
        printf("\nEnter some data to be passed to child process:");
        gets(some_data);
        write(pd[WRITE_END], some_data, strlen(some_data));
        close(pd[WRITE_END]);
    }
    return 0;
}