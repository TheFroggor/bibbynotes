#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "funcs.h"
#include <sys/stat.h>

int make_new_note(const char *notes_dir){
    int last_num = 0;
    char today[11];
    if (prep_folder_exists(notes_dir) !=0){
        return -1;
    }
    get_current_date(today, sizeof(today));
    if (get_last_note_today_num(notes_dir, &last_num, today) == -1) {
        last_num = 0;
    }
    int new_num = last_num + 1;
    char nname[256];
    snprintf(nname, sizeof(nname), "note_%d_%s.txt", new_num, today);
    char cmd[512];
    char fullpath[512];
    snprintf(fullpath, sizeof(fullpath), "%s/%s", notes_dir, nname);
    snprintf(cmd, sizeof(cmd), "nano \"%s\"", fullpath);
    if (system(cmd) != 0){
        return -1;
    }
    if(chmod(fullpath, 0444) != 0){
        perror("chmod");
    }
    return 0;
}
