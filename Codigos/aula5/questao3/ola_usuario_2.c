//arquivo ola_usuario_2
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    int i=0, fp;
    char string[80];


	//criar o nome do arquivo
	sprintf(string, "%s.txt", argv[1]); //junta os nomes do arquivo
	
	
	//Abrir arquivo e cria-lo
	fp = open(string, O_WRONLY | O_CREAT, S_IRWXU);
	if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}
	
	//escrever no arquivo
	write(fp, argv[1], sizeof(argv[1]));
	write(fp, "\n", 2); // Grava a string, caractere a caractere	
	write(fp, argv[2], sizeof(argv[2]));
	    
return 0;   
} 
