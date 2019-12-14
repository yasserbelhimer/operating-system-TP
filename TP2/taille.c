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
        for(int i = 1;i<argc;i++)
        {
            fd = open(argv[i],O_RDONLY);
            if(fd==-1)
                printf("le fichier %s n'existe pas !\n",argv[i]);
            else
            {
                int tailleFichier = 0;
                while(read(fd,&buf,1))
                {
                    tailleFichier++;
                }
                printf("le fichiers : %s sa taille est %d\n",argv[i],tailleFichier);
                close(fd);
            }
        }
        

    }
}