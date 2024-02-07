#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<signal.h>
#include <stdlib.h>
int identificador;
char mensaje[] = "****He recibido una señal de mi proceso padre**** \n";
void Salir(int sig)
{
	switch(sig){
		case (SIGTERM):
			write(1,mensaje,strlen(mensaje));

	break;
	}	
}
void main()
{

	if(fork()==0){
		printf("Soy  el  proceso P1 con PID %d  y  mi  padre  cuyo PPID es %d   \n", getpid(),getppid());
	
	}else if(fork()==0){
		printf("Soy  el  proceso P2 con PID %d  y  mi  padre  cuyo PPID es %d  \n", getpid(),getppid());

	}else if(fork()==0){
		printf("Soy  el  proceso P3 con PID %d  y  mi  padre  cuyo PPID es %d \n", getpid(),getppid());
		identificador = fork();//hijo de P3, es decir, su nieto, P5
	
			if(identificador==0){
				printf("Soy  el  proceso P5 con PID %d  y  mi  padre  cuyo PPID es %d  \n", getpid(),getppid());
				signal(SIGTERM, Salir);
				
				sleep(3);
				
			}else{
					sleep(3);
					kill(identificador, SIGTERM);
					
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
