#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>
#include <limits.h>
#include <getopt.h>

int main(int argc,char *argv[]){
    DIR* rep = NULL;//la declaration d'un pointeur sur FILE DIR.|| la declaration de notre repertoire
    struct dirent* fichierLu = NULL;// la declaration de fichier intermidiare pour parcourir le dossier
    int rflag = 0;// une variable boolean pour savoir si l'utilisateur a choisi l'iption r
    int fflag = 0;// une variable boolean pour savoir si l'utilisateur a choisi l'iption f
    char *rvalue = NULL;// la chaine de caractere qui corresponde a un dossier
    char *fvalue = NULL;// la chaine de caractere qui corresponde a un dossier 
    // remarque : on peut utiliser une seule chaine de carctere 
    int opt;// l'option qui va choisin l'utilisateur r pour les repretoires et f pour les fichiers
    // opendir() attend une chaîne de caractères et renvoie un pointeur sur FILE DIR.
    // closedir() Cette fonction attend un pointeur sur DIR et renvoie un int qui correspond à un code d'erreur, 0 si la fermeture s'est bien exécutée, -1 s'il y a eu un souci.
    // readdir() prend en paramètre un pointeur sur DIR ;Par contre elle renvoie un pointeur sur une structure dirent.ette structure, elle simule le fichier du dossier qui sera lu ! readdir() renvoie NULL s'il n'y a plus de fichier à lire.
    /*
     La fonction getopt() analyse les arguments de la ligne de commande.
     Ses éléments argc et argv correspondent aux nombres et à la table d'arguments qui sont transmis à la fonction main() lors du lancement du programme. 
     Un élément de argv qui commence par « - » (et qui ne soit pas uniquement « -- » ou « - ») est considéré comme une option. 
     Les caractères à la suite du « - » initial sont les caractères de l'option. 
     Si getopt() est appelée à plusieurs reprises, elle renverra successivement chaque caractère de chaque option.
    */
    //La fonction getcwd() copie le chemin d'accès absolu du répertoire de travail courant dans la chaîne pointée par buf, qui est de longueur size.
    if (argc<=3)
    {
        // on commance par la recuperation des options
        while ((opt = getopt (argc, argv, "rf")) != -1){
            switch (opt)
            {
                case 'r':
                    rflag = 1;rvalue = argv[optind];
                    break;
                case 'f':
                    fflag = 1;fvalue=argv[optind];
                    break;
                default:
                    printf("error");
            }
        }
        if (rflag&&!fflag)//si l'utilisateur a choisir l'option r seulement
        { 
            if (rvalue!=NULL)
            {
                rep=opendir(rvalue);/* Ouverture d'un dossier  */
                if (rep==NULL)
                {
                    char cwd[PATH_MAX];
                    if (getcwd(cwd, sizeof(cwd)) != NULL) {
                    rep=opendir(cwd);/* Ouverture du dossier courant si le chaine entree n'est pas valide pour un dossier*/
                    }
                }
            }
            else
            {
                char cwd[PATH_MAX];
                if (getcwd(cwd, sizeof(cwd)) != NULL) {
                    rep=opendir(cwd);// Ouverture du dossier courant si aucun repertoire n'est specifie
                }
            } 
            while (fichierLu = readdir(rep))
            {
                if (fichierLu->d_type == DT_DIR)// si le fichier lu est un repertoire on l'affiche
                {
                    printf("%s\n",fichierLu->d_name);
                }
            }
            closedir(rep);
        }
        if (fflag&&!rflag)//si l'utilisateur a choisir l'option f seulement
        {
            if (fvalue)
            {
                rep=opendir(fvalue);
                if (rep==NULL)
                {
                    char cwd[PATH_MAX];
                    if (getcwd(cwd, sizeof(cwd)) != NULL) {
                    rep=opendir(cwd);
                    }
                }
            }
            else
            {
                char cwd[PATH_MAX];
                if (getcwd(cwd, sizeof(cwd)) != NULL) {
                    rep=opendir(cwd);
                }
            } 
            while (fichierLu = readdir(rep))
            {
                if (fichierLu->d_type==DT_REG)// si le fichier lu est un fichier regulier on l'affiche
                {
                    printf("%s\n",fichierLu->d_name);
                }
            }
            closedir(rep);
        }
        if ((fflag&&rflag)||(!rflag&&!fflag))// si l'utilisateur a choisir les deux option r et f ou bien n'a choisir aucune option
        {
            if (argv[1]!=NULL)
            {
                rep=opendir(argv[1]);
                if (rep==NULL)
                {
                    char cwd[PATH_MAX];
                    if (getcwd(cwd, sizeof(cwd)) != NULL) {
                    rep=opendir(cwd);
                    }
                }
            }
            else
            {
                char cwd[PATH_MAX];
                if (getcwd(cwd, sizeof(cwd)) != NULL) {
                    rep=opendir(cwd);
                }
            } 
            while (fichierLu = readdir(rep))
                printf("%s\n",fichierLu->d_name);
            closedir(rep);
        }
    }
    return EXIT_SUCCESS;
}
