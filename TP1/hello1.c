#include <stdio.h>
int main(int argc,char *argv[]){
    printf("le nom du programme est %s !\n",argv[0]);
    printf("le nombre d'arguments passe est %d !\n",argc);
    if (argc>1)
    {
        printf("les differenta arguments passe sont :\n");
        for (int i = 0; i < argc; i++)
        {
            printf("l'argument n %d est %s\n",i+1,argv[i]);
        }
        
    }
    return 0;
}