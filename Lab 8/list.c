#include <stdio.h>
#include "list.h"

unsigned int length(Node* head)
{
	unsigned int size = 0;
	Node* p = head;
	while (p != NULL)
	{
		p = p -> next;
		size++;
	}
	return size;
}

void print(Node* head){
	Node* p = head;
	while (p != NULL){
		printf("%d\n", p -> data);
		p = p -> next;
	}
}

Node *next(Node *head, Node *of_node){
	Node* p = head;
	while (p != of_node)
		p = p -> next;
	return p -> next;
}

Node *previous(Node *head, Node *of_node){
	Node* p = head;
	if (of_node == head)
		return NULL;
	while (p -> next != of_node)
		p = p -> next;
	return p;
}

void insert(Node **head, Node *new_node, unsigned int position){
	Node* p = *head;
	if (position == 0)
	{
		new_node -> next = *head;
		*head = new_node;
		return ;
	}
	while (position != 0)
	{
		if (p = p -> next || position == 1) // = on purpose
			position--; // if position == 1 that means we will add to the end of the list
		else 
			return; // wrong position
	}
	Node* next_node = p -> next;
	p -> next = new_node;
	new_node -> next = next_node;
}