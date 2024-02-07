#include <stdio.h>
#include <stdlib.h>
void main (int argc, char *argv[]) 
{
	//funcion multiplicacion pasandole por consola los numeros a multiplicar
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int resultado = a * b;
	printf(" El resultado es %d \n", resultado);
	
	
}
