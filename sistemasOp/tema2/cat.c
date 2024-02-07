#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int argc, char *argv[])
{
	int fd;
	char c;
	if(argc < 1)
	{
		printf("Error, mete el archivo\n");
	}else{
		fd = open(argv[1], O_CREAT | O_RDWR, 0666);
		while(read(fd,&c,1)>0)
		{
		write(1,&c,1);

		}
	}
}
