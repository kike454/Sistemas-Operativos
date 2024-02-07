#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void main(int argc, char *argv[])
{

	pid_t pid1, pid2;
	if(pid1=fork()==0)	
	{
		if(pid2=fork()==0)
		{
			printf("Soy el nieto con PID %d y con PPID %d\n",getpid(),getppid());
			
	}else{
		printf("soy el padre con PID%d y con PPID %d\n",getpid(),getppid());
		

	}
	}else{
		printf("Soy el abuelo con PID %d y con PPID(hijo de main) %d\n",getpid(),getppid());
		execl("/bin/ls","ls",(char*)0); 
		}
		while(wait(NULL)>0);

}
