#include <stdio.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main(int agrc, char *argv[]){
	char c;
	int fd1 = open(argv[1], O_CREAT | O_RDWR, 0666);
	while(read(fd1,&c,1)>0){
	write(1,&c,1);
}
}
