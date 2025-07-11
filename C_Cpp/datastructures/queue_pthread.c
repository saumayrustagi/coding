#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct
{
	pthread_t *array;
	int size;
	int capacity;
	int head;
	int tail;
} queue_pthread;

queue_pthread *queue_init(int capacity)
{
	queue_pthread *q = (queue_pthread *)malloc(sizeof(queue_pthread));
	q->array = malloc(sizeof(pthread_t) * capacity);
	q->size = 0;
	q->capacity = capacity;
	q->head = 0;
	q->tail = 0;
	return q;
}

void queue_destroy(queue_pthread *q)
{
	free(q->array);
	free(q);
}

int enqueue(queue_pthread *q, pthread_t val)
{
	assert(q->size < q->capacity);
	q->array[q->tail] = val;
	++(q->size);
	q->tail = (q->tail < q->capacity - 1) ? q->tail + 1 : 0;
	return val;
}

int dequeue(queue_pthread *q)
{
	assert(q->size > 0);
	--(q->size);
	int tmp = q->head;
	q->head = (q->head < q->capacity - 1) ? q->head + 1 : 0;
	return tmp;
}

void print_queue(queue_pthread *q)
{
	int tmp = q->head;
	int traversed = 0;
	while (q->size > traversed)
	{
		printf("%d ", (void *)q->array[tmp]);
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
	queue_pthread *q = queue_init(5);
	pthread_t t1, t2, t3, t4, t5, t6;
	enqueue(q, t1);
	enqueue(q, t2);
	print_queue(q);
	dequeue(q);
	print_queue(q);
	enqueue(q, t3);
	enqueue(q, t4);
	enqueue(q, t5);
	enqueue(q, t6);
	print_queue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	print_queue(q);
	enqueue(q, t4);
	enqueue(q, t5);
	enqueue(q, t6);
	print_queue(q);
	dequeue(q);
	dequeue(q);
	print_queue(q);
	queue_destroy(q);

	char *disclaimer = "I just wanted to check if the thread_queue is working correctly and since the pattern matches that of the int_queue, we can assume that since the sanitizers didn't catch anything, we are good to go";
	printf("\n%s\n", disclaimer);

	return 0;
}