#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{

    int fd = -1;          //file discripter : what the associated no with the file; so the kernel can handle the file
    char buffer[2] = {0}; //
    int ret = 0;

    if (argc != 2) //error if a argument is not passed when executing the program.
    {
        printf("Please provide the filename as argument to read\n");
        return -1;
    }

    fd = open("./sim_input.txt", O_RDONLY);

    if (fd == -1)
    {
        printf("Error in opening the file error=%s\n", strerror(errno));
        return -1;
    }

    //after opening the file....

    //reading using API read.
    /*
    read API:
    1. file descripter : which we open the file (string of data )
    2. buffer that we created 
    3. size of buffer

    read ()  will return the amount of bytes which it has read,
    when it is =0 that means the file is in the end.
    error = -1
    so when reading a file it always returns a value >0 
    */
    while (ret = read(fd, buffer, sizeof(buffer)) > 0)
    {
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    close(fd);

    return 0;
}