#ifndef c_dsalgos_stack_stack_h
#define c_dsalgos_stack_stack_h

#include "../linkedList/linkedList.h"

typedef LinkedList Stack;

void stack_init(Stack* pstack);
void stack_reset(Stack* pstack);
int stack_access(Stack* pstack, int idx);
int stack_peek(Stack* pstack);
void stack_push(Stack* pstack, int val);
int stack_pop(Stack* pstack);

#endif