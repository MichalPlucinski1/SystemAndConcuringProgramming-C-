//
// Created by michael on 07.11.23.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pdesk[2];

    if (pipe(pdesk) == -1){
        perror("Tworzenie potoku");
        exit(1);
    }

    switch(fork()){
        case -1:    // blad w tworzeniu procesu
            perror("Tworzenie procesu");
            exit(1);
        case 0:     // proces potomny
            if (write(pdesk[1], "Hallo!", 7) == -1){
                perror("Zapis do potoku");
                exit(1);
            }
            //usleep(100);

            if (write(pdesk[1], "Hallo!", 7) == -1){
                perror("Zapis do potoku");
                exit(1);
            }

            exit(0);
        default: {  // proces macierzysty

            close(pdesk[1]);
            char buf[10];
            int r = 0;
            if ((r = read(pdesk[0], buf, 10) )== -1){
                perror("Odczyt z potoku");
                exit(1);
            }
            printf("Odczytano z potoku %d danych: %s\n",r, buf);
            if ((r = read(pdesk[0], buf, 10)) == -1){
                perror("Odczyt z potoku 2");

                exit(1);
            }
            printf("Odczytano z potoku %d danych: %s\n",r, buf);
        }
    }
}