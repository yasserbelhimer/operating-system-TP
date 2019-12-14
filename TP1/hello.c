#include <stdio.h>
int main(int argc,char *argv[]){
    if (argc>1)
    {
        printf("Bonjour %s !\n",argv[1]);
    }
    else
    {
        printf("Bonjour Inconnu !\n");
    }
    return 0;
}