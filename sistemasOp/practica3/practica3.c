#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
sem_t max_capacidad, sofa,silla_barbero, mutex, peluquero,clienteEnSilla;//creamos semaforos 

int contador1=0;
int contador=0;
int contador2=0;
int contador3=0;

void *funcionHilo(void* arg){
	int numero=*(int*)arg;
		sem_wait(&max_capacidad);//resta cada hilo que entra
			printf("Soy el cliente %d y he entrado en el establecimiento\n", numero);
			sem_wait(&mutex);
			contador++;//seccion critica
			sem_post(&mutex);
			
			printf("Hay %d de personas en la peluqueria\n",contador);
		sem_wait(&sofa);
			printf("Soy el cliente %d , y me voy a sentar en el sofa \n", numero);
			sem_wait(&mutex);
			contador2++;
			sem_post(&mutex);
			printf("Hay %d personas sentadas en el sofa\n" , contador2);
			
		sem_wait(&silla_barbero);
			printf("Soy el cliente %d , me voy a sentar en la silla del barbero \n", numero);
			sem_wait(&mutex);
			contador3++;
			sem_post(&mutex);
			printf("Hay %d personas sentadas en la silla del barbebro\n" , contador3);
	
		
		sem_post(&peluquero);//primero tiene que llamr al peluquero y luego se sienta
			printf("Soy el cliente %d, y llamo al peluquero \n", numero);

		sem_post(&sofa);
			printf("Soy el cliente %d, y me levanto del sofa \n", numero);//aqui se jecuta simulatnemanete un hilo	
			sem_wait(&mutex);
			contador2--;
			sem_post(&mutex);

		sem_wait(&clienteEnSilla);
			printf("Soy el cliente %d, y el peluquero me ha cortado el pelo \n", numero);
			sleep(2);
		sem_post(&silla_barbero);
			printf("Soy el cliente %d, y voy de la silla a la salida \n",numero);
			sem_wait(&mutex);
			contador3--;
			sem_post(&mutex);
		sem_post(&max_capacidad);
			printf("Soy el cliente %d, y he salido de la tienda \n ",numero);
			sem_wait(&mutex);
			contador--;
			sem_post(&mutex);
			//printf("Soy el cliente %d, y he salido de la tienda,  \n ",numero);
		
		
		
		//printf("Soy el hilo %d\n", numero);
		//printf("Acabo de entrar en la peluqueria %d,")
	pthread_exit(NULL);
}
void *funcionPeluquero(void* arg){
	for(int i=0; i<50;i++){
		sem_wait(&peluquero);
		
		sem_post(&clienteEnSilla);
		sleep(5);//tiempo que tarda el peluquero en cortar el pelo
			
		
	}
}
	
int main(int argc,char*argv[]){
	sem_init(&max_capacidad, 0, 20); //inicializamos el semaforo a 20 , el aforo total de la peluqueria 
	
	sem_init(&sofa, 0, 5); //inicializamos el semaforo a 5 , personas(hilos) que se pueden sentar  

	sem_init(&silla_barbero, 0, 1); //inicializamos el semaforo a 1 , solo puede sentarse una persona en la silla del peluquero para cortarse el pelo 
	sleep(3);//tiempo que tarda en cortarse el pelo
	
	sem_init(&mutex, 0, 1);//impide que 2 hilos ejecuten la msima variable 
	sem_init(&peluquero, 0, 0); //inicializamos a 0 el semaforo, solo hay un peluquero, si no hay nadie en la peluqueria, este hilo tiene que estar bloqueado, si hay gente cortandose el pelo, tiene que estar activo
	sem_init(&clienteEnSilla, 0, 0);//una vez  que el cliente a alcanzado la silla, se bloquee
	
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
	//return 0;
}












































































































