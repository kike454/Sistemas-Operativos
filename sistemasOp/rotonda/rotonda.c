#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>

sem_t capacidad_rotonda,mutex;
int contador =0;
//int idcoche=0;
//int idmoto=0;
bool hayMoto=false;

void *coche(void* arg)
{
	
		
	int idcoche = *(int*)arg;
	sem_wait(&capacidad_rotonda);//entra un vehiculo en la rotonda
		
	while(hayMoto==true){
		sleep(1);
	}
	
	
	//while(hayMoto==false);
	sem_wait(&mutex);
	contador++;//cuentas el primer coche 
	sem_post(&mutex);
	printf("Soy un coche %d y hay %d vehiculos en la rontoda\n", idcoche,contador);
	//idcoche++;
	//sem_post(&coches);
	
	sleep(4);
	sem_post(&capacidad_rotonda);
	sem_wait(&mutex);
	contador--;//cuentas el primer coche 
	sem_post(&mutex);
	printf("Soy un coche %d  y he salido de la rotonda y hay %d vehiculos en la rontoda\n",idcoche, contador);
	//idcoche++;
	
}

void *moto(void* arg)
{
	int idmoto = *(int*)arg;
	sem_wait(&capacidad_rotonda);//entra un vehiculo en la rotonda
	
	hayMoto=true;
	sem_wait(&mutex);
	contador++;//cuentas la primera moto
	sem_post(&mutex);
	
	printf("Soy una moto %d y hay %d vehiculos en la rontoda\n",idmoto, contador);
	//idmoto++;
	sleep(1);//timepo que esta en la rotonda
	hayMoto=false;
	sem_post(&capacidad_rotonda);
	sem_wait(&mutex);
	contador--;//cuentas el primer coche 
	sem_post(&mutex);
	printf("Soy una moto %d y he salido de la rotonda y hay %d vehiculos en la rontoda\n",idmoto, contador);
	//idmoto++;
		
	
}

void main()
{
	sem_init(&capacidad_rotonda, 0, 5); //inicializamos el semaforo a 5 , capacidad rotonda 
	
	
	
	sem_init(&mutex, 0, 1);//impide que 2 hilos ejecuten la msima variable 
	
	
	pthread_t coches[20];
	pthread_t motos[20];
	
	//int j=0;
	//int k=0;
		
		for(int i=1; i<20;i++){
			pthread_create(&coches[i],NULL, *coche, (void*)&i);
			
			//sleep(1);
	
			pthread_create(&motos[i],NULL, *moto, (void*)&i);
			
			sleep(1);
		}
		
		for(int i=1; i<20;i++){
			pthread_join(coches[i],NULL);//espera a que lo hilos acaben,es decir, que 2 hilos no entren al mismo proceso
			pthread_join(motos[i],NULL);
		}
		
		
}
		
		
