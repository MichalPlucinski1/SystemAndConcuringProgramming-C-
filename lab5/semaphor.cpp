//
// Created by michael on 12.12.23.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define KEY1 0x155119
#define KEY2 0x155120

int main() {
    printf("Hello, World!\n");


    volatile int * ptr;

    int sem_id1 = semget(KEY1, 1, IPC_CREAT | 0666);
    int sem_id2 = semget(KEY2, 1, IPC_CREAT | 0666);

    if (sem_id1 == -1 || sem_id2 == -1) {
        perror("semget");
        exit(1);
    }

    union semun {
        int val;
        struct semid_ds *buf;
        ushort *array;
    } argument;

    argument.val = 1;
    if (semctl(sem_id1, 0, SETVAL, argument) == -1 || semctl(sem_id2, 0, SETVAL, argument) == -1) {
        perror("semctl");
        exit(1);
    }

    int pid = fork();

    srand(getpid());

    struct sembuf sem_op1, sem_op2;
    sem_op1.sem_flg = sem_op2.sem_flg = 0;

    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    for(int i = 0; i <=100; i++){


         if (pid == 0) {
            // Child Process (Writer)
            sem_op1.sem_num = 0;
            sem_op1.sem_op = -1; // Opuszczamy semafor sem1

            semop(sem_id1, &sem_op1, 1);
             *ptr = i;

            // Write Data
            printf("Child process: Writing %d\n", i);

            sem_op2.sem_num = 0;
            sem_op2.sem_op = 1; // Podnosimy semafor sem2
            semop(sem_id2, &sem_op2, 1);
        } else {
            // Parent Process (Reader)
            sem_op2.sem_num = 0;
            sem_op2.sem_op = -1; // Opuszczamy semafor sem2
            semop(sem_id2, &sem_op2, 1);

            // Read Data
            printf("Parent process: Reading %d\n", *ptr);
            sem_op1.sem_num = 0;
            sem_op1.sem_op = 1; // Podnosimy semafor sem1
            semop(sem_id1, &sem_op1, 1);
        }
    }

    semctl(sem_id1, 0, IPC_RMID); // Usunięcie semafora sem1
    semctl(sem_id2, 0, IPC_RMID); // Usunięcie semafora sem2

    return 0;
}
