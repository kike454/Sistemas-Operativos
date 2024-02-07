#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

sem_t A, B, C, orden,orden1; //creamos semaforos 

void *fLinea1()//creamos una funcion por hilo, porque cada hilo realiza una accion diferente 
{
	sem_wait(&A);
		
	sem_wait(&B);
		printf("Pieza 1 producida \n");
	sem_post(&A);
	sem_post(&B);
	sem_post(&orden);//creamos este semaforo para controlar la frontera entre linea1 y linea2
}

void *fLinea2()
{
	sem_wait(&orden);
	sem_wait(&B);
		
	sem_wait(&C);
		printf("Pieza 2 producida \n");
	sem_post(&B);
	sem_post(&C);
	sem_post(&orden1);
}
void *fLinea3()
{
	sem_wait(&orden1);
	sem_wait(&C);
		
	sem_wait(&A);
		printf("Pieza 3 producida \n");
	sem_post(&C);
	sem_post(&A);
}

void main()
{
	sem_init(&A, 0, 1); //ponemos los semaforos arriba para que exxistan
	
	sem_init(&B, 0, 1);   

	sem_init(&C, 0, 1);
	sem_init(&orden, 0, 0);
	sem_init(&orden1, 0, 0);

	//creamos las 3 lineas de recursos
	pthread_t linea1,linea2,linea3;
	pthread_create(&linea1,NULL,*fLinea1,NULL);
	
	//pthread_t linea2;
	pthread_create(&linea2,NULL,*fLinea2,NULL);
	
	//pthread_t linea3;
	pthread_create(&linea3,NULL,*fLinea3,NULL);
	pthread_join(linea3,NULL);
	pthread_join(linea1,NULL);
	pthread_join(linea2,NULL);

	
	
}
