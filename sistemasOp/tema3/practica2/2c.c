#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<signal.h>
#include <stdlib.h>

char mensaje[100] = "*****Soy el proceso P3 y he recibido una señal del proceso P5***** \n";
void Salir(int sig)
{
	switch(sig)
		case(SIGTERM):
			write(1,mensaje, strlen(mensaje));
			
}
void main()
{

	if(fork()==0){
		printf("Soy  el  proceso P1 con PID %d  y  mi  padre  cuyo PPID es %d   \n", getpid(),getppid());
	
	}else if(fork()==0){
		printf("Soy  el  proceso P2 con PID %d  y  mi  padre  cuyo PPID es %d  \n", getpid(),getppid());

	}else if(fork()==0){
		printf("Soy  el  proceso P3 con PID %d  y  mi  padre  cuyo PPID es %d \n", getpid(),getppid());
				signal(SIGTERM, Salir);//TRATAMOS LA SEÑAL ENVIADA POR P5
			if(fork()==0){
				printf("Soy  el  proceso P5 con PID %d  y  mi  padre  cuyo PPID es %d  \n", getpid(),getppid());
				kill(getppid(),SIGTERM);//enviamos señal de apgado a P3
			}

	}else if(fork()==0){
		printf("Soy  el  proceso P4 con PID %d  y  mi  padre  cuyo PPID es %d \n", getpid(),getppid());

			if(fork()==0){
				printf("Soy  el  proceso P6 con PID %d  y  mi  padre  cuyo PPID es %d  \n", getpid(),getppid());
			}
	}else{
		printf("Soy  el  proceso PADRE con PID %d \n", getpid());
	}
	while(wait(NULL)>0){}
}
