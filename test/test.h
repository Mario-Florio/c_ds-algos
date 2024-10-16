#ifndef c_dsalgos_test_test_h
#define c_dsalgos_test_test_h

#include <string.h>
#include "../common.h"

void suite(char* name, void (*func)());
void it(char* name, int condition);

#endif