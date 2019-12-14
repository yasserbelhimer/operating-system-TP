#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
    int fd;
    if(argc!=2){
        printf("Usage: %s <File name#>\n",argv[0]);
        exit(1);
    }
    mode_t mode = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

    fd = (int)open(argv[1],O_WRONLY | O_EXCL | O_CREAT,mode);

    if(fd==-1){
        perror("open");
        exit(-1);
    }
    return EXIT_SUCCESS;
}