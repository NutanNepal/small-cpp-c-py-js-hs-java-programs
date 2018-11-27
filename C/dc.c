//producer consumer with cond variables
#include <stdio.h>
#include <pthread.h>
#define SIZE 10

int buffer;
pthread_mutex_t mutex;
pthread_cond_t condc, condp;

void *produce(){
	int i;
	pthread_mutex_lock(&mutex);	//lock:produce
	for(i = 1; i <= SIZE; i++){
		while(buffer != 0){
			//buffer is not empty so wait on consumer to eat it
			pthread_cond_wait(&condp, &mutex);
		}
		buffer = i;	//	you can seed and use rand
				// critical section data
		printf("produce %d\n", buffer);
		pthread_cond_signal(&condc);	
	}

	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);	
}

void *consume(){
	int i;
	pthread_mutex_lock(&mutex);
	for(i = 1; i <= SIZE; i++){
		while(buffer == 0){
			pthread_cond_wait(&condc, &mutex);
		}
		printf("consume %d\n", buffer);
		buffer = 0;
		pthread_cond_signal(&condp);
	}
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);

}

int main(){
	pthread_t cid, pid;
	pthread_mutex_init(&mutex, NULL);	//initializing mutex
	pthread_cond_init(&condc, NULL);	//initializing cond variables
	pthread_cond_init(&condp, NULL);	
	
	pthread_create(&pid, NULL, produce, NULL);	//creating threads
	pthread_create(&cid, NULL, consume, NULL);

	pthread_join(pid, NULL);
	pthread_join(cid, NULL);

	pthread_mutex_destroy(&mutex);	//destroying
	pthread_cond_destroy(&condc);
	pthread_cond_destroy(&condp);

return 0;	

}	
