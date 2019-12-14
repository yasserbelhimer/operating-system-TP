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
    DIR* rep = NULL;
    struct stat StatusBuffer;
    struct dirent* fichierLu = NULL;
    int rflag = 0;
    int fflag = 0;
    char *rvalue = NULL;
    char *fvalue = NULL;
    char *svalue = NULL;
    int opt;
    if (argc<=3)
    {
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
        if (rflag&&!fflag)
        { 
            if (rvalue!=NULL)
            {
                rep=opendir(rvalue);
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
                if (fichierLu->d_type == DT_DIR)
                {
                    printf("%s\n",fichierLu->d_name);
                }
            }
        }
        if (fflag&&!rflag)
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
                if (fichierLu->d_type==DT_REG)
                {
                    printf("%s\n",fichierLu->d_name);
                }
            }
        }
        if ((fflag&&rflag)||(!rflag&&!fflag))
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
        }
    }
    return EXIT_SUCCESS;
}