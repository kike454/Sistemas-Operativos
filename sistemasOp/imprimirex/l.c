#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<signal.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int num;
		for(num=0;num<3;num++)
		{
			pid=fork();
			printf("Soy el proceso de PID %d y mi padre tiene %d de PID\n",getpid(),getppid());
			if(pid>0){break;}
		}
		while(wait(NULL)>0){}
		printf("Fin del proceso de PID %d\n",getpid());
		return 0;
}
