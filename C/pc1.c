#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define size 5
#define num_size 10

int buffer[size];
sem_t sem_empty, sem_full;
int idx; int val;

void add(int value){
        if(idx<size){
                buffer[idx] = value;
                idx++;
        }
        else{
                printf("Overflow\n");
        }
}

void delete(){
        if(idx>=0){
                idx--;
        }
        else{
                printf("Underflow\n");
        }
}

void *producer(){
    int i;
        for(i=0; i<num_size; i++){
                sem_wait(&sem_empty);
                val = rand()%100; //add a random val less than 100
                add(val);
                printf("Produced: %d\n", buffer[idx]);
                sem_post(&sem_full);
                printf("Produced: %d\n", val);
        }
    pthread_exit(NULL);
}

void *consumer(){
int i;
    for(i=0; i<num_size; i++){
            sem_wait(&sem_full);
                delete();
                //printf("Consumed: %d\n", buffer[idx]);
                sem_post(&sem_empty);
                printf("Consumed: %d\n", val);
        }
pthread_exit(NULL);
}

int main(){
pthread_t cid, pid;
idx=0;
sem_init(&sem_empty, 1, 1);
sem_init(&sem_full, 1, 0);

pthread_create(&pid,NULL, producer,NULL);
pthread_create(&cid, NULL, consumer, NULL);

pthread_join(pid, NULL);
pthread_join(cid, NULL);

pthread_exit(NULL);
}
