#include <stdio.h> 
#include <string.h> 
#include <sys/types.h>

void main(void)
{
	//pid_tpid;

 	if(fork()==0)
	{
		printf("Soy el hijo 1 con PPID %d y PPID %d\n", getpid(),getppid());
		
	}else{
	
	
	printf("Fin del proceso padre con PID %d\n",getpid());
	}
}
