#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define size 10
#define num_size 20

int buffer1[size], buffer2[size], buffer3[size];
sem_t sem_empty1, sem_full1, sem_empty2, sem_empty3, sem_full2, sem_full3;
int idx[3] = {0, 0, 0};
int val;

void add(int value, int buffer[], int i){
    if(idx[i]<size){
        buffer[idx[i]] = value;
        idx[i]++;
    }
    else{
        printf("Overflow\n");
    }
}

void delete(int i){
    if(idx[i]>=0){
        idx[i]--;
    }
    else{
        printf("Underflow\n");
    }
}

void *pth1(){
    int i;
    for(i=0; i<num_size; i++){
        sem_wait(&sem_empty1);
        val = rand()%100; //add a random val less than 100
        printf("thread 1 Produced: %d\n", val);
        add(val, buffer1, 1);
        sem_post(&sem_full1);
    }
    pthread_exit(NULL);
}

void *pth2(){
    int i;
    for(i=0; i<num_size; i++){
        sem_wait(&sem_empty2);
        val = rand()%100; //add a random val less than 100
        printf(" thread 2 Produced: %d\n", val);
        add(val, buffer2, 2);
        sem_post(&sem_full2);
    }
    pthread_exit(NULL);
}

void *pth3(){
    int i;
    for(i=0; i<num_size; i++){
        sem_wait(&sem_empty3);
        val = rand()%100; //add a random val less than 100
        printf("thread 3 Produced: %d\n", val);
        add(val, buffer3, 3);
        sem_post(&sem_full3);
    }
    pthread_exit(NULL);
}

void *consumer(){
    int i;
    for(i=0; i<num_size; i++){
        sem_wait(&sem_full1);
        delete(1);
        sem_post(&sem_empty1);
        printf("Consumed from 1: %d\n", val);
    }
    for(i=0; i<num_size; i++){
        sem_wait(&sem_full2);
        delete(2);
        sem_post(&sem_empty2);
        printf("Consumed from 2: %d\n", val);
    }
    for(i=0; i<num_size; i++){
        sem_wait(&sem_full3);
        delete(3);
        sem_post(&sem_empty3);
        printf("Consumed: %d\n", val);
    }
    pthread_exit(NULL);
}

int main()
{
int i = 3;
pthread_t cid, pid[i];
sem_init(&sem_empty1, 1, 1);
sem_init(&sem_full1, 1, 0);
sem_init(&sem_empty2, 1, 1);
sem_init(&sem_full2, 1, 0);
sem_init(&sem_empty3, 1, 1);
sem_init(&sem_full3, 1, 0);

pthread_create(&pid[0],NULL, pth1,NULL);
pthread_create(&pid[1],NULL, pth2,NULL);
pthread_create(&pid[2],NULL, pth3,NULL);

pthread_create(&cid, NULL, consumer, NULL);

for( i = 0; i < 3; i++){
    pthread_join(pid[i], NULL);
}
pthread_join(cid, NULL);

pthread_exit(NULL);
}