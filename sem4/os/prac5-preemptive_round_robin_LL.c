//Round Robin algorithm

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct processblock process_block;

struct processblock{
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    process_block *next;
};

process_block *head = NULL, *last;

int ini_num_processes = 0;

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

int process_count = 0;
void add_process_block_at_end(int at, int bt){
    process_block *newprocess_block = (process_block *)malloc(sizeof(process_block));
    newprocess_block->arrival_time = at;
    newprocess_block->burst_time = bt;
    if (head == NULL)
    {
        head = newprocess_block;
        head->next = NULL;
        last = head;
        head->process_id = process_count++;;
    }
    else
    {
        last->next = newprocess_block;
        last = newprocess_block;
        newprocess_block->next = NULL;
        newprocess_block->process_id = process_count++;
    }
}

void add_updated_process_block_at_end(process_block **pb, int burst_time){
    process_block *p = *pb;
    process_block *process = p; 
    process_block *newprocess_block = (process_block *)malloc(sizeof(process_block));
    newprocess_block->arrival_time = process->arrival_time;
    newprocess_block->burst_time = burst_time;
    if (head == NULL)
    {
        head = newprocess_block;
        head->next = NULL;
        last = head;
        head->process_id = process->process_id;
    }
    else
    {
        last->next = newprocess_block;
        last = newprocess_block;
        newprocess_block->next = NULL;
        newprocess_block->process_id = process->process_id;
    }
}


void traverse(){
    
    int p = 0;
    process_block *i = head;
    printf("Initial Number of Processes : %d\n", ini_num_processes);

    printf("Process\t\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    while (i != NULL)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i->process_id, i->arrival_time, i->burst_time, i->completion_time, i->turn_around_time, i->waiting_time);
        i = i->next;
    }
    printf("\n");
}

void round_robin(process_block **pb, int time_quantum){
    process_block *p = *pb;
    process_block *process = p;

    double average_waiting_time = 0, average_turn_around_time = 0;
    int current_time = 0;

    int num_processes = size();

    while (process != NULL) {
        // TODO : Apply round robin time quantum calculations
        if (process->burst_time <= time_quantum){
            current_time = process->completion_time = current_time + process->burst_time;

        } else if (process->burst_time > time_quantum){ 
            int complement = process->burst_time - time_quantum;
            current_time = process->completion_time = current_time + time_quantum;
            add_updated_process_block_at_end(&process, complement);
        }

        if(process->burst_time <= time_quantum){
            process->turn_around_time = process->completion_time - process->arrival_time;
            process->waiting_time = process->turn_around_time - process->burst_time;
            average_waiting_time = average_waiting_time + process->waiting_time;
            average_turn_around_time = average_turn_around_time + process->turn_around_time;
        }

        process = process->next;
    }

    traverse();
    
    average_turn_around_time = average_turn_around_time/ num_processes;
    average_waiting_time = average_waiting_time / num_processes;

    printf("Average Waiting Time : %.3f\n", average_waiting_time);
    printf("Average Turnaround Time : %.3f\n", average_turn_around_time);
}

int main(){

    printf("Algorithm : Round Robin\n");
    add_process_block_at_end(0, 24);
    add_process_block_at_end(0, 3);
    add_process_block_at_end(0, 3);

    ini_num_processes = size();

    round_robin(&head, 4);
    return 0;
}