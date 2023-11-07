#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#define MAX 10

int get_desc_in(char* arg){
    int file = open(arg, O_RDONLY);
    if (file == -1){
        perror("Blad otwarcia pliku zrodlowego");
        exit(1);
        }
    return file;
}

int get_desc_out(char *arg){
    int file = creat(arg, 0640);
    if (file == -1){
        perror("Blad utworzenia pliku docelowego");
        exit(1);
    }
    return file;
}




void reverse_file(int in, int out){
    char buf[MAX];

    printf("\n\n file has %ld bajts\n\n\n", lseek(in, 0, SEEK_END));

    int bit = lseek(in, -MAX, SEEK_END);
    printf("bit: %d\n", bit);

    int bitRead = 0;

    do{
        printf("\n next iter %d \n", bit);
        bitRead = read(in, buf,MAX);
        printf("\n bit readed: %d\n", bitRead);

        bit = lseek(in, -MAX * 2, SEEK_CUR);
        /*
        printf("bit after lseek: %d\n", bit);

        printf("buf in : %s\n", buf);
        */
        reverse_string(bitRead, buf);
        /*
        printf("buf out: %s\n", buf);

        printf("bit after lseek: %ld\n", lseek(in, 0, SEEK_CUR));
        */
        write(out, buf, bitRead);

        sleep(1);

    } while(bitRead == MAX);




    printf("\n end of while \n");
    bitRead = read(in, buf,MAX);

    write(out, buf, bitRead);
    int cat = fork();
    
}




int main(int argc, char* argv[]){
    char buf[MAX];
    int file_out, file_in;
    int lbajt;
    int p1 = fork();
    if(p1 == 0){
        execl("clear", "clear", NULL);
    }
    wait(NULL);

    if (argc<3){
        argv[1] = "start.txt";
        argv[2] = "reversed.txt";
        //fprintf(stderr, "Uzyto argumentow domyslnych");
    }

    file_in = get_desc_in(argv[1]);
    file_out = get_desc_out(argv[2]);



    //test

    reverse_file(file_in, file_out);


    exit(0);
}
