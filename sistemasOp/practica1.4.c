#include <stdio.h>
#include <stdlib.h>
void main(int argc, char *argv[])
{
 int contador =0;
int numero = atoi(argv[1]);//cast de char argv a int


for(int i = 1; i<=numero;i++){ //dividimos el numero introducido entre todos sus anteriores
	if(numero%i==0){//si el numero introducido es 3, en el bucle if se comprueba 3%1, 3%2, 3%3
		contador++;//se incrementa cuando el resto es 0, es decir, nos interesa contar las veces que el resto es 0.
 	}
}
if(contador==2){//si el numero es divisible entre si mismo y 1 
printf("El numero es primo \n");
}else{
printf("El numero no es primo \n");
}

}
