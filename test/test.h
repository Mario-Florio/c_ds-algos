#ifndef c_dsalgos_test_test_h
#define c_dsalgos_test_test_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void suite(char* name, void (*func)());
void it(char* name, int condition);

#endif