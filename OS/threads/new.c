#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int a = 100;
int p = 0;
pthread_mutex_t mp;
pthread_mutex_t m;

void* work(void* arg){
	pthread_mutex_lock(&m);
	while(a > 0){
		pthread_mutex_unlock(&m);
	
		pthread_mutex_lock(&m);
		a -= 10;
		pthread_mutex_unlock(&m);
		
		pthread_mutex_lock(&mp);
		p += 10;
		pthread_mutex_unlock(&mp);
		
		pthread_mutex_lock(&mp);
	}
	pthread_mutex_unlock(&m);
	
	return NULL;
}

int main(int argc, char* argv[]){
	pthread_t t[2];
	pthread_mutex_init(&mp, NULL);
	pthread_mutex_init(&m, NULL);
	
	pthread_create(&t[0], NULL, work, NULL);
	pthread_create(&t[1], NULL, work, NULL);
	pthread_join(t[0], NULL);
	pthread_join(t[1], NULL);
	pthread_mutex_destroy(&mp);
	pthread_mutex_destroy(&m);
	
	printf("gold at map: %d\n", a);
	printf("gold at center: %d\n", p);

	return 0;
}