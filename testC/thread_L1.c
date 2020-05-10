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
        sleep(1);
    }
    return 0;
}

int main()
{

    pthread_t myThread; //the place where we will store the Id of the thread

    void *thread_result;

    pthread_create(&myThread, NULL, ThreadFunc, NULL); // creating thread and assigning the function.

    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        printf("parent .. %d\n", i);
    }

    //sleep(1); // the main thread will be executed before the child is finished... use sleep() or pthread_join().

    //best practice
    pthread_join(myThread, &thread_result); //this will block the main, so anythng after this wont run until the child thread has executed.
    return 0;
}