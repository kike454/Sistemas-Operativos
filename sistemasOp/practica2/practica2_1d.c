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
		if(fork()==0){
		printf("Soy el proceso P5 con PID %d y mi padre cuyo PPID es %d \n", getpid(),getppid());
		}
	

	}else if(fork()==0)
	{
		printf("Soy el proceso P4 con PID %d y mi padre cuyo PPID es %d \n", getpid(),getppid());
		
			execl("/bin/ls", "ls", (char*)0); //sobre el proceso copiado P4 ejecutamos la instruccion exec para que muestre todos los archivo del directorio 	
		
		if(fork()==0){
		printf("Soy el proceso P6 con PID %d y mi padre cuyo PPID es %d \n", getpid(),getppid());
		}

	}else{
		printf("Soy el proceso padre  con PID %d \n", getpid());

	}
	while(wait(NULL)>0){
	}
}
