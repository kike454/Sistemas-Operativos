#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//implementacion comando cat 
void main(int argc, char *argv[])
{
	if(argc < 1){
		printf("Error, falta el nombre del archivo \n");
	}
	else{
		int fd;//file descriptor del fichero
		char c;
		fd = open(argv[1],O_CREAT | O_RDWR,0666);
		while(read(fd,&c,1)>0){// >0 ,siempre que hay un caracter lo lee, cuanod no hya acaba
			write(1,&c,1);	
		}
		//write(1, "\n",1);

	}
		
}

