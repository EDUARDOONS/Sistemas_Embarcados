 #include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#define MAX 60


void* funcao1 (void* argumentos)
{
	int valor = * (int *) argumentos;
	int SOMA;
	SOMA = SOMA + valor;	
	printf("\n SOMA PARALELA e: %d\n ", valor);
	return NULL;
};

void* funcao2 (void* argumentos)
{
	int valor = * (int *) argumentos;
	int SOMA;
	SOMA = SOMA + valor;	
	printf("\n SOMA PARALELA e: %d\n ", valor);
	return NULL;
};

int main(){
	long int A[60][60];
	long int B[60][60];
	int SOMA = 0, SOMA_SEQUENCIAL = 0, i = 0, x = 0;
	
	//gerar valores aleatorios
	for(i = 1; i < MAX; i++)
     {		
     	for(x = 1; x < MAX; x++)
		 {
     		A[i][x]= rand()%100;
     		B[i][x]= rand()%100;
     		printf(" %d ", A[i][x]);
     		printf(" %d ", B[i][x]);
     		
		 }
	}
	
	pthread_t threads_1;

	for(i = 1; i < MAX; i++)
     {		
     	for(x = 1; x < MAX; x++)
		 {
		 	if ((i < MAX/2) && (x < MAX/2))
			 {
		 		SOMA =A[i][x]+B[i][x];
		 		pthread_create(&threads_1, NULL, funcao1, (void*)&SOMA);
		 		SOMA_SEQUENCIAL= SOMA_SEQUENCIAL+SOMA;
			 }
		 	else
		 		{SOMA = A[i][x]+B[i][x];
				 SOMA_SEQUENCIAL= SOMA_SEQUENCIAL+SOMA;}
			 
    
		 }
	}
	    
	printf("A SOMA SEQUENCIAL E  %d\n ", SOMA_SEQUENCIAL);
	
	return 0;
}
