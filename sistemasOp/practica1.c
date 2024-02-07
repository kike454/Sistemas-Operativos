#include <stdio.h>
#include <stdlib.h>
void main(int argc,char *argv[])
{

int resultado = atoi(argv[1]) * atoi(argv[2]); //atoi castea el char a int, luego al ejecutar el programa tienes que introducir 2 parametros,es decir, los numeros a multiplicar. argv[0] es el nombre del ejecutable

printf(" %d \n",resultado); // %d,imprimir decimal
}
