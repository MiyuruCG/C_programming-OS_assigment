#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void sig_handler(int signum)
{
    printf("Alarm delivered signnum is %d\n", signum);
    exit(0);
}

int main()
{
    alarm(5);
    signal(SIGALRM, sig_handler);

    for (;;) //infinite loop
    {
        sleep(1);
    }

    return 0;
}