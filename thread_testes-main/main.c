
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
void *PrintHello1(void *threadid){ //função a ser executada quando uma thread for criada
  long id;
  id = (long)threadid;            //conversão de void pra long
  for (int i = 0; i < 100; i++) {
    printf("Thread %ld: Ola mundo!\n", id);
    usleep(300001 + ( rand() % 800000 ));
  }
  pthread_exit(NULL);             //finalização da thread
 
}

void *PrintHello2(void *threadid){ //função a ser executada quando uma thread for criada
  long id;
  id = (long)threadid;            //conversão de void pra long
  for (int i = 0; i < 100; i++) {
    printf("Thread %ld: Ola mundo!\n", id);
    usleep(300001 + ( rand() % 800000 ));
  }
  pthread_exit(NULL);             //finalização da thread
  
}


int main(){
  pthread_t t1, t2;               //criando t1 e t2 do tipo thread
  int create;                     //variável que recebe o retorno da função pthread_create()
  long num;                       //identificador da thread
  
  num = 1;
  printf("Main: criando a thread %ld\n", num);
  create = pthread_create(&t1, NULL, PrintHello1, (void *)num); //criando thread 1
 
  num = 2;
  printf("Main: criando a thread %ld\n", num);
  create = pthread_create(&t2, NULL, PrintHello2, (void *)num); //criando thread 2

  pthread_join(t2, NULL);
  pthread_join(t1, NULL);
 
  printf("Main: finalizando\n");
  return 0;
}