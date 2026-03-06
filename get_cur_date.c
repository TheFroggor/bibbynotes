#include <stdio.h>
#include <time.h>

void get_current_date(char *buffer, size_t size){
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d", tm_info);
}
