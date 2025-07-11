#pragma once

#include "lib.h"

typedef struct
{
	threadpool_task_t *head;
	threadpool_task_t *tail;
	pthread_mutex_t lock;
	pthread_cond_t cond;
	int size;
} threadpool_task_queue;