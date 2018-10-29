#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main(){
	pid_t BPID, CPID, DPID, EPID, FPID;		//child pid
	pid_t PPID = getpid(); 	//parent pid

	if((PPID = fork()) == 0){
		printf("This is B with %d\n", ( BPID = getpid()));
        if((PPID = fork()) == 0){
		    printf("This is D with %d\n", (DPID = getpid()));    
	    }
        else{
            if((PPID = fork()) == 0){
		        printf("This is E with %d\n", ( EPID = getpid()));    
	        }
            else{
                if((PPID = fork()) == 0){
		            printf("This is F with %d\n", ( FPID = getpid()));    
	            }
                else{
                    sleep(5);
                    kill(DPID, SIGKILL);
                    printf("We killed D\n");
                    kill(EPID, SIGKILL);
                    printf("We killed E\n");
                    kill(FPID, SIGKILL);
                    printf("We killed F\n");
                }
            }
        }
	}
    else{
		printf("This is A with %d\n", getpid());
        if((PPID = fork()) == 0){
		    printf("This is C with %d\n", (CPID = getpid()));
	    }
        else{
            sleep(10);
            kill(BPID, SIGKILL);
            kill(CPID, SIGKILL);
            printf("We killed B and C\n");
        }
    }
    return 0;
}
