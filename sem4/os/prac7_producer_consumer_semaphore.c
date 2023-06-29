#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#define BUFFSIZE 5
#define NITEMS 7
int buffer[BUFFSIZE];
int in = 0;
int out = 0;
int counter = 0;
sem_t mayproduce;
sem_t mayconsume;
sem_t cmutex;
void *Producer()
{
    int i, item;
    for (i = 0; i < NITEMS; i++)
    {
        sem_wait(&mayproduce);
        item = rand() % 100 + 1;
        buffer[in] = item;
        sem_wait(&cmutex);
        counter++;
        sem_post(&cmutex);
        printf("\nProducing %d ...at buffer[%d]", item, in);
        in = (in + 1) % BUFFSIZE;
        if (counter == BUFFSIZE)
            printf("\n[Buffer full: in=%d\tout=%d, Producer waiting...", in, out);
        sem_post(&mayconsume);
    }
}
void *Consumer()
{
    int i, item;
    for (i = 0; i < NITEMS; i++)
    {
        sem_wait(&mayconsume);
        item = buffer[out];

        sem_wait(&cmutex);
        counter--;
        sem_post(&cmutex);
        printf("\nConsuming %d ...at buffer[%d]", item, out);
        out = (out + 1) % BUFFSIZE;
        if (counter == 0)

            printf("\n[Buffer empty]: in=%d\tout=%d, consumer waiting...", in, out);
            
        sem_post(&mayproduce);
    }
}
int main()
{
    pthread_t ptid,
        ctid;

    sem_init(&mayproduce, 0, BUFFSIZE);

    sem_init(&mayconsume, 0, 0);

    sem_init(&cmutex, 0, 1);

    if (pthread_create(&ptid, NULL, Producer, NULL))
    {
        printf("\n ERROR creating Producer thread...");
        exit(1);
    }
    if (pthread_create(&ctid, NULL, Consumer, NULL))
    {
        printf("\n ERROR creating Consumer thread...");
        exit(1);
    }

    if (pthread_join(ptid, NULL))
    {
        printf("\n ERROR joining thread");
        exit(1);
    }

    if (pthread_join(ctid, NULL))
    {
        printf("\n ERROR joining thread");
        exit(1);
    }
    return 0;
}