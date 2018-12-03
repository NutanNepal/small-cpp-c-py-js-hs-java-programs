#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int fd[2];
    pipe(fd);
    pid_t child = fork();

    if (child == 0){
        srand(time(NULL));
        int random = rand() % 100;
        write(fd[1], &random, sizeof(random));
        int flag2;
        read(fd[0], &flag2, sizeof(flag2));
        if (flag2 == 0){
            printf("My parent says that the number is prime.");
        }
        else{
            printf("My parent says that the number is composite.");
        }
    }
    else{
        int num;
        read(fd[0], &num, sizeof(num));
        printf("MY child sent me %d\n", num);
        int flag = 0;
        int i;
        for(i = 1; i < num; i++){
            if (num % i == 0){
                flag = 1;
            }
        }
        write(fd[1], &flag, sizeof(flag));
    }
    return 0;
}