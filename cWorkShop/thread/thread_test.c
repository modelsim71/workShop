#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
    printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid,
		      (unsigned int)tid, (unsigned int)tid);

/*	while (1) {
		sleep(30000);
		printf("threadf 1\n");
	}*/
	return ;
}

void *thread_fn(void *arg)
{
	printids("new thread: ");
	return NULL;
}

int main(int argc, char **argv)
{
    int err; 
	pthread_t ntid;
	
	err = pthread_create(&ntid, NULL, thread_fn, NULL);
	if (0 != err) {
		printf("can't create thread: %s\n", strerror(err));
	}
	printids("main thread: ");
	pthread_join(ntid, NULL);
	
	return EXIT_SUCCESS;
}

