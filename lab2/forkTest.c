//
// Created by michael on 17.10.23.
//
#include<stdio.h>
#include <unistd.h>

int main(){
    printf("Poczatek\n");
    //fork(); // klonuje proces , to clone z parametram
    execlp("lt", "ls", "-a", NULL); // jezeli skuteczny, to zasteujemy nasz program obecny
    perror("exec");
    printf("Koniec\n");
}


