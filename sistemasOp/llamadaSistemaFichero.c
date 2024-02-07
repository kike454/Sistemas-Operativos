#include <stdio.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	char mensaje[] = "Hola Mundo";
	char c;
		int fichero = open("fichero.txt", O_CREAT | O_RDWR, 0666);
		write(fichero,mensaje,strlen(mensaje));
		close(fichero);
		open("fichero.txt", 0666);

	while(read(fichero,&c,1)>0){;
	sleep(1); //retardo de un segundo
	printf("%c + \n",c);
}	

}
