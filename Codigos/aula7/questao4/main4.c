#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main(){
	int pid, i=1;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	char pergunta[100];
	char resposta[100];

	
	// Cria o pipe
	pipe(fd);
	// Cria o processo
	pid = fork();
	// Codigo do filho
	if(pid == 0)
	{		//Perunda1
			printf("Qual seu nome usuario:\n");
			gets(pergunta);
			if (write(fd[1], pergunta, sizeof(pergunta)) < 0){
				printf("Erro na escrita do pipe\n");}
			sleep(1);
				
			
	}
	
	// Codigo do pai
	else
	{		//ouvi
			if(read(fd[0], resposta, sizeof(resposta)) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("Seu nome e: %s\n", resposta);}
			sleep(1);
				
	}
	
	return 0;
}
