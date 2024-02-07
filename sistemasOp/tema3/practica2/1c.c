#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<signal.h>
#include <stdlib.h>

void main()
{
int variable =0;

	if(fork()==0){
		variable++;
		printf("Soy  el  proceso P1 con PID %d  y  mi  padre  cuyo PPID es %d  y el valor de la variable es %d \n", getpid(),getppid(),variable);
	
	}else if(fork()==0){
		variable++;
		printf("Soy  el  proceso P2 con PID %d  y  mi  padre  cuyo PPID es %d y el valor de la variable es %d \n", getpid(),getppid(),variable);

	}else if(fork()==0){
		variable++;
		printf("Soy  el  proceso P3 con PID %d  y  mi  padre  cuyo PPID es %d  y el valor de la variable es %d \n", getpid(),getppid(),variable);
	
			if(fork()==0){
				printf("Soy  el  proceso P5 con PID %d  y  mi  padre  cuyo PPID es %d  \n", getpid(),getppid());
			}

	}else if(fork()==0){
		printf("Soy  el  proceso P4 con PID %d  y  mi  padre  cuyo PPID es %d \n", getpid(),getppid());
			execl("/bin/ls", "ls", (char*)0); //sobre el proceso copiado P4 ejecutamos la instruccion exec para que muestre todos los archivo del directorio

			if(fork()==0){
				printf("Soy  el  proceso P6 con PID %d  y  mi  padre  cuyo PPID es %d  \n", getpid(),getppid());
			}
	}else{
		printf("Soy  el  proceso PADRE con PID %d \n", getpid());
	}
	while(wait(NULL)>0){}
}
