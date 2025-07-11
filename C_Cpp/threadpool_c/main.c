#include "lib.h"

int main()
{
	threadpool_t *tp = threadpool_init(10, 20);
	return 0;
}