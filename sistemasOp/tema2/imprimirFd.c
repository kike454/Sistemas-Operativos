#include<stdio.h>
#include<fcntl.h>

char name[]="archivo.txt";
int main(){

int fd;

fd=creat(name,0666);

printf("valor fd %d \n",fd);
return 0;
}
