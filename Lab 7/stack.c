#include "stack.h"

int push(STACK *s, char value) {
	NODE *p = NULL;
	if (s == NULL){
		return EXIT_FAILURE;
	}
	p = (NODE *) malloc(sizeof(NODE));
	if ( p == NULL ) {
		printf("System out of memory!\n");
		return EXIT_FAILURE;
	}
	p->data = value;// assign to new node
	p->next = s->top; // adjust next pointer
	s->top = p;// point head to this node
	(s -> size)++;// increase stack size
	return EXIT_SUCCESS;
}

char pop(STACK *s)
{
	char value;
	NODE *p = NULL;
	if ( s == NULL || s->size == 0 ) {
		printf("Sorry, stack is empty...\n");
		return EXIT_FAILURE;
	}
	value = (s->top)->data;  // top of stack
	p = s->top;  // remember for free()
	s->top = p->next;// top should point to next
	(s ->size)--;           // decrease stack size
	free(p);// free allocated space
	return value;;
}


int initStack(STACK** par)
{
	*par = (STACK*) malloc(sizeof(STACK));
	(*par) -> top = NULL;
	(*par) -> size = 0;
	
	return EXIT_SUCCESS;
}

#ifdef DEBUG_STACK
int main()
{
// Testing stack
}
#endif
