//
// Created by michael on 03.10.23.
//



#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
   int d;

   if ( argc < 2 )
      exit (1);

   d = open(argv[1], O_RDONLY);
   if ( d == -1 ) {
      perror("Blad otwarcia pliku");
      exit (1);
   }

   exit (0);
}
