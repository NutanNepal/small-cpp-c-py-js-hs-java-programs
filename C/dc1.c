//producer consumer with cond variables
#include <stdio.h>
#include <pthread.h>
#define SIZE 20

int count = 0;
pthread_mutex_t mutex;
pthread_cond_t condc, condd;

void *client(){
	int _;
	pthread_mutex_lock(&mutex);	//lock:produce
    for(_=0; _<200; _++){
        while(count > SIZE){
                //buffer is not empty so wait on consumer to eat it
                pthread_cond_wait(&condc, &mutex);
        }
        printf("adding clients...");
        count++;	//	you can seed and use rand
                    // critical section data
        printf("total clients: %d\n", count);
        pthread_cond_signal(&condd);
    }
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);	
} 

void *detective(){
	int _;
	pthread_mutex_lock(&mutex);
    for(_ = 0; _<200; _++){
        while(count == 0){
            printf("no client!");
            pthread_cond_wait(&condd, &mutex);
        }
        printf("taking %d clients away %d", count);
        count = 0;
        pthread_cond_signal(&condc);
    }
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);

}

int main(){
	pthread_t cid, did;
	pthread_mutex_init(&mutex, NULL);	//initializing mutex
	pthread_cond_init(&condc, NULL);	//initializing cond variables
	pthread_cond_init(&condd, NULL);	
	
	pthread_create(&cid, NULL, client, NULL);	//creating threads
	pthread_create(&did, NULL, detective, NULL);

	pthread_join(did, NULL);
	pthread_join(cid, NULL);

	pthread_mutex_destroy(&mutex);	//destroying
	pthread_cond_destroy(&condc);
	pthread_cond_destroy(&condd);

return 0;	

}	
