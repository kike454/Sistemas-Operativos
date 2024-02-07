#include <stdio.h> 
#include <string.h> 
#include <sys/types.h>

void main(void)
{

	//pid_t pid;

	//pid = fork();
	if(fork()==0)
	{
		printf("Soy el hijo 1 con PID %d y con PPID %d\n", getpid(),getppid());
	}
	else if(fork()==0){
		printf("Soy el hijo 2 con PID %d y con PPID %d\n", getpid(),getppid());
	}
	else if(fork()==0){
		printf("Soy el hijo 3 con PID %d y con PPID %d\n", getpid(),getppid());
	}
	else if(fork()==0){
		printf("Soy el hijo 4 con PID %d y con PPID %d\n", getpid(),getppid());
	}
	else if(fork()==0){
		printf("Soy el hijo 5 con PID %d y con PPID %d\n", getpid(),getppid());
	}
	else if(fork()==0){
		printf("Soy el hijo 6 con PID %d y con PPID %d\n", getpid(),getppid());
	}
	else if(fork()==0){
		printf("Soy el hijo 7 con PID %d y con PPID %d\n", getpid(),getppid());
	}
	else if(fork()==0){
		printf("Soy el hijo 8 con PID %d y con PPID %d\n", getpid(),getppid());
	}
	else{
		printf("Proceso padre %d\n",getpid());
	}
	while(wait(NULL)>0){}
}
