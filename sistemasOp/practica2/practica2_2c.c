#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<signal.h>
#include <stdlib.h>
#include <stdio.h>

/*
Cada proceso que se crea mediante la instruccion fork recibe un identificador de proceso (PID) y un identificador del proceso padre (PPID)
Al realizar la llamada fork el proceso hijo es una copia exacta del padre menos el PID, si no se produce un error en la ejecucion del proceso fork y nos encontramos en el proceso hijo, el fork devuelve 1.

*/
int sig;
char mensaje1[] = "***He recibido una señal de mi proceso padre*** \n";
int identificador;
void Salir (int sig)
{
	switch(sig)
{	
		case(SIGTERM):
			write(1,mensaje1,strlen(mensaje1));
			exit(EXIT_SUCCESS);	
	break;
	}
}

void main()
{
	if(fork()==0)
	{
		printf("Soy el proceso P1 con PID %d y mi padre cuyo PPID es %d \n", getpid(),getppid());

	}else if(fork()==0)
	{
		printf("Soy el proceso P2 con PID %d y mi padre cuyo PPID es %d \n ", getpid(),getppid());
	

	}else if(fork()==0)
	{
		printf("Soy el proceso P3 con PID %d y mi padre cuyo PPID es %d \n", getpid(),getppid());
		identificador=fork();
		
		
		
		if(identificador==0){
		printf("Soy el proceso P5 con PID %d y mi padre cuyo PPID es %d \n", getpid(),getppid());
		
		
		signal(SIGTERM, Salir);//tratamos la señal enviada del padre P3
		sleep(3);

		}else
		{
			sleep(3);
			kill(identificador, SIGTERM);//enviamos señal de P3 a P5	
			
		}
	

	}else if(fork()==0)
	{
		printf("Soy el proceso P4 con PID %d y mi padre cuyo PPID es %d \n", getpid(),getppid());
		if(fork()==0){
		printf("Soy el proceso P6 con PID %d y mi padre cuyo PPID es %d \n", getpid(),getppid());
		}

	}else{
		printf("Soy el proceso padre  con PID %d \n", getpid());

	}
	while(wait(NULL)>0){
	}
}
