#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<wait.h>

int main(int argc, char*argv[])
{
int rt;


	printf("Soy el padre y mi pid es %d y mi ppid %d \n", getpid(),getppid());
	rt=fork();
	if(rt==0){
		
		printf("Soy el hijo y mi pid es %d y mi ppid %d  \n", getpid(),getppid());
		
	
	
		int rt2 = fork();
		if(rt2==0){
		printf("Soy el nieto y mi pid es %d y mi ppid %d \n", getpid(),getppid());
		execl("/bin/ps","  ps",(char*)0);
		
		}else
			
			execl("/bin/ls","ls",(char*)0);
	}
	while(wait(NULL)>0);
	}
