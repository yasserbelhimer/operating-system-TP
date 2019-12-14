#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc,char *argv[]){
    char buf;
    int fd;

    if(argc == 1)
        printf("Manque d'arguments !\n Usage : cat [filename] ...\n");
    else
    {
        fd = open(argv[1],O_RDONLY);
        if(fd==-1)
            printf("le fichier %s n'existe pas !\n",argv[1]);
        else
        {
            while(read(fd,&buf,1)) write(1,&buf,1);
            printf("\n");
            close(fd);
        }

    }
}