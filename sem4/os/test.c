#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFSIZE 5
#define NITEMS 7

int buffer[BUFFSIZE], in = 0, out = 0, counter = 0;

sem_t mayproduce;
sem_t mayconsume;
sem_t cmutex;

void* Producer(){
    int i, item;

    for(i = 0; i < NITEMS; i++){
        sem_wait(&mayproduce);
        item = i;
        buffer[in] = item;
        sem_wait(&cmutex);
        counter++;
        sem_post(&cmutex);

        printf("\nProducing %d -> \tBUFFER[%d]", item, in);

        if(counter == BUFFSIZE){
            printf("BUFFER FULL -> in: [%d], out: [%d]", in, out);
        }
    }
}

int main(){

    for(int i = 0; i < 7; i++){
        printf("%d ", (i) % 5);
    }
    return 0;
}