#include <unistd.h> 
#include <stdio.h> 
#include <signal.h>

  int main() {
    pid_t APID, BPID, CPID, DPID, EPID, FPID, GPID, HPID;
    pid_t PPID = getpid();
    if ((PPID = fork()) == 0) {
      printf("Process A %d\n", (APID = getpid()));
      printf("Parent of A has ppid %d\n", getppid());
      if ((PPID = fork()) == 0) {
        printf("Process C %d\n", (CPID = getpid()));;
        printf("Parent of C has ppid %d\n", getppid());
        if ((PPID = fork()) == 0) {
          printf("Process F %d\n", (FPID = getpid()));;
          printf("Parent of F has ppid %d\n", getppid());
        } 
        else {
          sleep(10);
          kill(FPID, SIGKILL);
        }
      } 
      else {
        if ((PPID = fork()) == 0) {
          printf("Process B %d\n", (BPID = getpid()));
          printf("Parent of B has ppid %d\n", getppid());
          if ((PPID = fork()) == 0) {
            printf("Process E %d\n", (EPID = getpid()));
            printf("Parent of E has ppid %d\n", getppid());
            if ((PPID = fork()) == 0) {
              printf("Process G %d\n", (GPID = getpid()));
              printf("Parent of G has ppid %d\n", getppid());
            } 
            else {
              if ((PPID = fork()) == 0) {
                printf("Process H %d\n", (HPID = getpid()));;
                printf("Parent of H has ppid %d\n", getppid());
              } 
              else {
                sleep(5);
                kill(GPID, SIGKILL);
                kill(HPID, SIGKILL);
              }
            }
          } 
          else {
            if (fork() == 0) {
              printf("Process D %d\n", (DPID = getpid()));;
              printf("Parent of D has ppid %d\n", getppid());
            } 
            else {
              sleep(10);
              kill(DPID, SIGKILL);
              kill(EPID, SIGKILL);
            }
          } 
        }
        else {
            sleep(15);
            kill(BPID, SIGKILL);
            kill(CPID, SIGKILL);
            printf("A:pid = %d\n", getpid());
        }
      }
    } 
    else {
        kill(APID, SIGKILL);
    }
    return 0;
}