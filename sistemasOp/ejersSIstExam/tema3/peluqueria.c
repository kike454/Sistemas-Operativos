#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>

sem_t max_capacidad,max_sofa,max_silla,mutex,peluquero,clienteEnSilla


void main(){

	
sem_init(&max_capacidad,0,20);
sem_init(&max_sofa,0,5);
sem_init(&max_silla,0,1);
sem_init(&max_mutex,0,1);//proteger seccion critica
sem_init(&max_peluquero,0,0);//bloqueado, que no cote el pelo al aire
sem_init(&clienteEnSilla,0,0);//se ha termiando de cortar el pelo,se libere el semaforo de la silla 
	

}
