#pragma once

typedef struct
{
	void (*function)(void *);
	void *args;
} task_t;
