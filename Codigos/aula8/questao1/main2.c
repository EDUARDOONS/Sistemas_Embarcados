#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* funcao (void* argumentos)
{
	int valor = * (int *) argumentos;
 	printf("recebi um inteiro: %d \n", valor );
	sleep(1);
	return NULL;
};

int main ()
{	
	int NUM_THREADS = 10, i=0, x=1;;
	pthread_t threads[NUM_THREADS];

 	for(i=1;i<=NUM_THREADS;i++){
 	pthread_create(&threads[i], NULL, funcao, (void*)&i);
	sleep(1);
 	}
 	
 	pthread_join (threads[10], NULL);
	pthread_exit(& i);
	
	return 0;
}


//I.Passagem dum inteiro
//int x=5;
//pthread_create(&threads[i], NULL, funcao, (void*)&x);
//void * funcao ( void * argumentos ){
// int valor = * (int *) argumentos;
// printf("recebi um inteiro: %d \n", valor );
//}

//II.Passagem duma String
//char mesg[ ]=”Ola”;
//pthread_create(&threads[i], NULL, funcao, (void*)mesg);
//void * funcao ( void * argumentos ){
// char *message = (char *) argumentos ;
// printf(" %s ", message );
//}

//III.Passagem de múltiplos parâmetros usando uma estrutura
//tyypedef struct { int a; float b; } ST;
//ST v;
//v.a = 5; v.b = 2.5;
//pthread_create(&threads[i], NULL, funcao, (void*)&v);
//void * funcao ( void * argumentos ){
// ST * in = (ST *) argumentos ;
// printf("recebi dois valores: %d %f ", in->a, in->b );
//}


//void *funcao(void *args)
//{
// int id = *(int *)args;
// printf("Thread %d\n", id);
// return (NULL);
//}
//int main ()
//{
// pthread_t threads[NUM_THREADS];
// int i, ids[NUM_THREADS];
// for (i = 0; i < NUM_THREADS; i++) ids[i]=i;
//
// for(i=0;i < NUM_THREADS;i++)
// pthread_create(&threads[i], NULL, funcao, &ids[i]);
// for(i=0;i < NUM_THREADS;i++)
// pthread_join(threads[i],NULL);
// return 0 ;
//}



