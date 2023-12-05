#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/msg.h>



int main() {
    printf("Hello, World!\n");


    int id = shmget(0x155119, sizeof(int), IPC_CREAT|0600);
    //semget(0x155119, 5, IPC_CREAT|0600);
    //msgget(0x155119, IPC_CREAT|0600);
    int pid = fork();

    srand(getpid());


    int *ptr;
    ptr = shmat(id, NULL, 0);

    for(int i = 1; i <= 100; i++){
        if(pid == 0){
            //usleep(1000 + rand()%10 * 1000);
            while(*ptr != 0);
            *ptr = i;
        }
        else{
            while(*ptr == 0);

            printf("%d val: %d\n",i, *ptr);
            *ptr = 0;

        }
    }


    return 0;
}
