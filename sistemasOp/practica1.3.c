#include <stdio.h>
#include <unistd.h>

void funcion(int *var)
{
*var = *var -1; //apunta al valor de var cuando lo introduces por pantalla con scanf
	printf(" El numero introducido menos 1 es igual a %d \n",*var);


}
void main()
{
int var;//variable local a la funcion main
	scanf("%d", &var); //&var, direccion de memoria asociada a la variable var, se utiliza para incializar el puntero *var, con *var nos referimos al contenido de la direccion de memoria 
while(var>=1){
	sleep(1);
	funcion(&var);
}
//for(int i =0; i=var;i++){
//sleep(1);
//funcion(&var);
//}

}

