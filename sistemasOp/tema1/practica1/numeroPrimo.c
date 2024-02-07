
#include <stdio.h>
#include <stdlib.h>

void main (int argc, char *argv[]) 
{
	int contador =0;
	int numero = atoi(argv[1]);
	for(int i =1; i<=numero;i++){
		if(numero%i==0)
			contador++;
	}
	if(contador ==2){
		printf("El numero es primo \n");
	}else{
		printf("El numero no es primo \n");
	}
	
}
