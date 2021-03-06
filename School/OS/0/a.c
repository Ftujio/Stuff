#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t m;
int turn = 2;

void* print(void* arg){
	int* p = arg;
	int i;
	
	for(i = 0; i < 10;){
		if(turn != *p){
			pthread_mutex_lock(&m);
			printf("Hello from thread %d!\n", *p);
			turn = *p;
			i++;
			pthread_mutex_unlock(&m);
		}
	}
}

int main(int argc, char* argv[]){
	pthread_mutex_init(&m, NULL);
	int a = 1;
	int b = 2;
	int* pa = &a;
	int* pb = &b;

	pthread_t thread1;
	pthread_t thread2;
	
	pthread_create(&thread1, NULL, print, pa);
	pthread_create(&thread1, NULL, print, pb);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_mutex_destroy(&m);

	return 0;
}