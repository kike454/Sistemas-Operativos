#include <stdio.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void main(int agrc, char *argv[]){
	char c;
	int fd1 = open(argv[1], O_CREAT | O_RDWR, 0666);//origen
	int fd2 = open(argv[2], O_CREAT | O_RDWR, 0666);//destino
	while(read(fd1,&c,1)>0){
	write(fd2,&c,1);//escribir en el destino

}
}
