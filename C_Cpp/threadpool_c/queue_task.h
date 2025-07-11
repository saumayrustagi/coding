#pragma once

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "task.h"

typedef struct
{
	task_t *array;
	int size;
	int capacity;
	int head;
	int tail;
} queue_task_t;

queue_task_t *queue_init(int capacity);

void queue_destroy(queue_task_t *q);

int enqueue(queue_task_t *q, task_t val);

int dequeue(queue_task_t *q);