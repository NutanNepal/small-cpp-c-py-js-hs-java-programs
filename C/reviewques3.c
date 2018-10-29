#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main(){
    int fd[2];
    pipe(fd);
    pid_t PPID, CPID, pii;

    if((CPID = fork())==0){
        close(fd[0]);
        pid_t x = getpid();
        write(fd[1], &x, sizeof(x));
    }
    else{
        close(fd[1]);
        read(fd[0], &pii, sizeof(pii));
        kill(pii, SIGKILL);
    }
    printf("p= %d, c= %d",getpid(), pii);
return 0;
}
