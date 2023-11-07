//
// Created by michael on 24.10.23.
//
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void test1(){
    //1
    fork();
    //2
    fork();
    //4

    if(fork() == 0) // 8
        fork(); // 12
    fork(); // 24
    printf("%d\n", getpid());

   wait(NULL);
}

void test2(){

        int pid1 = -1, pid2 = -1, pid3 = -1, pid4 = -1, pid5 = -1;
        pid1 = fork();

    if (pid1 == 0){
        pid2 = getpid();
        pid3 = getppid();
    }
    pid4 = getpid();
    printf("pid 1: %d \n pid 2: %d \n pid 3: %d \n pid 4: %d \n", pid1, pid2, pid3, pid4);
    pid5 = wait(NULL);
    printf("pid 5: %d \n ", pid5);


}



int main(){
    test1();

}