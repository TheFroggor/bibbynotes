#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main(){
    const char *home = getenv("HOME");
    char notes_dir[256];
    char out_name[256];
    snprintf(notes_dir, sizeof(notes_dir), "%s/BibbyNotes", home);
    prep_folder_exists(notes_dir);
    int choice;
    do {
        printf("\n=== Bibby Notes ===\n");
        printf("1. New Note\n");
        printf("2. Check last note\n");
        printf("3. Show notes directory\n");
        printf("4. Exit\n");
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
                get_last_note_num(notes_dir, out_name);
                char open[256];
                snprintf(open, sizeof(open), "less \"%s/%s\"", notes_dir, out_name);
                if (system(open) != 0){
                    return -1;
                    }
                break;
                while (getchar() != '\n');
            case 3:
                printf("Notes directory: %s\n", notes_dir);
                break;
            case 4:
                printf("BAIIIIII!!!11!!!\n");
                break;
            deafult:
                printf("Bruh?\n");
        }
     } while (choice !=4);
     return 0;
}
