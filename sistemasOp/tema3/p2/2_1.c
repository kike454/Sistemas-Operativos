#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<signal.h>
#include <stdlib.h>
#include <stdio.h>

int variable=0;
void main()
{
	if(fork()==0)
	{
		variable++;
		printf("Soy el proceso P1 con PID %d, y con PPID %d \n", getpid(), getppid());
	}else if(fork()==0)
	{
		variable++;
		printf("Soy el proceso P2 con PID %d, y con PPID %d \n", getpid(), getppid());
	}else if(fork()==0)
	{
		variable++;
		printf("Soy el proceso P3 con PID %d, y con PPID %d \n", getpid(), getppid());
		if(fork()==0)
		{
			printf("Soy el proceso P5 con PID %d, y con PPID %d \n", getpid(), getppid());
		}
	}else if(fork()==0)
	{
		printf("Soy el proceso P4 con PID %d, y con PPID %d \n", getpid(), getppid());	
			execl("/bin/ls", "ls",(char *)0);
		if(fork()==0)
		{
			printf("Soy el proceso P6 con PID %d, y con PPID %d \n", getpid(), getppid());
		}	
	}else{
		printf("Soy el proceso PADRE con PID %d \n" ,getpid());
	}
	while(wait(NULL)>0){}
}
