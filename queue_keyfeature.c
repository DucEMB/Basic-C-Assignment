#include <stdio.h>
#include <stdlib.h>

struct queue
{
	int front;
	int rear;
	int	size;
	int capacity;
	int * array;
};
typedef struct queue Queue;

Queue * make_queue(int capacity)
{
	Queue * newqueue = (Queue *)malloc(sizeof(Queue));
	newqueue->capacity = capacity;
	newqueue->front = 0;
	newqueue->size = 0;
	newqueue->rear = capacity - 1;
	newqueue->array = (int *)malloc(capacity*sizeof(int));
	return newqueue;
}

int is_full(Queue * queue)
{
	if (queue->size == queue->capacity)
	{
		return 1;
	}
	return 0;
}

int is_empty(Queue * queue)
{
	if (queue->size == 0)
	{
		return 1;
	}
	return 0;
}

void Enqueue(Queue * queue,int value)
{
	if (is_full(queue))
	{
		return;
	}
	queue->rear = ( queue->rear + 1 ) % queue->capacity;
	queue->array[queue->rear] = value;
	queue->size = queue->size + 1;
}

int Dequeue(Queue * queue)
{
	int res;
	if (is_empty(queue))
	{
		return 0;
	}
	res = queue->array[queue->front];
	queue->front = ( queue->front + 1 ) % queue->capacity;
	queue->size = queue->size - 1;
	return res;
}

void print_queue(Queue * queue)
{
	while (is_empty(queue) == 0)
	{
		printf("  %d",Dequeue(queue));
	}
}

int main()
{
	Queue * queue = make_queue(5);
	Enqueue(queue,10);
	Enqueue(queue,20);
	Enqueue(queue,30);
	Enqueue(queue,40);
	Enqueue(queue,50);
	Dequeue(queue);
	print_queue(queue);
	return 0;
}