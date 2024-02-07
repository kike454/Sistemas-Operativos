#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
sem_t semA,semB,semC,sem1,sem2,sem3,mutex;
int variable=0;

void *func1()
{
		for(int i=1;i<=20;i++)
		{
			sem_wait(&sem1);
			sem_wait(&semA);
			sem_wait(&semB);
			//sem_wait(&mutex);
			variable++;
			//sem_post(&mutex);
			printf("PIEZA 1, numero de piezas introducidas en la linea 1 es %d\n",variable);
			sem_post(&semA);
			sem_post(&semB);
			sem_post(&sem2);
			
		}
}
void *func2()
{
	for(int i=1;i<=20;i++)
		{
			sem_wait(&sem2);
			sem_wait(&semB);
			sem_wait(&semC);
			//sem_wait(&mutex);
			variable++;
			//sem_post(&mutex);
			printf("PIEZA 2, numero de piezas introducidas en la linea 2 es %d\n",variable);
			sem_post(&semB);
			sem_post(&semC);
			sem_post(&sem3);
			
		}
}
void *func3()
{
	for(int i=1;i<=20;i++)
		{
			sem_wait(&sem3);
			sem_wait(&semC);
			sem_wait(&semA);
			//sem_wait(&mutex);
			variable++;
			//sem_post(&mutex);
			printf("PIEZA 3,numero de piezas introducidas en la linea 3 es %d\n",variable);
			sem_post(&semC);
			sem_post(&semA);
			sem_post(&sem1);
			
		}
}
void main()
{
	sem_init(&semA,0,1);//los semaforos a, b y c estan a la espera de que entre hilo, estos semaforos no tienen que estar bloqueados
	sem_init(&semB,0,1);
	sem_init(&semC,0,1);
	sem_init(&sem1,0,1);//las lineas del montaje al compartir recursos, necesitan un semaforo extra para pasar de una linea de montaje a otra, sin que las lineas que comparten el mismo recurso accedan concurrentemente al contenido del mismo.(evitar interbloqueo,acceso concurrente a la seccion critica(variable)), el primer semaforo a utilizar lo inicalizas a uno, para realizar su wait correspondiente.
	sem_init(&sem2,0,0);
	sem_init(&sem3,0,0);
	//sem_init(&mutex,0,1);

	pthread_t hiloA, hiloB, hiloC;
	pthread_create(&hiloA,NULL,*func1,NULL);
	pthread_create(&hiloB,NULL,*func2,NULL);
	pthread_create(&hiloC,NULL,*func3,NULL);
	
	pthread_join(hiloA,NULL);
	pthread_join(hiloB,NULL);
	pthread_join(hiloC,NULL);
}
