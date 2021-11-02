#include <stdlib.h>

typedef struct list{
	Node* head;
	int size;
}LinkedList;

typedef struct node{
	struct node* next;
	int data;
}Node;

unsigned int length(Node* head);

void print(Node* head);

Node* next(Node* head, Node* of_node);

Node* previous(Node* head, Node* of_node);

Node* retrieve(Node* head, unsigned int position);

unsigned int locate(Node *head, unsigned int start_position, float value);

void insert(Node **head, Node *new_node, unsigned int position);

void delete(Node **head, unsigned int position);