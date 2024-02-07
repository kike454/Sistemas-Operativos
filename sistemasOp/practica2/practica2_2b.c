#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<signal.h>
#include <stdlib.h>

/*
Cada proceso que se crea mediante la instruccion fork recibe un identificador de proceso (PID) y un identificador del proceso padre (PPID)
Al realizar la llamada fork el proceso hijo es una copia exacta del padre menos el PID, si no se produce un error en la ejecucion del proceso fork y nos encontramos en el proceso hijo, el fork devuelve 1.

*/
char mensaje[] = "*** Soy el proceso P3 y he recibido una señal del proceso P5 ***  \n";
int sig;

void Salir (int sig)
{
	

	switch(sig)
{
		
		case(SIGTERM):
			write(1,mensaje,strlen(mensaje));
			
	
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
		signal(SIGTERM, Salir);//tratamos la señal enviada por P5
		if(fork()==0){
		printf("Soy el proceso P5 con PID %d y mi padre cuyo PPID es %d \n", getpid(),getppid());
		kill(getppid(),SIGTERM);//enviamos una señal de apagado a P3
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
	while(wait(NULL)>0){//espera a que acaben todos los procesos hijos, para que no se muera ninguno
	}
}
