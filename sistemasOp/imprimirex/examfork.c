#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<signal.h>
#include <stdlib.h>

void Salir(int sig)
{
	switch(sig){


		case(SIGUSR1):
		printf("P1->P2\n");

		case(SIGTERM):
		printf("P3->P1\n");

		break;
	
	}
}
void main()
{
	pid_t pid1,pid2;
	if(pid1=fork()==0){
		printf("Soy P1 con pid %d y cn ppid %d\n",getpid(),getppid());
			sleep(1);
			signal(SIGUSR1,Salir);

		if(pid2=fork()==0){
			printf("Soy P2 con pid %d y con ppid %d\n",getpid(),getppid());
			
			signal(SIGTERM,Salir);
	
		
		}else if(fork()==0){
			printf("Soy P3 con pid %d y con ppid %d\n",getpid(),getppid());
			kill(getppid(),SIGUSR1);
		}else{
			sleep(3);
			kill(pid2,SIGTERM);
		}
	
	}else{
		printf("Proceso padre con pid %d\n",getpid());
		
	}
	while(wait(NULL)>0){
	}

}
