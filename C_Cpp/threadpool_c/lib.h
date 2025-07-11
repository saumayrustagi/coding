#pragma once

#include <pthread.h>

typedef struct
{
	void (*function)(void *);
	void *args;
} threadpool_task_t;

typedef struct
{
	int num_threads;
	int count;
	int queue_capacity;

	threadpool_task_t *queue;
	pthread_t *threads;
	pthread_mutex_t lock;
	pthread_cond_t cond;
} threadpool_t;

threadpool_t *threadpool_init(int num_threads, int queue_capacity);