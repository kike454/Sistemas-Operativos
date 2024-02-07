#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
	pid_t pid;
 printf ("Ejemplo de fork.\n");
 printf ("Inicio del proceso padre. PID=%d\n", getpid ());
 pid=fork();
 if (pid == 0)
 { 
 printf ("Proceso hijo. PID=%d, PPID=%d\n", getpid (),getppid ());
 sleep (1);
 }
 else
 { 
 printf ("Proceso padre. PID=%d\n", getpid ());
 sleep (1);
 }
 printf ("Fin del proceso %d\n", getpid ());
 exit (0);

	
	
}
