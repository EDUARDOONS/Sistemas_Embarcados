#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main(){
	int pid, i=1;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	char pergunta1[100] = "Pai, qual e a verdadeira essencia da sabedoria?";
	char resposta1[100] = "Não facais nada violento, praticai somente aquilo que e justo e equilibrado";
	char pergunta2[100] = "Mas ate um crianca de tres anos sabe disso";
	char resposta2[100] = "Sim, mas e uma coisa dificil de ser praticada até mesmo por um velho como eu";

	
	// Cria o pipe
	pipe(fd);
	// Cria o processo
	pid = fork();
	// Codigo do filho
	if(pid == 0)
	{		//Perunda1
			//printf("FILHO: %s\n", pergunta1);
			if (write(fd[1], pergunta1, sizeof(pergunta1)) < 0){
				printf("Erro na escrita do pipe\n");}
			
			//ouvi
			if(read(fd[0], resposta1, sizeof(resposta1)) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("PAI: %s\n", resposta1);}
			sleep(1);
			
			//Perunda2
			//printf("FILHO: %s\n", pergunta1);
			if (write(fd[1], pergunta2, sizeof(pergunta2)) < 0){
				printf("Erro na escrita do pipe\n");}
				
			//ouvi
			if(read(fd[0], resposta2, sizeof(resposta2)) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("PAI: %s\n", resposta2);}
			sleep(1);
			
	}
	
	// Codigo do pai
	else
	{		//ouvi
			if(read(fd[0], pergunta1, sizeof(pergunta1)) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("FILHO: %s\n", pergunta1);}
			sleep(1);
			
			//Responde1
			//printf("PAI: %s\n", pergunta1);
			if (write(fd[1], resposta1, sizeof(resposta1)) < 0){
				printf("Erro na escrita do pipe\n");}		
			
			//ouvi
			if(read(fd[0], pergunta2, sizeof(resposta2)) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("FILHO: %s\n", pergunta2);}
			sleep(1);
			
			//Responde2
			//printf("PAI: %s\n", pergunta1);
			if (write(fd[1], resposta2, sizeof(resposta2)) < 0){
				printf("Erro na escrita do pipe\n");}	
									
	}
	
	return 0;
}
