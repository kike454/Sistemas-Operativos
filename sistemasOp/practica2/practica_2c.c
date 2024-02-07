#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<signal.h>
#include <stdlib.h>
int fd;
int x;
char mensaje1[] = "***He recibido una señal de mi proceso padre \n";
char mensaje2[] =  "Soy P6 \n";
//2b,d

void Salir (int sig)
{
	

	switch(sig)
{
		
		case(SIGTERM):
			write(1,mensaje1,strlen(mensaje1));
			
	for(int i=0; i< strlen(mensaje2);i++){
			
			write(1,&mensaje2[i],1);
			sleep(1);
			}	
		exit(EXIT_SUCCESS);
	break;
	}
}

void main(void)
{

int pid;

int sig;
 	if((pid = fork())==0)
	{
		
		printf("Soy el proceso hijo1 con PID %d y  mi padre es PPID %d  y el valor de la variable es  \n" , getpid(),getppid());

	}else if(fork()==0)
	{
		
		fd=open("fichero.txt", O_CREAT | O_RDWR,0666);
		printf("Soy el proceso hijo2 con PID %d y mi padre es PPID %d y el valor de la variable es  \n" , getpid(),getppid());

	}else if(fork()==0)
	{	
		
		
		
		printf("Soy el proceso hijo3 con PID %d y mi padre es PPID %d y el valor de la variable es  \n" , getpid(),getppid());
		
		x=fork();//guardar el pid del hijo 
			 if(x==0){
			printf("Soy el proceso hijo 5 con PID %d y mi padre es %d \n", getpid(), getppid()); //creamos el hijo 5 cuyo padre es hijo3
			//kill(x, SIGINT);//envias señal del hijo al padre
			signal(SIGTERM, Salir);
			sleep(5);
	
			
		}else{
		sleep(5);
		kill(x,SIGTERM);//envias señal
		}

	}else if(fork()==0)
	{
		printf("Soy el proceso hijo4 con PID %d y mi padre es PPID %d \n" , getpid(),getppid());
		
		if(fork()==0)
		
			printf("Soy el proceso hijo 6 con PID %d y mi padre es %d \n", getpid(), getppid());
			
	}else if (fork()== 0){
		printf("Soy el proceso padre con PID %d \n", getpid());
	}
	while(wait(NULL)>0){}


}
