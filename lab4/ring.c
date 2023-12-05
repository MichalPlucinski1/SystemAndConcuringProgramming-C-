//
// Created by michael on 21.11.23.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){

    // statyczne i stale
    int pdesk[2];
    pdesk[0]= open("/tmp/in", O_RDONLY);
    pdesk[1] = open("/tmp/out", O_WRONLY);

    // glowna pętla
    while(1){

        char buf[10];
        long bufSize;


        // odczyt test
        if (pdesk[0] == -1){
            perror("blad: otwarcia potoku do odczytu");
            exit(1);
        }

        //odczyt z desk
        if ((bufSize = read(pdesk[0], buf, 10) )== -1){
            perror("blad: Odczyt z potoku");
            exit(1);
        }
        printf("Odczytano z potoku: %s\n", buf);



        // zapis test

        if (pdesk[1] == -1){
            perror("Blad otwarcia potoku do zapisu");
            exit(1);
        }

        //zapis z desk
        if (write(pdesk[1], buf, bufSize) == -1){
            perror("blad zapisu do potoku");
            exit(1);
        }
        printf("iteracja przebiegla pomyslnie");


    }


    return 0;
}