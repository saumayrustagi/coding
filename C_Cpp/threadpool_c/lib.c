#include "lib.h"
#include <pthread.h>
#include <stdlib.h>
#include <assert.h>

threadpool_t *threadpool_init(int num_threads, int queue_capacity)
{
	threadpool_t *tp = (threadpool_t *)malloc(sizeof(threadpool_t));
	assert(tp != NULL);

	tp->num_threads = num_threads;
	tp->count = 0;
	tp->queue_capacity = queue_capacity;

	tp->threads = (pthread_t *)malloc(sizeof(pthread_t) * num_threads);
	tp->queue = (threadpool_task_t *)malloc(sizeof(int) * queue_capacity);
	return tp;
}
