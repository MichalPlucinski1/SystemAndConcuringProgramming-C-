//
// Created by michael on 17.10.23.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>





int main(int argc, char* argv[])
{

    int d;
    d = creat("t1", O_WRONLY);



    ftruncate(d,1000000);


    int e = creat("t2", O_WRONLY);


    lseek(e, 1000000, SEEK_END);

    write(e, "1", 1);

    return 0;
}
