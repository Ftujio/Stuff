#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

int num = 0;

pthread_mutex_t m_num;

void* work(void* arg){
	int i;
	int id = *((int*)arg);
	printf("thread: %d\n", id);

	for(i = 0; i < 16000000; i++){
		pthread_mutex_lock(&m_num);
		num++;
		pthread_mutex_unlock(&m_num);
	}

	return NULL;
}

int main(int argc, char* argv[]){
	int i;
	pthread_t thread[2];

	pthread_mutex_init(&m_num, NULL);

	for(i = 0; i < 2; i++){
		int* id = malloc(sizeof(int));
		*id = i;
		printf("i: %d, id: %d\n", i, *id);
		pthread_create(&thread[i], NULL, work, (void*)id);
	}

	for(i = 0; i < 2; i++){
		pthread_join(thread[i], NULL);
	}

	pthread_mutex_destroy(&m_num);

	printf("%d\n", num);

	return 0;
}