#include <ctype.h>
#include <stdio.h>
#include <string.h>

void trimString(char* str) {
    int start = 0;
    int end = strlen(str)-1;

    while (isspace(str[start])) {
        start++;
    }

    while (end > start && isspace(str[end])) {
        end--;
    }

    if (start > 0 || end < (strlen(str)-1)) {
        memmove(str, str + start, end-start+1);
        str[end-start+1] = '\0';
    }
}
