#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "queue_task.h"

queue_task_t *queue_init(int capacity)
{
	queue_task_t *q = (queue_task_t *)malloc(sizeof(queue_task_t));
	q->array = malloc(sizeof(task_t) * capacity);
	q->size = 0;
	q->capacity = capacity;
	q->head = 0;
	q->tail = 0;
	return q;
}

void queue_destroy(queue_task_t *q)
{
	free(q->array);
	free(q);
}

void enqueue(queue_task_t *q, task_t val)
{
	assert(q->size < q->capacity);
	q->array[q->tail] = val;
	++(q->size);
	q->tail = (q->tail < q->capacity - 1) ? q->tail + 1 : 0;
}

int dequeue(queue_task_t *q)
{
	assert(q->size > 0);
	--(q->size);
	int tmp = q->head;
	q->head = (q->head < q->capacity - 1) ? q->head + 1 : 0;
	return tmp;
}