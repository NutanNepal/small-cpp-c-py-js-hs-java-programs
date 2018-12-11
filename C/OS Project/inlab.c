#include <stdio.h>

int main()
{
    char input[15][30];
	int argnum, i; //= "exec p(10,100) p(2,3,1)";
	
    
    
    printf("\n:( => ");
    
    for (argnum=0; (scanf("%s",&input[argnum]))==1;argnum++)
			if (getchar()=='\n') break;
	
	printf("%s\n", input[1][2]);
	char* inp[10];
	
    printf("\n:( => ");
    printf("\n:( => %s, %s, %d", input[1], input[2], argnum);
    
    /*for(i = 0; i < 15; i++){
            inp[i] = (char *)malloc(10 * sizeof(char));      //allocate
    }*/
    printf("\n:( ):");
    
    //for (i=1; i<=argnum; i++) inp[i-1]  = input[i];          //assign
    
    int j, k;
    char *args[10][10];                                         //2d array to store

    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
    		args[i][j]=(char *)malloc(10*sizeof(char));
    	}
    }
    printf("\n:( =>");
    
    for(i = 1; i < 10; i++){
        char *temp;

    	strcpy(args[i][0],strtok(inp[i][0],"(,"));
    	for (j=1; (temp=strtok(NULL,",)"))!=NULL; j++) 
    		strcpy(args[i][j], temp);
    	printf("\n");
    }
    
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
    		printf("%s", args[i][j]);
    	}
    	printf("\n");
    }
    
    return 0;
}