#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//the function we will be assigning to a thread
void *ThreadFunc(void *args)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("this is runned in a thread .... %d\n", i);
    }
    return 0;
}

int main()
{

    pthread_t myThread; //the place where we will store the Id of the thread

    void *thread_result;

    pthread_create(&myThread, NULL, ThreadFunc, NULL); // creating thread and assigning the function.

    sleep(1);

    return 0;
}