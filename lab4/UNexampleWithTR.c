//
// Created by michael on 07.11.23.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]) {
    int pdesk[2];

    if (pipe(pdesk) == -1){
        perror("Tworzenie potoku");
        exit(1);
    }

    switch(fork()){
        case -1: // blad w tworzeniu procesu
            perror("Tworzenie procesu");
            exit(1);
        case 0: // proces potomny
            dup2(pdesk[1], 1);
            close(pdesk[1]); //higiena
            close(pdesk[0]);
            execvp("ls", argv);
            perror("Uruchomienie programu ls");
            exit(1);
        default: { // proces macierzysty
            close(pdesk[1]);
            dup2(pdesk[0], 0);
            close(pdesk[0]); //dla higieny)
            //wait(0);
            execlp("tr", "tr", "a-z", "A-Z", 0, NULL);
            perror("Uruchomienie programu tr");
            exit(1);
        }
    }
}