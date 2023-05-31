#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h> //for rand()
#define BUFFSIZE 5
#define NITEMS 7 // Maximum number of items that can be produced or consumed in a given limited run
int buffer[BUFFSIZE];
int in = 0;
int out = 0;
int counter = 0;
sem_t mayproduce; // producer semaphore
sem_t mayconsume; // consumer semaphore
sem_t cmutex;     // for counter
void *Producer()
{
    int i, item;
    for (i = 0; i < NITEMS; i++)
    {
        sem_wait(&mayproduce); // wait() is successfull if buffer is not full
                               // random number between 1 and 100 are generated to simulate producer
        item = rand() % 100 + 1;
        buffer[in] = item; // add random number to buffer
        // use counter variable in mutually exclusive manner
        sem_wait(&cmutex); // wait()
        counter++;
        sem_post(&cmutex); // signal()
        printf("\nProducing %d ...at buffer[%d]", item, in);
        in = (in + 1) % BUFFSIZE;
        if (counter == BUFFSIZE) // buffer full
            printf("\n[Buffer full: in=%d\tout=%d, Producer waiting...", in, out);
        sem_post(&mayconsume); // signal consumer about availability of the item in buffer
    }
}
void *Consumer()
{
    int i, item;
    for (i = 0; i < NITEMS; i++)
    {
        sem_wait(&mayconsume); // wait() is successfull if buffer is not empty
        item = buffer[out];

        // use counter variable in mutually exclusive manner
        sem_wait(&cmutex);
        counter--;
        sem_post(&cmutex);
        printf("\nConsuming %d ...at buffer[%d]", item, out);
        out = (out + 1) % BUFFSIZE;
        if (counter == 0) // buffer empty

            printf("\n[Buffer empty]: in=%d\tout=%d, consumer waiting...", in, out);
        sem_post(&mayproduce); // signal producer about availability of space to produce items
    }
}
int main()
{
    // define thread identifiers for producer and consumer repectively
    // as producer and consumer are implemented as threads, they can run concurrently, ...
        // whenever they receive mayproduce and mayconsume signals
        pthread_t ptid,
        ctid;
    // initialize the semaphores
    sem_init(&mayproduce, 0, BUFFSIZE);
    // mayproduce initialised to BUFFSIZE, hence the first thread to run will be the producer
        sem_init(&mayconsume, 0, 0);
    // second argument 0 indiactes that the semaphore is shared among threads of the process
        sem_init(&cmutex, 0, 1);
    // third argument intialsed to 1, so that producer can increment count
    // creating producer and consumer threads; exit if thread creation fails
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
    // wait for the producer to finish
    if (pthread_join(ptid, NULL))
    {
        printf("\n ERROR joining thread");
        exit(1);
    }

    // wait for consumer to finish
    if (pthread_join(ctid, NULL))
    {
        printf("\n ERROR joining thread");
        exit(1);
    }
    return 0;
}