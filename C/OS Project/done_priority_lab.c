#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "queue.h"


int fg_pid = 0;
int fg_suspended = 0;
int run = 1;
struct queue pid_list;

void help() {
	printf("This is manual page\n");
	printf("This shell supports the following commands:\n");
	printf("\tver\n\texec\n\tps\n\tkill\thelp\n\texit\n");
	printf("For more details please type 'help command'\n");
}

void helpcmd(char *cmd) {
	printf("This is manual page\n\n");
	if (strcmp(cmd, "ver") == 0)
	{
		printf("\nver:\tShows details about the shell version\n");
	}
	else if (strcmp(cmd, "exec" == 0))
	{
		printf("\nexec p1(n1,qt1) p2(n2,qt2) ...:\nExecutes the programs p1, p2 ...\nEach program types a message for n times and it is given a time quantum of qt msec.\n");
		printf("If parameter (&) is given the program will be executed in the background\n");
	}
	else if (strcmp(cmd, "ps") == 0)
	{
		printf("\nps:\tShows the living process with the given pid\n");
	}
	else if (strcmp(cmd, "kill") == 0)
	{
		printf("\nkill pid:\tEnds the process with the given pid\n");
	}
	else if (strcmp(cmd, "help") == 0)
	{
		printf("\nhelp:\tYou should know this command by now\n");
	}
	else if (strcmp(cmd, "exit") == 0)
	{
		printf("\nexit:\tEnds the experience of working in the new shell\n");
	}
	else
	{
		printf("\nNo Such command. Type help to see a list of commands\n");
	}
}

void ver() {
	printf("\nNew Shell. Works properly!!\n");
}

void ps() {
	struct node *p;
	printf("\nNEW SHELL presents the following living processes\n");
	printf("\tPID\tNAME\n");
	for (p = pid_list.head; p != NULL; p = p->next)
	{
		printf("\t%d\t%s\n", p->pid, p->name);
	}
}

void mykill(int pid) {
	kill(pid, SIGTERM);
	printf("You have just killed process %d\n", pid);
}

void exec(char *input) { //input is in the form p(10,20,5,&)
	int i, t, status;
	char *args[10];
	char *temp;
	struct node *p;

	for (i = 0; i < 10; i++)
	{
		args[i] = (char *)malloc(10 * sizeof(char));
	}

	strcpy(args[0], strtok(input, "(,"));
	for (i = 1; (temp = strtok(NULL, ",)")) != NULL; i++)
		strcpy(args[i], temp);
	printf("\n");
	if (strcmp(args[i - 1], "&") == 0)
	{
		args[i - 1] = NULL;
	}
	else
		args[i] = NULL;
	if ((t = fork()) == 0)
	{
		execv(args[0], args);
	}
	enqueue(t, args[0], &pid_list);
	if (args[i - 1] != NULL)
	{
		fg_pid = t;
		while (fg_pid != 0 && fg_suspended != 1)
			pause();
	}

}

void myexit() {
	char yesno;
	if (pid_list.head == pid_list.tail)
	{
		run = 0;
	}
	else {
		printf("There are still living processes Do you want to kill them? (y/n): ");
		yesno = getchar();
		if (yesno == 'y')
		{
			while (pid_list.head != pid_list.tail)
			{
				mykill(pid_list.tail->pid);
				usleep(10000);
			}
			run = 0;
		}
	}
}

void childdead(int signum) {
	int dead_pid, status;

	dead_pid = wait(&status);
	printf("The child %d is dead\n", dead_pid);

	delete(&pid_list, dead_pid);
	printf("\n");
	if (dead_pid == fg_pid)
	{
		fg_pid = 0;
	}
}

void susp(int signum) {
	fg_suspended = 1;
	printf("All processes supspended\n");
}

void cont(int signum) {
	fg_suspended = 0;
	printf("Waking all processes...\n");
	while (fg_pid != 0 && fg_suspended != 1)
		pause();
}

