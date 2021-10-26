#include "queue.h"

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

#ifdef DEBUG_QUEUE
int main(){
// testing queues here
}
#endif
