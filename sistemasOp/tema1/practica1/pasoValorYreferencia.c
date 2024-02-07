#include <stdio.h>
#include <unistd.h>
void funcionRestar(int *var)
{
	*var = *var - 1;
		printf(" numero introducido -1 %d \n", *var);
}

void main(int argc, char *argv[]){

	int var;
	scanf("%d", &var);
	
	while(var > 0)
	{
		sleep(1);
		funcionRestar(&var);	
		
	}
	

}

