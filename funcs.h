#ifndef FUNCS_H
#define FUNCS_H
#include <stddef.h>

int prep_folder_exists(const char *notes_dir);
void get_current_date(char *buffer, size_t size);
int get_last_note_today_num(const char *notes_dir, int *out_num, const char *date);
int make_new_note(const char *notes_dir);

#endif 
