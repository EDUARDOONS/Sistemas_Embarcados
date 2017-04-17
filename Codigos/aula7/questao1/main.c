#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main(){
	int pid, i=1;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	char mensagem1[2] = "1";
	char mensagem2[2] = "2";
	char mensagem3[2] = "3";
	char mensagem4[2] = "4";
	char mensagem5[2] = "5";
	char mensagem6[2] = "6";
	char mensagem7[2] = "7";
	char mensagem8[2] = "8";
	char mensagem9[2] = "9";
	char mensagem10[2] = "10";
	
	
	// Cria o pipe
	pipe(fd);
	// Cria o processo
	pid = fork();
	// Codigo do pai
	if(pid != 0)
	{
	
			printf("PAI vai escrever no pipe %s\n", mensagem1);
			if (write(fd[1], mensagem1, 1) < 0){
				printf("Erro na escrita do pipe\n");}
			sleep(1);
			close(fd[0]);
			
			printf("PAI vai escrever no pipe %s\n", mensagem2);
			if (write(fd[1], mensagem2, 1) < 0){
				printf("Erro na escrita do pipe\n");}
			sleep(1);
			
			printf("PAI vai escrever no pipe %s\n", mensagem3);
			if (write(fd[1], mensagem3, 1) < 0){
				printf("Erro na escrita do pipe\n");}
			sleep(1);
			
			printf("PAI vai escrever no pipe %s\n", mensagem4);
			if (write(fd[1], mensagem4, 1) < 0){
				printf("Erro na escrita do pipe\n");}
			sleep(1);
			
			printf("PAI vai escrever no pipe %s\n", mensagem5);
			if (write(fd[1], mensagem5, 1) < 0){
				printf("Erro na escrita do pipe\n");}
			sleep(1);
			
			printf("PAI vai escrever no pipe %s\n", mensagem6);
			if (write(fd[1], mensagem6, 1) < 0){
				printf("Erro na escrita do pipe\n");}
			sleep(1);
			
			printf("PAI vai escrever no pipe %s\n", mensagem7);
			if (write(fd[1], mensagem7, 1) < 0){
				printf("Erro na escrita do pipe\n");}
			sleep(1);
			
			printf("PAI vai escrever no pipe %s\n", mensagem8);
			if (write(fd[1], mensagem8, 1) < 0){
				printf("Erro na escrita do pipe\n");}
			sleep(1);
			
			printf("PAI vai escrever no pipe %s\n", mensagem8);
			if (write(fd[1], mensagem8, 1) < 0){
				printf("Erro na escrita do pipe\n");}
			sleep(1);
			
			printf("PAI vai escrever no pipe %s\n", mensagem10);
			if (write(fd[1], mensagem10, 1) < 0){
				printf("Erro na escrita do pipe\n");}
			sleep(1);
			
				printf("encerrando\n");			
	}
	
	// Codigo do filho
	{
			if(read(fd[0], mensagem1, 1) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("Fiho leu: %s\n", mensagem1);}
			
			if(read(fd[0], mensagem2, 1) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("Fiho leu: %s\n", mensagem2);}
				
			if(read(fd[0], mensagem3, 1) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("Fiho leu: %s\n", mensagem3);}
				
			if(read(fd[0], mensagem4, 1) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("Fiho leu: %s\n", mensagem4);}
				
			if(read(fd[0], mensagem5, 1) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("Fiho leu: %s\n", mensagem5);}
				
			if(read(fd[0], mensagem6, 1) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("Fiho leu: %s\n", mensagem6);}
				
			if(read(fd[0], mensagem7, 1) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("Fiho leu: %s\n", mensagem7);}
				
			if(read(fd[0], mensagem8, 1) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("Fiho leu: %s\n", mensagem8);}
				
			if(read(fd[0], mensagem9, 1) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("Fiho leu: %s\n", mensagem9);}
				
			if(read(fd[0], mensagem10, 1) < 0){
				printf("Erro na leitura do pipe\n");}
			else{
				printf("Fiho leu: %s\n", mensagem10);}
					
	}
	
	return 0;
}
