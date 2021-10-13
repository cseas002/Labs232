#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}NODE;

typedef struct queue{
	NODE* head;
	NODE* tail;
	int length;
}QUEUE;

int initQueue(QUEUE** queue)
{
	*queue = (QUEUE*) malloc(sizeof(QUEUE));
	 if (*(queue) == NULL)
		return EXIT_FAILURE;
	(**queue).head = (**queue).tail = NULL;
	(**queue).length = 0;
	return EXIT_SUCCESS;
}

int enqueue(QUEUE* queue, int value)
{
	NODE* p = (NODE*) malloc(sizeof(NODE));
	p -> data = value;
	p -> next = NULL;
	if (queue -> length == 0)
		queue -> head = queue -> tail = p;
	else 
	{
		queue -> tail -> next = p;
		queue -> tail = p;
	}
	(queue -> length)++;
	return EXIT_SUCCESS;
}

int dequeue(QUEUE* queue)
{
	if (queue -> length == 0)
	{
		printf("Can't dequeue because the queue is empty\n");
		return -1;	
	}
	NODE* p = queue -> head;
	int returnValue = queue -> head -> data;
	queue -> head = queue -> head -> next;
	free(p);
	(queue -> length)--;
	if (queue -> length == 0) 
		queue -> tail = NULL; // tail will keep the value otherwise
	return returnValue;
}

int main()
{
	int n, m, i, newSize, j = 1;
	QUEUE* queue;
	QUEUE* queue2;
	QUEUE* queueDead;
	initQueue(&queue);
	initQueue(&queue2);
	initQueue(&queueDead);
	printf("Length of the queue: ");
	scanf("%d", &n);
	printf("Killing each number: ");
	scanf("%d", &m);
	for (i = 1; i <= n; i++)
		enqueue(queue, i);

	newSize = n;

	while (newSize > 0)
	{
	    if (queue -> length == 0)
		    for (i = 0; i < newSize; i++)
				    enqueue(queue, dequeue(queue2)); // Adding back people
		if (j % m == 0)
		{
			enqueue(queueDead, dequeue(queue)); // adding dead people to a queue
			newSize--;
		}
		else
			enqueue(queue2, dequeue(queue)); // And the others into another queue temprorarily
		j++;
	}

	for (i = 1; i <= n; i++)
		printf("Dead %d:%d\n", i, dequeue(queueDead));

}
