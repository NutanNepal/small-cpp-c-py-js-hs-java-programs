#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char input[15][30];
	int argnum, i;
    for (argnum=0; (scanf("%s",&input[argnum]))==1;argnum++)
			if (getchar()=='\n') break;

    if (strcmp(input[0],"exec")==0 && argnum!=0) {
        
		for (i=1; i<=argnum; i++) exec(input[i]);
    }
}