
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void main(){

	pid_t pid1,pid2,pid3;
	int variable=0;
	if(pid1=fork()==0)
	{	
		variable++;
		printf("P1 con PID %d y con PPID %d, %d valor variable\n",getpid(),getppid(),variable);
	}else if(pid1=fork()==0)
		{
			variable++;
			printf("P2 con PID %d y con PPID %d, %d variable\n",getpid(),getppid(),variable);
	}else if(pid1=fork()==0)
		{
			variable++;
			printf("P3 con PID %d y con PPID %d, %d varibale\n",getpid(),getppid(),variable);
			if(pid2=fork()==0){
				printf("P5(*HIJO P3*) con PID %d y con PPID %d\n",getpid(),getppid());
			}
	}else if(pid1=fork()==0)
		{
			printf("P4 con PID %d y con PPID %d\n",getpid(),getppid());
				execl("/bin/ls", "ls",(char*)0);
				if(pid3=fork()==0)
				{
					printf("(P6(*HIJOP5*) con PID %d y con PPID %d\n",getpid(),getppid());
				}
	}else{
			
	printf("PROCESO PADRE con PID %d y con PPID(hijo del main) %d\n",getpid(),getppid());
	}
	while(wait(NULL)>0);
}
