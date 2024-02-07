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

int fd;
	if(fork()==0){
		printf("Soy  el  proceso P1 con PID %d  y  mi  padre  cuyo PPID es %d   \n", getpid(),getppid());
	
	}else if(fork()==0){
		fd = open("archivo.txt", O_CREAT | O_RDWR , 0666);
		printf("Soy  el  proceso P2 con PID %d  y  mi  padre  cuyo PPID es %d  \n", getpid(),getppid());

	}else if(fork()==0){
		printf("Soy  el  proceso P3 con PID %d  y  mi  padre  cuyo PPID es %d \n", getpid(),getppid());
	
			if(fork()==0){
				printf("Soy  el  proceso P5 con PID %d  y  mi  padre  cuyo PPID es %d  \n", getpid(),getppid());
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
