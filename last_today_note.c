#include <dirent.h>
#include <string.h>
#include <stdio.h>

int get_last_note_today_num (const char *notes_dir, int *out_num, const char *date){
    DIR *dir = opendir(notes_dir);
    if (dir == NULL){
        perror("failed to open directory");
        return -1;
    }
    int best_num = -1;
    int num, y, m, d;
    char file_date[11];
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (sscanf(entry->d_name,  "note_%d_%4d-%2d-%2d.txt", &num, &y, &m, &d) == 4) {
            snprintf(file_date, sizeof(file_date), "%04d-%02d-%02d", y, m, d);
            if (strcmp(date, file_date) == 0 && best_num < num) {
                best_num = num;
            }
        }
    }
    if (best_num == -1) {
    printf("no notes today!\n");
    closedir(dir);
    return -1;
    }
    else {
        *out_num = best_num;
        }
    closedir(dir);
    return 0;
}
