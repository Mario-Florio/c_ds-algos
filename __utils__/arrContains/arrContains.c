#include "../../common.h"

int arrContains(int length, char* arr[], char* str) {
    for (int i = 0; i < length; i++) {
        if (strcmp(arr[i], str) == 0) return 1;
    }
    return 0;
}
