#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>

int prep_folder_exists (const char *notes_dir){
    char ans;
    DIR *dir = opendir(notes_dir);
    if (dir == NULL){
        perror("folder doesn't exist.\n");
        printf("do you wish to create default folder?Y/N\n");
        scanf(" %c", &ans);
        if (ans == "Y" | ans == "y"){
           if ( mkdir(notes_dir, 0755) == 0){
                printf("folder created.\n");
                return 0;
                }
            else{
                printf("folder creation failed.\n");
                return 1;
                }
            }
        else{
            perror("folder creation cancelled.");
            return 1;
            }
        }
    else {
        closedir(dir);
        return 0;
        }
    
}
