#ifndef STACK_H
#define STACK_H
#include "commonCode.h"

typedef struct stack{
	NODE* top;
	int size;
}STACK;

int push(STACK *s, char value);

char pop(STACK *s);

int initStack(STACK** par);
#endif
