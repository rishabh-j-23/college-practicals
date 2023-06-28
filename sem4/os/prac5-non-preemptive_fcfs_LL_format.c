//FCFS algorithm
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct processblock process_block;
struct processblock{

    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    process_block *next;
};

process_block *head = NULL, *last;

int size(){
    process_block *i = head;
    int len = 0;
    while (i != NULL)
    {
        len++;
        i = i->next;
    }
    return len;
}

void add_process_block_at_end(int at, int bt){
    process_block *newprocess_block = (process_block *)malloc(sizeof(process_block));
    newprocess_block->arrival_time = at;
    newprocess_block->burst_time = bt;
    if (head == NULL)
    {
        head = newprocess_block;
        head->next = NULL;
        last = head;
    }
    else
    {
        last->next = newprocess_block;
        last = newprocess_block;
        newprocess_block->next = NULL;
    }
}

void traverse(){
    process_block *i = head;
    printf("Process\t\tArrival Time\tBurst Time\tTurnaround Time\tCompletion Time\tWaiting Time\n");
    int p = 0;
    while (i != NULL)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p, i->arrival_time, i->burst_time, i->turn_around_time, i->completion_time, i->waiting_time);
        i = i->next;
        p++;
    }
    printf("\n");
}

void first_come_first_serve(process_block **pb){
    process_block *p = *pb;
    process_block *process = p;
    double average_waiting_time = 0, average_turn_around_time = 0;

    int current_time = 0, ct = 0;

    while(process != NULL){
        current_time = process->completion_time = current_time + process->burst_time;

        process->turn_around_time = process->completion_time - process->arrival_time;
        process->waiting_time = process->turn_around_time - process->burst_time;

        average_waiting_time = average_waiting_time + process->waiting_time;
        average_turn_around_time = average_turn_around_time + process->turn_around_time;

        process = process->next;
    }

    traverse();

    int num_processes = size();

    average_turn_around_time = average_turn_around_time/ num_processes;
    average_waiting_time = average_waiting_time / num_processes;

    printf("Average Waiting Time : %.3f\n", average_waiting_time);
    printf("Average Turnaround Time : %.3f\n", average_turn_around_time);
}

int main(){

    printf("Algorithm : First Come First Serve\n");
    add_process_block_at_end(0, 24);
    add_process_block_at_end(0, 3);
    add_process_block_at_end(0, 3);

    printf("Initial Number of Processes : %d\n", size());
    first_come_first_serve(&head);
    
    return 0;
}