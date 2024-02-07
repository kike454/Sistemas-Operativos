#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>


void main(void){

if (fork()==0){
	printf("Soy el proceso hijo1 con PID %d y con PPID %d\n" , getpid(), getppid()); 
        
   
}else if(fork()==0){
printf("Soy el proceso hijo2 con PID %d y con PPID %d\n" , getpid(), getppid()); 

 }
else if(fork()==0){
printf("Soy el proceso hijo3 con PID %d y con PPID %d\n" , getpid(), getppid()); 
}
else if(fork()==0){
printf("Soy el proceso hijo4 con PID %d y con PPID %d\n" , getpid(), getppid()); 

}
else if(fork()==0) {
    printf("Soy el proceso hijo5 con PID %d y con PPID %d\n", getpid(), getppid());
}
else if(fork()==0) {
    printf("Soy el proceso hijo6 con PID %d y con PPID %d\n", getpid(), getppid());
}
else if(fork()==0) {
    printf("Soy el proceso hijo7 con PID %d y con PPID %d\n", getpid(), getppid());
}
else if(fork()==0) {
    printf("Soy el proceso hijo8 con PID %d y con PPID %d\n", getpid(), getppid());
}
else {
printf("Soy el proceso padre con PID %d\n ", getpid()); 

}

 while(wait(NULL)>0){} // devuelve numero de procesos hijos que tiene actio, lo ejecutan padre e hijo

}

