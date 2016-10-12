#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define THREAD_NUM 2

long turn = 0;
pthread_mutex_t mutex;

void* print(void* a){
	long tid = (long) a;
	pthread_mutex_lock(&mutex);
	if(turn == tid){
		printf("thread %ld\n", turn);
	}
	if(turn == 0){
		turn = 1;
	} else {
		turn = 0;
	}
	printf("turn for thread %ld\n", turn);
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

int main(int argc, char* argv[]){
	pthread_mutex_init(&mutex, NULL);
	pthread_t threads[THREAD_NUM];
	long i = 0, th;

	while(1){
		if(th = pthread_create(&threads[turn], NULL, print, (void*)i)){
			printf("Error with thread!\n");
		}
		if(i == 0){
			i = 1;
		} else {
			i = 0;
		}
	}

	pthread_exit(NULL);

	return 0;
}