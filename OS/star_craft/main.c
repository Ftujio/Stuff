#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define MAP_MINERALS 100

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

pthread_mutex_t m_worker_num;

void train_soldier(){

}

void traint_worker(){

}

void transport(int id){
	printf("SCV %d is transporting minerals\n", id);
	sleep(2);
}

void deliver(int id){
	printf("SCV %d delivered minerals to Command center\n", id);
	center_minerals += 8;
}

void mine(int id){
	printf("SCV %d is mining\n", id);
	map_minerals -= 8;
}

void* work(void* args){
	int id = *(int*)args;
	while(1){
		pthread_mutex_lock(&m_map);
		if(map_minerals >= 8){
			mine(id);
			transport(id);
		} else {
			pthread_mutex_unlock(&m_map);
			break;
		}
		pthread_mutex_unlock(&m_map);

		pthread_mutex_lock(&m_center);
		deliver(id);
		pthread_mutex_unlock(&m_center);
	}

}

void create_threads(pthread_t* threads, int num){ // "num" should be passed as "WORKER_START_NUM"
	int i;
	for(i = 0; i < num; i++){
		pthread_create(threads + i, NULL, work, (void*)&i);

		pthread_mutex_lock(&m_worker_num);
		worker_num++;
		pthread_mutex_unlock(&m_worker_num);
	}
}

void create_new_thread(pthread_t* thread, int thread_id){ // "id" should be passed as "worker_num"
	pthread_create(thread, NULL, work, (void*)&thread_id);
}

void finish_game(pthread_t* threads, int num){ // "num" should be passed as "worker_num"
	int i;
	for(i = 0; i < num; i++){
		pthread_join(*threads + i, NULL);
	}
	printf("Game finshed!\n");
}

void run_game(){
	pthread_t workers[WORKER_START_NUM];
	pthread_t* p_workers = workers;

	create_threads(p_workers, WORKER_START_NUM);
	finish_game(p_workers, worker_num);
}

void setup_stuff(){
	pthread_mutex_init(&m_map, NULL);
	pthread_mutex_init(&m_center, NULL);

	run_game();

	pthread_mutex_destroy(&m_map);
	pthread_mutex_destroy(&m_center);
}

int main(int argc, char* argv[]){
	setup_stuff();

	return 0;
}