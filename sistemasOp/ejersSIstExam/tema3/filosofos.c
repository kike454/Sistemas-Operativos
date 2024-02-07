#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

sem_t comer,palillo1,palillo2,palillo3,palillo4;

void *fil1()
{
	sem_wait(&comer);
	sem_wait(&palillo1);
	printf("Soy el Filosofo 1 y cojo el palillo izquierdo\n");
	sem_wait(&palillo2);
	printf("Soy el Filosofo 1 y cojo el palillo derecho\n");
	sem_post(&palillo2);
	sem_post(&palillo1);
	sem_post(&comer);
	printf("**Soy el Filosofo 1 y he terminado de comer**\n");
	
	
	
}
void *fil2()
{
	sem_wait(&comer);
	sem_wait(&palillo2);
	printf("Soy el Filosofo 2 y cojo el palillo izquierdo\n");
	sem_wait(&palillo3);
	printf("Soy el Filosofo 2 y cojo el palillo derecho\n");
	sem_post(&palillo3);
	sem_post(&palillo2);
	sem_post(&comer);
	printf("**Soy el Filosofo 2 y he terminado de comer**\n");
}
void *fil3()
{
	sem_wait(&comer);
	sem_wait(&palillo3);
	printf("Soy el Filosofo 3 y cojo el palillo izquierdo\n");
	sem_wait(&palillo4);
	printf("Soy el Filosofo 3 y cojo el palillo derecho\n");
	sem_post(&palillo4);
	sem_post(&palillo3);
	sem_post(&comer);
	printf("**Soy el Filosofo 3 y he terminado de comer**\n");
}
void *fil4()
{
	sem_wait(&comer);
	sem_wait(&palillo4);
	printf("Soy el Filosofo 4 y cojo el palillo izquierdo\n");
	sem_wait(&palillo1);
	printf("Soy el Filosofo 4 y cojo el palillo derecho\n");
	sem_post(&palillo1);
	sem_post(&palillo4);
	sem_post(&comer);
	printf("**Soy el Filosofo 4 y he terminado de comer**\n");
}

void main()
{
	sem_init(&comer,0,1);
	sem_init(&palillo1,0,1);
	sem_init(&palillo2,0,1);
	sem_init(&palillo3,0,1);
	sem_init(&palillo4,0,1);
	
	pthread_t filo1,filo2,filo3,filo4;
	pthread_create(&filo1,NULL,*fil1,NULL);
	pthread_create(&filo2,NULL,*fil2,NULL);
	pthread_create(&filo3,NULL,*fil3,NULL);
	pthread_create(&filo4,NULL,*fil4,NULL);

	pthread_join(filo1,NULL);
	pthread_join(filo2,NULL);
	pthread_join(filo3,NULL);
	pthread_join(filo4,NULL);
	

}
