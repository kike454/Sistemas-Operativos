#include <stdio.h>
#include <stdlib.h>
void main(int argc,char *argv[])
{
/**	if(argc<2){

		printf("Errorn \n");
		exit(0);

}else{

if(!strcmp(argv[1], "Azul"))
	printf("Acceso \n");
else{

	printf("Acceso denegado \n");
	exit(0);
}**/

if (argc<2){
printf ("Error, falta clave de acceso\n");
exit(0);
}
else{
if (!strcmp(argv[1],"Azul") )
printf("Acceso al programa...\n");
}
else
{
printf ("Acceso denegado\n");
exit(0);
}
}
