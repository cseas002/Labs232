#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char data;
	struct node* next;
}NODE;

typedef struct stack{
	NODE* top;
	int size;
}STACK;


//int push(STACK* par, char value)
//{
//	NODE* p1 = (NODE*) malloc(sizeof(NODE));
//	p1 -> data = value;
//	p1 -> next = NULL;
//	if (par -> size == 0)
//		par -> top = p1;
//	else 
//	{
//		par -> top -> next = p1;
//		par -> top = p1;
//	}
//	(par -> size)++;
//	
//	return EXIT_SUCCESS;
//}

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
//
//char pop(STACK* par)
//{
//	if (par -> size == 0)
//		return '\0';
//	NODE* p1 = par -> top;
//	par -> top -> next = NULL;
//	(par -> size)--;
//	return p1 -> data;
//}

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

bool valid(STACK* par)
{
	bool bracket = false, sqrBracket = false;
	int parenthese = 0;
	char type;
	while (par -> size > 0)
	{
		type = pop(par);
		printf("%c\n", type);
		switch(type)
		{
		case ')':
			parenthese ++;
			break;
		case '(':
			if (parenthese <= 0)
				return false;
			parenthese --;
			break;
		case ']':
			if (sqrBracket || parenthese)
				return false;
			sqrBracket = true;
			break;
		case '[':
			if (parenthese != 0 || !sqrBracket)
				return false;
			sqrBracket = false;
			break;
		case '}':
			if (parenthese != 0 || sqrBracket || bracket)
				return false;
			bracket = true;
			break;
		case '{':
			if (parenthese != 0 || sqrBracket)
				return false;
			bracket = false;
			break;
		}
	}
	if (bracket || sqrBracket || parenthese != 0)
		return false;
	return true;
}

int main()
{
	printf("Give the sequence :\n");
	char* seq = (char*) malloc(50 * sizeof(char));
	scanf("%s", seq);
	int i;
	STACK* par;
	initStack(&par);
	for (i = 0; i < strlen(seq); i++)
		push(par, seq[i]);
	
	printf("%s\n", valid(par) ? "true" : "false");
}