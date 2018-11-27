#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<signal.h>
#define num_thrds 2

void *thread_fun_P0(){
  while(1){
    while(turn!=0){
      /*do nothing */
    }
    /*critical section*/
	
    turn=1;
  }
  pthread_exit(NULL);
}

void *thread_fun_P1(){
  while(1){
    while(turn!=1){
      /*do nothing */
    }
    /*critical section*/
    turn=0;
  }
  pthread_exit(NULL);
}

int main(){
  pthread_t tid[num_thrds]; int i;
  
  for(i=0;i<num_thrds;i++){
    if(i==0){
      pthread_create(&tid[i],NULL,thread_fun_P0,NULL);
    }
    else{
      pthread_create(&tid[i],NULL,thread_fun_P1,NULL);
    }
  }
  
  for(i=0;i<num_thrds;i++){
    pthread_join(tid[i],NULL);
  }
  pthread_exit(NULL);
}