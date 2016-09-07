#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define MAP_MINERALS 500

#define WORKER_START_NUM 5
#define MAX_WORKERS 200
#define WORKER_TRAINED_MESSAGE "SCV good to go, sir."

#define SOLDIER_WIN_NUM 20
#define SOLDIER_TRAIN_COST 50
#define SOLDIER_TRAINED_MESSAGE "You wanna peace of me boy?"

// Map and center resources variables
int map_minerals = MAP_MINERALS;
int center_minerals = 0;

// Other variables
int soldier_num = 0;
int worker_num = 0;

// Mutexes
pthread_mutex_t m_map;
pthread_mutex_t m_center;

pthread_mutex_t m_worker_num;
pthread_mutex_t m_soldier_num;

void transport(int id){
	printf("SCV %d is transporting minerals\n", id);
	sleep(2);
}

void deliver(int id, int minerals){
	printf("SCV %d delivered minerals to Command center\n", id);
	center_minerals += minerals;
}

void mine(int id){
	printf("SCV %d is mining\n", id);
	map_minerals -= 8;
}

void* work(void* arg){
	int id = *(int*)arg, dig;
	int mined = 0;
	
	free(arg);

	while(1){
		pthread_mutex_lock(&m_soldier_num);
		if(soldier_num >= 20){
			pthread_mutex_unlock(&m_soldier_num);
			break;
		}
		pthread_mutex_unlock(&m_soldier_num);

		dig = 0;
		pthread_mutex_lock(&m_map); 
		if(map_minerals >= 8){
			mine(id);
            mined = 8;
			dig = 1;
		} else if(map_minerals > 0 && map_minerals < 8){
            mined = map_minerals;
			map_minerals = 0;
			dig = 1;
			pthread_mutex_unlock(&m_map);
		} else {
			pthread_mutex_unlock(&m_map);
			break;
		}
		pthread_mutex_unlock(&m_map);

		if(dig) {
            transport(id);

		    pthread_mutex_lock(&m_center);
		    deliver(id, mined);
		    pthread_mutex_unlock(&m_center);
        }
	}

	return NULL;
}

void create_new_thread(pthread_t *thread, int thread_id){ // "id" should be passed as "worker_num"
	int* id = malloc(sizeof(int));
	*id = thread_id;
	pthread_create(&thread[worker_num], NULL, work, (void*)id);

	pthread_mutex_lock(&m_worker_num);
	pthread_mutex_lock(&m_center);
	if(center_minerals > 8){
		worker_num++;
		center_minerals -= 8; 
	} else {
		printf("Not enough minerals to create worker! RIPUU\n");
	}
	pthread_mutex_unlock(&m_center);
	pthread_mutex_unlock(&m_worker_num);
}

void* get_command(void* arg){
	char input;

    pthread_t *threads = (pthread_t*)arg;
	while(1){
		scanf("%c", &input);

		pthread_mutex_lock(&m_soldier_num);
		if(soldier_num < 20){
			pthread_mutex_unlock(&m_soldier_num);
			if(input == 's'){
				create_new_thread(threads, worker_num);
			} else if(input == 'm'){
				pthread_mutex_lock(&m_soldier_num);
				pthread_mutex_lock(&m_center);
				if(center_minerals > 8){
					soldier_num++;
					center_minerals -= 8;
				} else {
					printf("Not enough minerals to create soldier! RIPUU\n");
					
					pthread_mutex_unlock(&m_center);
					pthread_mutex_unlock(&m_soldier_num);

					break;
				}
				printf("number of soldiers: %d\n", soldier_num); // This is for debugging
				pthread_mutex_unlock(&m_center);
				pthread_mutex_unlock(&m_soldier_num);
			}
		} else if(map_minerals == 0 && center_minerals < 8){

		} else {
			pthread_mutex_unlock(&m_soldier_num);
			break;
		}
	}

	return NULL;
}

void create_threads(pthread_t* threads, int num, pthread_t* scan){ // "num" should be passed as "WORKER_START_NUM"
	int i;
	
	for(i = 0; i < num; i++){
        int* id = malloc(sizeof(int));
		*id = i;
		pthread_create(&threads[i], NULL, work, (void*)id);
		pthread_mutex_lock(&m_worker_num);
		worker_num++;
		pthread_mutex_unlock(&m_worker_num);
	}

	pthread_create(scan, NULL, get_command, threads);
}

void finish_game(pthread_t* threads, int num){ // "num" should be passed as "worker_num"
	int i;
	//printf("NUM OF THREADS TO WAIT FOR: %d\n", num);

	for(i = 0; i < num; i++){
		pthread_join(threads[i], NULL);
	}
	printf("number of soldiers: %d\n", soldier_num); // This is for debugging

	if(soldier_num >= 20){
		printf("You win!\n");
	} else {
		printf("You loose!\n");
	}
}

void run_game(){
	pthread_t workers[200], scan;
	pthread_t* p_workers = workers;

	create_threads(p_workers, WORKER_START_NUM, &scan);

    pthread_join(scan, NULL);

	finish_game(p_workers, worker_num);
}

void setup_stuff(){
	pthread_mutex_init(&m_map, NULL);
	pthread_mutex_init(&m_center, NULL);
	pthread_mutex_init(&m_worker_num, NULL);
	pthread_mutex_init(&m_soldier_num, NULL);

	run_game();

	pthread_mutex_destroy(&m_map);
	pthread_mutex_destroy(&m_center);
	pthread_mutex_destroy(&m_worker_num);
	pthread_mutex_destroy(&m_soldier_num);
}

int main(int argc, char* argv[]){
	setup_stuff();

	printf("minerals at map: %d\n", map_minerals); // This is for debugging
	printf("minerals at center: %d\n", center_minerals); // This is for debugging

	printf("number of workers: %d\n", worker_num); // This is for debugging
	printf("number of soldiers: %d\n", soldier_num); // This is for debugging

	return 0;
}