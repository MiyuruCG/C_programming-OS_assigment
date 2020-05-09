#include <stdio.h>
#include <unistd.h>

int main(void)
{

    pid_t pid;

    if ((pid = fork()) > 0)
    {
        printf("\n");
        printf("this is the parent ... \n");
        printf("child process id = %d\n", pid);
        printf("\n");
    }
    else
    {
        printf("\n");
        printf("this is the child process....\n");
        printf("parent process id = %d\n", getpid());
        printf("\n");
    }

    return 0;
}