//arquivo ola_usuario_2
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char string[80], nome[30], idade[4];
	int i=0, fp;
	
	printf("Qual seu nome\n");
	scanf("%s", nome);
	printf("Qual sua idade\n");
	scanf("%s", idade);

	//criar arquivo
	sprintf(string, "%s.txt", nome); 
	
	//Abrir arquivo e cria-lo
	fp = open(string, O_WRONLY | O_CREAT, S_IRWXU);
	if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}

	write(fp, nome, sizeof(nome));
	write(fp, "\n", 2); // Grava a string, caractere a caractere	
	write(fp, idade, sizeof(idade));
		
return 0;

}
