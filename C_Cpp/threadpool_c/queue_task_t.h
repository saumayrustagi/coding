#pragma once

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "task_t.h"

typedef struct
{
	task_t *array;
	int size;
	int capacity;
	int head;
	int tail;

	pthread_mutex_t lock;
	pthread_cond_t not_empty;
	pthread_cond_t not_full;
} queue_task_t;

queue_task_t *queue_init(int capacity);

void queue_destroy(queue_task_t *q);

void enqueue(queue_task_t *q, task_t val);

task_t dequeue(queue_task_t *q);