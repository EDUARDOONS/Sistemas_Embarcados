#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main(){
	int pid, i=1;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	char pergunta1[100] = "Quando o vento passa, é a bandeira que se move.";
	char pergunta2[100] = "Não, é o vento que se move.";
	char resposta[100] = "Os dois se enganam. É a mente dos senhores que se move.";

	
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
			sleep(1);
				
			//Perunda2
			//printf("FILHO: %s\n", pergunta1);
			if (write(fd[1], pergunta2, sizeof(pergunta2)) < 0){
				printf("Erro na escrita do pipe\n");}
			sleep(1);
				
			//ouvi
			if(read(fd[0], resposta, sizeof(resposta)) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("PAI: %s\n", resposta);}
			sleep(1);
			
	}
	
	// Codigo do pai
	else
	{		//ouvi
			if(read(fd[0], pergunta1, sizeof(pergunta1)) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("FILHO1: %s\n", pergunta1);}
			sleep(1);
				
			
			//ouvi
			if(read(fd[0], pergunta2, sizeof(pergunta2)) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("FILHO2: %s\n", pergunta2);}
			sleep(1);
			
			//Responde
			//printf("PAI: %s\n", pergunta1);
			if (write(fd[1], resposta, sizeof(resposta)) < 0){
				printf("Erro na escrita do pipe\n");}	
			sleep(1);						
	}
	
	return 0;
}
