#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

pthread_mutex_t check_mutex;
int M[10][10]={};
int row=0;

void *thread_fun(void* arg_t){
  
  int *col=(int*) arg_t;

  if(M[row][(*col)]==0){
    printf("o");
  }
  if(M[row][(*col)]==1){
    printf("x");
  }
  
  pthread_exit((void *)col);
}

int main(){
  int N;
  int i, j, k; 
  void *status;
  printf("Enter a number: ");
  scanf("%d", &N);
  pthread_t TH[N];
  int arg[N];
  if(N>0 && N<=10){
    printf("Number of threads we are going to create: %d\n", N);
    for(i=0; i<N; i++){
      for(j=0; j<N; j++){
        M[i][j]=rand()%2; 
      }
    }

    for(i=0; i<N; i++){
      for(j=0; j<N; j++){
        printf("%d", M[i][j]);
      }
      printf("\n");
    }

    printf("\n \n \n");
 
    for(i=0; i<N; i++){
      for(j=0; j<N; j++){
	arg[j]=j;
	pthread_mutex_lock(&check_mutex);/*write instruction to lock*/
        pthread_create(&TH[j], NULL, thread_fun, (void*)&arg[j]);/*correct this line (pass argument properly)*/
	pthread_mutex_unlock(&check_mutex);/*write instruction to unlock*/
      }
	for (k=0;k<N;k++){
		pthread_join(TH[k],&status);   
	}
	row=row+1;     
      printf("\n");
    }
  }

  pthread_exit(NULL);
  return 0;
}
