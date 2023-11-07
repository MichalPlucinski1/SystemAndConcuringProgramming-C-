// C program to read nth byte of a file and
// copy it to another file using lseek
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX 10

void func(char arr[])
{
    // Open the file for READ only.
    int  f_read = open("start.txt", O_RDONLY);
    if ( f_read == -1 ) {
        perror("Blad otwarcia pliku start");
        exit (1);
    }

    // Open the file for WRITE and READ only.
    creat("end.txt", O_RDWR);
    int f_write = open("end.txt", O_WRONLY);
    if ( f_write == -1 ) {
        perror("Blad otwarcia pliku end");
        exit (1);
    }


    int count = 0;
    while (read(f_write, arr, 1))
    {
        printf()
        // to write the 1st byte of the input file in
        // the output file
        if (count < MAX)
        {
            // SEEK_CUR specifies that
            // the offset provided is relative to the
            // current file position
            lseek (f_write, MAX, SEEK_CUR);
            write (f_read, arr, 1);
            count = MAX;
        }

            // After the nth byte (now taking the alternate
            // nth byte)
        else
        {
            count = (2*MAX);
            lseek(f_write, count, SEEK_CUR);
            write(f_read, arr, 1);
        }
    }
    close(f_write);
    close(f_read);
    execl("cat","cat",  "./end.txt", NULL);
    perror("error while reading end");
}

// Driver code
int main(int argc, char* argv[])
{
    if(argc == 1){
        argc = 3;
        argv[1] = "start.txt";
        argv[2] = "end.txt";
    }


    for(int i = 0; i <argc; i++){
        printf("arg[%d] = %s  \n", i, argv[i]);
    }

    char arr[100];


    // Calling for the function
    func(arr);

    return 0;
}