int main(int argc, char const *argv[])
{
	char input[15][30];
	int argnum, i;

	pid_list.head = NULL;
	pid_list.tail = NULL;
	enqueue(getppid(), "NEW SHELL", &pid_list);

	signal(SIGCHLD, childdead);
	signal(SIGTSTP, susp);
	signal(SIGQUIT, cont);
	setpriority(PRIO_PROCESS, 0, -20);

	ver();

	while (run) {
		printf("=>");
		for (argnum = 0; (scanf("%s", &input[argnum])) == 1; argnum++)
			if (getchar() == '\n') break;
		if (strcmp(input[0], "ver") == 0 && argnum == 0) ver();
		else if (strcmp(input[0], "help") == 0 && argnum == 0) help();
		else if (strcmp(input[0], "help") == 0 && argnum == 1) helpcmd(input[argnum]);
		else if (strcmp(input[0], "ps") == 0 && argnum == 0) ps();
		else if (strcmp(input[0], "kill") == 0 && argnum == 1) mykill(atoi(input[1]));
		else if (strcmp(input[0], "exec") == 0 && argnum != 0)
			for (i = 1; i <= argnum; i++) exec(input[i]);

		else if (strcmp(input[0], "ep") == 0 && argnum != 0) {
			int t, j, k = 0, prio = 0;
			char *args[argnum][10];
			for (i = 0; i < argnum; i++) {
				for (j = 0; j<10; j++) {
					args[i][j] = (char *)malloc(10 * sizeof(char));
				}
			}
			for (i = 1; i <= argnum; i++) {
				char *temp;
				strcpy(args[i - 1][0], strtok(input[i], "(,"));
				for (j = 1; (temp = strtok(NULL, ",)")) != NULL; j++)
					strcpy(args[i - 1][j], temp);
			}
			for (i = 0; i < argnum; i++) {
				for (j = 0; j < 10; j++) {
					printf("%s\t", args[i][j]);
				}
				printf("\n");
			}
			while (k < argnum) {
				for (i = 0; i < argnum; i++) {
					if (atoi(args[i][3]) == prio) {
                        t = fork();
                        enqueue(t, args[i][0], &pid_list);
						if (t==0){
						    execl(args[i][0], args[i][0], args[i][1], args[i][2], (char*) NULL);
                        }
                        k++;
                        fg_pid=t;
                        while (fg_pid!=0 && fg_suspended != 1){
                            pause();
                        }
					}
				}
				prio++;
			}
		}

		else if (strcmp(input[0], "er") == 0 && argnum != 0) {
			int quanta;
			printf("Please enter the time slice: ");
			scanf("%d", &quanta);
			int j, k = 0;
			char *args[argnum][10];
			for (i = 0; i < argnum; i++) {
				for (j = 0; j<10; j++) {
					args[i][j] = (char *)malloc(10 * sizeof(char));
				}
			}

			for (i = 1; i <= argnum; i++) {
				char *temp;
				strcpy(args[i - 1][0], strtok(input[i], "(,"));
				for (j = 1; (temp = strtok(NULL, ",)")) != NULL; j++)
					strcpy(args[i - 1][j], temp);
			}

            int pid[argnum], child;

            for (i = 0; i < argnum; i++){
                if((child == fork())==0){
                    execl(args[i][0], args[i][0], args[i][1], args[i][2], (char*) NULL);
                    exit(0);
                }
                else{
                    enqueue((int)child, args[i][0], &pid_list);
                    sleep(1);
                    pid[i] = child;
                }
            }

            int pass_time = 0, total_time = 0;
            int start_time[argnum];
            float execution_time[argnum];
            float remaining_time[argnum];
            for(i = 0; i < argnum; i++){
                start_time[i] = 0;
                execution_time[i] = atoi(args[i][1]) * atoi(args[i][2]);
                remaining_time[i] = execution_time[i];
                total_time += execution_time[i];
            }

            while (pass_time < total_time){
                for (j = 0; j < argnum; j++){
                    if (pass_time < start_time[j]){
                        continue;
                    }
                    else if (remaining_time[j] <= 0){
                        continue;
                    }
                    else if (remaining_time[j] >= quanta){
                        kill(pid[j], SIGCONT);
                        usleep(quanta*1000000);
                        kill(pid[j], SIGTSTP);
                        pass_time += quanta;
                        remaining_time[j] -= quanta;
                    }
                    else{
                        kill(pid[j], SIGCONT);
                        usleep(remaining_time[j] * 1000000);
                        kill(pid[j], SIGTSTP);
                        pass_time += remaining_time[j];
                        remaining_time[j] = 0;
                    }
                }
            }
		}
		else if (strcmp(input[0], "exit") == 0 && argnum == 0) myexit();
		else printf("Nosuch command. Check help for help.\n");
	}
}