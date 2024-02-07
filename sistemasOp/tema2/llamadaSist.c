/*Realiza un programa que cree un fichero con la llamada al sistema open, escriba un mensaje en él con la llamada write y lea el contenido del fichero con la llamada read de forma que se muestre cada carácter de uno en uno con retardos de un segundo,Portanto,si se hace una escritura y  luego una lectura sobre el mismo descriptor de fichero,la lectura comenzará por donde se haya quedado el puntero al finalizar la escritura. Utiliza lafunción lseek para volver a posicionar el puntero en la posición inicial.*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int agrc, char *argv[])
{
	char mensaje[20]="keloke manin \n";
	char c;
	int fd;
	fd= open("archivo.txt", O_CREAT| O_RDWR, 0666);
	write(fd, mensaje, strlen(mensaje));
	lseek(fd,0,SEEK_SET);
	while(read(fd,&c,1)>0){
		printf("%c", c);
		fflush(stdout);
		sleep(1);

	}
	
}
