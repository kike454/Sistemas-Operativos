#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int argc, char *argv[])
{
	int fd;
	int fd2;
	char c;
	
	fd = open(argv[1], O_CREAT | O_RDWR, 0666);
	fd2 = open(argv[2], O_CREAT | O_RDWR, 0666);
	while(read(fd, &c,1)>0)
	{
		write(fd2,&c,1);
	}
}
