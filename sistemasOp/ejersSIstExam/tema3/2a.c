
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>



pid_t pid1,pid2,pid3;
int fd;
char mensaje[] = "**P5 envia señal a P3**\n";
char mensaje1[] = "**P3 envia señal a P5**\n";

char mensaje2[] = "**Soy P6**\n";
void Salir(int sig)
{
	switch(sig)
	{
		case(SIGTERM):
			write(1,mensaje,strlen(mensaje));
			
		case(SIGUSR1):
			write(1,mensaje1,strlen(mensaje1));
		case(SIGINT):
		for(int i=0;i<strlen(mensaje2);i++)
		{
			sleep(1);
		
			write(1,&mensaje2[i],1);
			sleep(1);
		}
	break;
		
	}
}

void main()
{

	if(pid1=fork()==0)
	{	
		
		printf("P1 con PID %d y con PPID %d, \n",getpid(),getppid());
	}else if(pid1=fork()==0)
		{
			fd = open("fichero.txt", O_CREAT | O_RDWR,0666);
			printf("P2 con PID %d y con PPID %d\n",getpid(),getppid());
	}else if(pid1=fork()==0)
		{
			
			printf("P3 con PID %d y con PPID %d\n",getpid(),getppid());
			signal(SIGTERM, Salir);
			if(pid2=fork()==0){
				printf("P5(*HIJO P3*) con PID %d y con PPID %d\n",getpid(),getppid());
					kill(getppid(),SIGTERM);
					signal(SIGUSR1,Salir);
					sleep(3);
			}else{
				sleep(3);
				kill(pid3,SIGUSR1);
			}
	}else if(pid1=fork()==0)
		{
			printf("P4 con PID %d y con PPID %d\n",getpid(),getppid());
				
				if(pid3=fork()==0)
				{
					printf("P6(*HIJOP5*) con PID %d y con PPID %d\n",getpid(),getppid());
					signal(SIGINT,Salir);
				}
	}else{
			
	printf("PROCESO PADRE con PID %d y con PPID(hijo del main) %d\n",getpid(),getppid());
	}
	while(wait(NULL)>0);
}
