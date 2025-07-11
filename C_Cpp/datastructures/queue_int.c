#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int *array;
	int size;
	int capacity;
	int head;
	int tail;
} queue;

queue *queue_init(int capacity)
{
	queue *q = (queue *)malloc(sizeof(queue));
	q->array = malloc(sizeof(int) * capacity);
	q->size = 0;
	q->capacity = capacity;
	q->head = 0;
	q->tail = 0;
	return q;
}

void queue_destroy(queue *q)
{
	free(q->array);
	free(q);
}

int enqueue(queue *q, int val)
{
	assert(q->size < q->capacity);
	q->array[q->tail] = val;
	++(q->size);
	q->tail = (q->tail < q->capacity - 1) ? q->tail + 1 : 0;
	return val;
}

int dequeue(queue *q)
{
	assert(q->size > 0);
	--(q->size);
	int tmp = q->head;
	q->head = (q->head < q->capacity - 1) ? q->head + 1 : 0;
	return tmp;
}

void print_queue(queue *q)
{
	int tmp = q->head;
	int traversed = 0;
	while (q->size > traversed)
	{
		printf("%d ", q->array[tmp]);
		if (tmp < q->capacity - 1)
			++tmp;
		else
			tmp = 0;
		++traversed;
	}
	printf("\n");
}

int main()
{
	queue *q = queue_init(5);
	enqueue(q, 1);
	enqueue(q, 2);
	print_queue(q);
	dequeue(q);
	print_queue(q);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	enqueue(q, 6);
	print_queue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	print_queue(q);
	enqueue(q, 4);
	enqueue(q, 5);
	enqueue(q, 6);
	print_queue(q);
	dequeue(q);
	dequeue(q);
	print_queue(q);
	queue_destroy(q);

	return 0;
}