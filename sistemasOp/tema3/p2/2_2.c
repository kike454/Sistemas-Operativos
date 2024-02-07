#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<signal.h>
#include <stdlib.h>
#include <stdio.h>

char mensaje[] = ("Soy P6 \n");
int fd;
void func_1(int sig)
{
	switch(sig){
		case(SIGTERM):
	write(1,"Soy el proceso P3 y he recibido una señal del proceso P5 \n",59);
		case(SIGUSR1):
	write(1,"He recibido una señal de mi proceso padre\n",59);
		case(SIGINT):
	for(int i=0;i<= strlen(mensaje);i++){
		sleep(1);
		write(1,&mensaje[i],1);
	}
	break;
	}
}

void main()
{
	if(fork()==0)
	{
		
		printf("Soy el proceso P1 con PID %d, y con PPID %d \n", getpid(), getppid());
	}else if(fork()==0)
	{
		fd = open("archivo.txt", O_CREAT | O_RDWR, 0666);
		printf("Soy el proceso P2 con PID %d, y con PPID %d \n", getpid(), getppid());
	}else if(fork()==0)
	{
		
		printf("Soy el proceso P3 con PID %d, y con PPID %d \n", getpid(), getppid());
		signal(SIGTERM, func_1);//p5 -> P3
		int identificador = fork();
		if(identificador==0)
		{	
			printf("Soy el proceso P5 con PID %d, y con PPID %d \n", getpid(), getppid());
			
			kill(getppid(), SIGTERM);//p5 -> p3
			sleep(3);
			signal(SIGUSR1, func_1);//p3 -> p5
		}else{
			sleep(3);
			kill(identificador,SIGUSR1);//p3 -> p5, solo entra el proceso3	
		}
	}else if(fork()==0)
	{
		printf("Soy el proceso P4 con PID %d, y con PPID %d \n", getpid(), getppid());	
			execl("/bin/ls", "ls",(char *)0);
		if(fork()==0)
		{
			printf("Soy el proceso P6 con PID %d, y con PPID %d \n", getpid(), getppid());
			signal(SIGINT, func_1);
		}	
	}else{
		printf("Soy el proceso PADRE con PID %d \n" ,getpid());
	}
	while(wait(NULL)>0){}
}
