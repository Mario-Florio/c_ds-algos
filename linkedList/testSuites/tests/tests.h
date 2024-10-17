#ifndef c_dsalgos_linkedlist_testsuites_tests_tests_h
#define c_dsalgos_linkedlist_testsuites_tests_tests_h

#include "../../linkedList.h"

void abstract_linkedList_accessTests(LinkedList* plist, int (*linkedList_access)(LinkedList* plist, int idx));

void abstract_linkedList_addTests(LinkedList* plist, void (*linkedList_add)(LinkedList* plist, int idx, int val));
void abstract_linkedList_removeTests(LinkedList* plist, int (*linkedList_remove)(LinkedList* plist, int idx));

void abstract_linkedList_pushTests(LinkedList* plist, void (*linkedList_push)(LinkedList* plist, int val));
void abstract_linkedList_popTests(LinkedList* plist, int (*linkedList_pop)(LinkedList* plist));

void abstract_linkedList_shiftTests(LinkedList* plist, void (*linkedList_shift)(LinkedList* plist, int val));
void abstract_linkedList_unshiftTests(LinkedList* plist, int (*linkedList_unshift)(LinkedList* plist));

#endif