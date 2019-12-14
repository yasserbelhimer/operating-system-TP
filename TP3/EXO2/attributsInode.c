#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<pwd.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
    struct stat StatusBuffer;

    
    if(stat(argv[1],&StatusBuffer)==-1){
        perror(argv[1]);
        exit(1);
    }

    printf("Nom de fichier : %s\n",argv[1]);
    printf("Droit d'acces (mode octal) :%o\n",StatusBuffer.st_mode & 0777);

    if(S_ISREG(StatusBuffer.st_mode))
        printf("%s est un fichier regulier \n",argv[1]);
    else if(S_ISDIR(StatusBuffer.st_mode))
        printf("%s est un repertoire \n",argv[1]);

    printf("Les droits d'acces de USER en mode symbolique sont :");
    printf("%c",StatusBuffer.st_mode & S_IRUSR ? 'r' : '-');
    printf("%c",StatusBuffer.st_mode & S_IWUSR ? 'w' : '-');
    printf("%c\n",StatusBuffer.st_mode & S_IXUSR ? 'x' : '-');
    printf("Owner  :\t\t %s\n",getpwuid(StatusBuffer.st_uid)->pw_name);
    printf("Taille :\t\t %ld\n",StatusBuffer.st_size);
    return EXIT_SUCCESS;
}