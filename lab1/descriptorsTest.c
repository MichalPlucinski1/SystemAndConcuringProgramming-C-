#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX 10


int main(int argc, char* argv[]){

    int desc_zrod;
    int lbajt = 0;
    char buf[MAX];
    int desc_bit;

    desc_zrod = open("test.txt", O_RDONLY);
    if (desc_zrod == -1){
        perror("Blad otwarcia pliku zrodlowego");
        exit(1);
    }


    lbajt = lseek(desc_zrod, -11, SEEK_END);




    read(desc_zrod, buf, 10);
    printf("buf: %s\n", buf);

    lseek(desc_zrod, -20, SEEK_CUR);


    read(desc_zrod, buf, 10);
    printf("buf: %s\n", buf);



    exit (0);
}