#include <stdio.h>
#include <pthread.h>
#include <assert.h>

void *print_args (void *arg) {
	printf("%s\n", (char *)arg);
	return NULL;
}

int main(void) {
	pthread_t t1, t2;
	printf("Main begin\n");
	pthread_create(&t1, NULL, print_args, "A");
	pthread_create(&t2, NULL, print_args, "B");
	printf("Main end\n");
	pthread_exit(NULL);
	// printf("Main end twice\n");
	return 0;
}