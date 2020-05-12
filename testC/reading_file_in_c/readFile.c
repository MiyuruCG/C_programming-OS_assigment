#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fp;          //file pointer
    char *line = NULL; //
    size_t len = 0;    // platform dependent
    ssize_t read;      // platform dependent

    fp = fopen("./ex.txt", "r"); // file path   &&   the permision to read only

    if (fp == NULL) //if theres an error
    {
        printf("error reading file... ");
        return -1;
    }

    while ((read = getline(&line, &len, fp)) != -1) // reading the data of the file line by line; read = -1 : end of file
    {
        printf("%zu  :\t", read); //= return val of getline() :: no of characters in the line
        printf("%s ", line);      // line : gets the actual data of the line
    }

    if (line)
    {
        free(line);
    }

    fclose(fp);

    return 0;
}