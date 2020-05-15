#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 10

int thread_routine(int x)
{
    printf("I am thread %2d my TID is %u\n", x, pthread_self());
    pthread_exit(0);
}

int main()
{
    pthread_attr_t thread_attr;
    pthread_t tids[NUM_THREADS];

    int x = 2431;

    pthread_attr_init(&thread_attr);

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&tids[i], &thread_attr, (void *)thread_routine, (void *)x);
        sleep(2);
    }

    printf("waiting for threads to finish...\n");

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tids[i], NULL);
    }

    printf("All threads are finished now...");

    return 0;
}