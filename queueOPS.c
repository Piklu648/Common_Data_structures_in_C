#include "queueADT.h"

QUEUE* createQueue(void)
{
	QUEUE* queue;

	if(queue = (QUEUE*) malloc(sizeof(QUEUE)))
	{
		queue->front = NULL;
		queue->rear  = NULL;
		queue->count = 0;
	}
	
	return queue;
}


bool enqueue(QUEUE* queue, void* itemPtr)
{
	QUEUE_NODE* newPtr;

	if( !(newPtr = (QUEUE_NODE*) malloc(sizeof(QUEUE_NODE))) )
		return false;

	newptr->dataPtr = itemPtr;
	newPtr->next    = NULL;

	if(queue->count == 0)
		queue->front = newPtr;
	else
		queue->rear->next = newPtr;

	queue->rear  = newPtr;
	(queue->count)++;

	return true;
}


void dequeue(QUEUE* queue, void** itemPtr)
{
	QUEUE_NODE* deleteLoc;

	if(!queue->count)
		return false;

	*itemPtr  = queue->front->dataPtr;
	deleteLoc = queue->front;

	if(queue->count == 1)
		queue->front = queue->rear = NULL;
	else
		queue->front = queue->front->next;

	(queue->count)--;
	free(deleteLoc);

	return true;

}


bool queueFront(QUEUE* queue, void** itemPtr)
{
	if(!queue->count)
		return false;
	else
	{
		*itemPtr = queue->front->dataPtr;
		return true;
	}
}


bool queueRear(QUEUE* queue, void** itemPtr)
{
	if(!queue->count)
		return false;
	else
	{
		*itemPtr = queue->rear->dataPtr;
		return true;
	}
}


bool emptyQueue(QUEUE* queue)
{
	return (queue->count == 0);
}


bool fullQueue(QUEUE* queue)
{
	QUEUE_NODE* temp;

	temp = (QUEUE_NODE*) malloc(sizeof(QUEUE_NODE));

	if(temp)
	{
		free(temp);
		return true;
	}

	return false;
}


int queueCount(QUEUE* queue)
{
	return queue->count;
}


QUEUE* destroyQueue(QUEUE* queue)
{
	QUEUE_NODE* deletePtr;

	if(queue)
	{
		while(queue->front != NULL)
		{
			free(queue->front->dataPtr);
			deletePtr = queue->front;
			queue->front = queue->front->next;
			free(deletePtr);
		}

		free(queue);
	}

	return NULL;
}

