#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

/*
This program provides a possible solution for first readers writers problem using mutex and semaphore.
I have used 10 readers and 5 producers to demonstrate the solution. You can always play with these values.
*/

sem_t rw_mutex;
sem_t mutex;
int cnt = 1;
int read_count = 0;

void *writer(void *wno)
{   
    sem_wait(&rw_mutex);
    cnt = cnt*2;
    printf("Writer %d modified cnt to %d\n",(*((int *)wno)),cnt);
    sem_post(&rw_mutex);

}
void *reader(void *rno)
{   
    // Reader acquire the lock before modifying numreader
    sem_wait(&mutex);
    read_count++;
    if(read_count == 1) 
    {
        sem_wait(&rw_mutex); // If this id the first reader, then it will block the writer
    }
    sem_post(&mutex);
    
    // Reading Section
    printf("Reader %d: read cnt as %d\n",*((int *)rno),cnt);

    // Reader acquire the lock before modifying numreader
    sem_wait(&mutex);
    read_count--;
    if(read_count == 0)
    {
        sem_post(&rw_mutex); // If this is the last reader, it will wake up the writer.
    }
    sem_post(&mutex);
}

int main()
{   

    pthread_t read[10],write[5];
    sem_init(&mutex,0,1);
    sem_init(&rw_mutex,0,1);

    int a[10] = {1,2,3,4,5,6,7,8,9,10}; //Just used for numbering the producer and consumer

    for(int i = 0; i < 10; i++) {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }

    for(int i = 0; i < 10; i++) {
        pthread_join(read[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(write[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&rw_mutex);

    return 0;
    
}

