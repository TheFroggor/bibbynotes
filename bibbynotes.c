#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main(){
    const char *home = getenv("HOME");
    char notes_dir[256];
    snprintf(notes_dir, sizeof(notes_dir), "%s/BibbyNotes", home);
    prep_folder_exists(notes_dir);
    int choice;
    do {
        printf("\n=== Bibby Notes ===\n");
        printf("1. New Note\n");
        printf("2. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        while (getchar() != '\n');
        switch (choice) {
            case 1:
                if (make_new_note(notes_dir) == 0)
                    printf("Note made successfully!\n");
                else 
                    printf("Bruh...\n");
                break;
            case 2:
                printf("BAIIIIII!!!11!!!\n");
                break;
            deafult:
                printf("Bruh?\n");
        }
     } while (choice !=2);
     return 0;
}
