#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int gold_available = 100;
int gold_center = 0;
pthread_mutex_t m_gold_a;
pthread_mutex_t m_gold_c;

void deliver(){
	pthread_mutex_lock(&m_gold_c);
	gold_center += 10;
	printf("gold at center: %d\n", gold_center);
	pthread_mutex_unlock(&m_gold_c);
}

void mine(){
	while(1){
		pthread_mutex_lock(&m_gold_a);
		if(gold_available < 1) break;
		printf("gold at map: %d\n", gold_available);
		gold_available -= 10;
		pthread_mutex_unlock(&m_gold_a);
		deliver();
	}
}

void* work(void* arg){
	int i;
	
	mine();
	
	return NULL;
}

int main(int argc, char* argv[]){
	pthread_t t[2];
	pthread_mutex_init(&m_gold_a, NULL);
	pthread_mutex_init(&m_gold_a, NULL);
	
	pthread_create(&t[0], NULL, work, NULL);
	pthread_create(&t[1], NULL, work, NULL);
	pthread_join(t[0], NULL);
	pthread_join(t[1], NULL);
	pthread_mutex_destroy(&m_gold_a);
	pthread_mutex_destroy(&m_gold_c);
	
	printf("gold at map: %d\n", gold_available);
	printf("gold at center: %d\n", gold_available);

	return 0;
}