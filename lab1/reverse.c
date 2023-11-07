#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define MAX 10


void reverse_string(int len, char str[]){
    for(int i = 0; i < len/2; i++){
        //answ[i] = str[len - 1 - i];
        char buf = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = buf;
    }
    //return *str;
}


int main(int argc, char* argv[]){
    char buf[MAX];
    int desc_zrod, desc_cel;
    int lbajt;

    if (argc<3){
        argv[1] = "test.txt";
        argv[2] = "reverseStart.txt";
        fprintf(stderr, "Za malo argumentow. Uzyj:\n");
        fprintf(stderr, "%s <plik zrodlowy> <plik docelowy>\n", argv[0]);
        //exit(1);
    }

    desc_zrod = open(argv[1], O_RDONLY);
    if (desc_zrod == -1){
        perror("Blad otwarcia pliku zrodlowego");
        exit(1);
    }

    desc_cel = creat(argv[2], 0640);
    if (desc_cel == -1){
        perror("Blad utworzenia pliku docelowego");
        exit(1);
    }

    int readSinceStart = lseek(desc_zrod, -1, SEEK_END);
    int curr = lseek(desc_zrod, MAX * -1, SEEK_CUR);
    int toRead = MAX;

    for(;readSinceStart > 0; readSinceStart -= lbajt) {

            printf("do odczytu: %d ", readSinceStart);
            lbajt = read(desc_zrod, buf, toRead);
            toRead = (curr < MAX?curr:MAX);

        curr = lseek(desc_zrod, -lbajt - toRead, SEEK_CUR);
        perror("");

        printf("\n curr: %d, to read: %d \nbuf: %s\n", curr, toRead, buf);


            /*for(int i = 0; i < lbajt; i++){
                printf();
            }*/
            //printf(" %d\n", lbajt);
            printf("\n \n");
            if (lbajt == -1){
                perror("Blad odczytu pliku zrodlowego");
                exit(1);
            }

        reverse_string(lbajt,buf);

            if (write(desc_cel, buf, lbajt) == -1) {
                perror("Blad zapisu pliku docelowego");
                exit(1);
            }
        }



    if (close(desc_zrod) == -1 || close(desc_cel) == -1){
        perror("Blad zamkniecia pliku");
        exit(1);
    }

    exit(0);
}
