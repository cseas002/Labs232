#ifndef QUEUE_H
#define QUEUE_H
#include "commonCode.h"

typedef struct queue{
	NODE* head;
	NODE* tail;
	int length;
}QUEUE;

int initQueue(QUEUE**);

int enqueue(QUEUE*, int);

int dequeue(QUEUE*);
#endif
