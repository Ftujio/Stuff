#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define MAP_MINERALS 5000

#define WORKER_START_NUM 5
#define MAX_WORKERS 200
#define WORKER_TRAINED_MESSAGE "SCV good to go, sir."

#define SOLDIER_WIN_NUM 20
#define SOLDIER_TRAIN_COST 50
#define SOLDIER_TRAINED_MESSAGE "You wanna peace of me boy?"

// Map and center resources variables
int map_minerals = MAP_MINERALS, center_minerals = 0;

// Other variables
int soldier_num = 0;
int worker_num = WORKER_START_NUM;

// Mutexes
pthread_mutex_t m_map;
pthread_mutex_t m_center;

void train(){

}

void transport(){
	printf("SCV N is transporting minerals\n");
	sleep(2);
}

void deliver(){
	printf("SCV N delivered minerals to Command center\n");
	center_minerals += 8;
}

void mine(){
	printf("SCV N is mining\n");
	map_minerals -= 8;
}

void* work(void* args){

}

void run_threads(pthread_t* thread, int num){
	int i;
	for(i = 0; i < num; i++){
		pthread_create(thread + i, NULL, work, NULL);
	}
}

void run_new_thread(){
	
}

void finish_game(int num){
	//pthread_mutex_join();
}

void setup_stuff(){
	pthread_t workers[WORKER_START_NUM];
	pthread_t* p_workers = workers;

	pthread_mutex_init(&m_map, NULL);
	pthread_mutex_init(&m_center, NULL);

	run_threads(p_workers, WORKER_START_NUM);

	pthread_mutex_destroy(&m_map);
	pthread_mutex_destroy(&m_center);
}

int main(int argc, char* argv[]){

	return 0;
}