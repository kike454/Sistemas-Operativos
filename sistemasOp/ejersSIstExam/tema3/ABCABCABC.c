#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

sem_t semA;
sem_t semB;
sem_t semC;

void *imprimirA()
{
	for(int i=0;i<3;i++)
	{
		sem_wait(&semC);
		
		printf("A\n");
		sem_post(&semA);
	}
}
void *imprimirB()
{
	for(int i=0;i<3;i++)
	{
		sem_wait(&semA);
		printf("B\n");
		sem_post(&semB);
	}
}
void *imprimirC()
{
	for(int i=0;i<3;i++)
	{
		sem_wait(&semB);
		printf("C\n");
		sem_post(&semC);
	}
}

int main()
{
	sem_init(&semA,0,0);
	sem_init(&semB,0,0);
	sem_init(&semC,0,1);

	pthread_t hiloA, hiloB, hiloC;
	pthread_create(&hiloA,NULL,*imprimirA,NULL);
	pthread_create(&hiloB,NULL,*imprimirB,NULL);
	pthread_create(&hiloC,NULL,*imprimirC,NULL);
	
	pthread_join(hiloA,NULL);
	pthread_join(hiloB,NULL);
	pthread_join(hiloC,NULL);
	
	
	
}
