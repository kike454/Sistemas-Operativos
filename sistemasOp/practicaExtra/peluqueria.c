#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

sem_t max_capacidad,max_sofa,silla_barbero,peluquero,mutex,clienteEnSilla;

int contador1,contador2,contador3;

void funcionHilo(void* arg)
{
	int numero=*(int*)arg;
	sem_wait(&max_capacidad);//entran los clientes a la pekuqueria
	printf("Soy el cliente %d y he entrado en la peluqueria\n",numero);
	sem_wait(&mutex);
	contador1++;
	printf("Hay %d en la peluqueria\n",contador1);
	sem_post(&mutex);
	
	sem_wait(&max_sofa);//cliente del sofa a la peluqueria
	printf("Soy el cliente %d y me siento en el sofa\n",numero);
	
	sem_wait(&mutex);
	contador2++;
	printf("Hay %d y  sentados en el sofa\n",contador2);
	sem_post(&mutex);
	
	sem_post(&max_capacidad);

	sem_wait(&mutex);
	contador1--;
	sem_post(&mutex);

	

	sem_wait(&silla_barbero);//entra en la silla
	printf("Soy el cliente %d y  me he sentado en la silla del barbero\n",numero);
	sem_wait(&mutex);
	contador3++;
	printf("Hay %d cliente en la silla del barbero\n",contador3);
	sem_post(&mutex);
	
	sem_post(&max_sofa);
	sem_wait(&mutex);
	contador2--;
	
	sem_post(&mutex);
	
	

	sem_post(&peluquero);//despierta al peluquero

	sem_wait(&clienteEnSilla);

	sem_post(&silla_barbero);
	
	sem_wait(&mutex);
	contador3--;
	//printf("Hay %d cliente en la silla del barbero\n",contador3);
	sem_post(&mutex);
	
	
	
	
}

void funcionPeluquero()
{
	for(int i=0;i<50;i++){

	sem_wait(&peluquero);
	//printf("Soy el cliente %d y el pelquero me esta cortando el pelo\n",numero);
	sleep(3);
	sem_post(&clienteEnSilla);
	}
	
	
}

void main()
{

	sem_init(&max_capacidad,0,20);
	sem_init(&max_sofa,0,5);
	sem_init(&silla_barbero,0,1);
	sem_init(&peluquero,0,0);
	sem_init(&mutex,0,1);
	sem_init(&clienteEnSilla,0,0);

	pthread_t hilo[50];
	pthread_t pelu;
		pthread_create(&pelu,NULL,*funcionPeluquero,NULL);//creamos hilo peluqueria 
		
		for(int i=1; i<50;i++){
			pthread_create(&hilo[i],NULL, *funcionHilo, (void*)&i);
			sleep(1);
		}
		for(int i; i<50;i++){
			pthread_join(hilo[i],NULL);//espera a que lo hilos acaben,es decir, que 2 hilos no entren al mismo proceso
		}
		pthread_join(pelu,NULL);

}
