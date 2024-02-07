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
	char mensaje[] = "examen Parcial";
	//char mensaje2[] = "Ordinario\n";
	
	char caracter;
	int fd;
	fd = open("fichero.txt", O_CREAT | O_RDWR,0666);
	write(fd,mensaje,strlen(mensaje));
	
	
	
	lseek(fd,0,SEEK_SET);
	while(read(fd,&caracter,1)>0){
	//sleep(1);
	//fflush(stdout);
		//printf("%c",caracter);	
	if(caracter=='a' || caracter=='e' || caracter=='i' || caracter=='o' || caracter=='u'){
		printf("%c\n", caracter);
	fflush(stdout);
	sleep(1);
		}
	}
}
