#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#define MAX 50000

void* funcao (void* argumentos)
{
	int valor = * (int *) argumentos;
	int valor_anterior;
	int valor_atual;
	if (valor >= valor_anterior){
		valor_atual = valor;}
	else{
	
		valor_anterior = valor;
	}
	
	return NULL;
};
int main(){
	int NUM_THREADS = 4, x=0;;
	char valor_longo[10];
	long int v[50000];
	int i = 0, V_MAX = 0, valor_parte1[3], valor_parte2[3], valor_parte3[3], valor_parte4[3];
				
	pthread_t threads[1];
	pthread_t threads[2];
	pthread_t threads[3];
	pthread_t threads[4];
	
	for(i = 1; i < MAX; i++)
     {		//gerar valores aleatorios
     		v[i] = rand();
           printf(" %d ", v[i]);
        
           //valor maximo tradicional
		   if (v[i]>v[i-1]){
           	V_MAX = v[i];
			
		   }
		   
		   //dividir vetor
				sprintf(valor_longo, "%d", v[i]);

				valor_parte1[1]= valor_longo[12];
				valor_parte1[2]= valor_longo[11];
				valor_parte1[3]= valor_longo[10];
				
				valor_parte2[1]= valor_longo[9];
				valor_parte2[2]= valor_longo[8];
				valor_parte2[3]= valor_longo[7];
				
				valor_parte3[1]= valor_longo[6];
				valor_parte3[2]= valor_longo[5];
				valor_parte3[3]= valor_longo[4];
				
				valor_parte4[1]= valor_longo[3];
				valor_parte4[2]= valor_longo[2];
				valor_parte4[3]= valor_longo[1];
				
		
				
 				pthread_create(&threads[1], NULL, funcao, (void*)&valor_parte1);
 				pthread_create(&threads[2], NULL, funcao, (void*)&valor_parte2);
 				pthread_create(&threads[3], NULL, funcao, (void*)&valor_parte3);
 				pthread_create(&threads[4], NULL, funcao, (void*)&valor_parte4);
 			
	    
     }
     printf("\n O valor maximo e: %d ", V_MAX);  
 
	return 0;
}
