#include <stdio.h> 
#include <string.h> 
#include <sys/types.h>

void main(void)
{
	pid_t pid;
	for(int i=0;i<3;i++){
		pid=fork();
			
			if(pid==0){
			printf("Soy el hijo con PID %d PPID %d\n",getpid(),getppid());
			}else if(pid==0){
				printf("Soy el hermano con PID %d PPID %d\n",getpid(),getppid());
			}
			
			if(pid>0){break;}	
		
	}
		
		while(wait(NULL)>0){}
	printf("Proceso padre con PID %d, con PPID%d\n",getpid(),getppid());
	
	return 0;
}
